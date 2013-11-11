#include "WriteData.h"

#include "SocketPackage.h"

#include "TFSBasis.h"
#include "TFSBasisFactory.h"
#include "TFSBasisCreator.h"

#include "StatusType.h"
#include "User.h"

#include "general.h"

#include <fstream>
#include <stdio.h>
#include <windows.h>

WriteData    WriteData::m_cStaticObject( "write" );

WriteData::WriteData()
    : TFSAction()
{
}

WriteData::WriteData( const char* szID )
    : TFSAction( szID )
{
}

WriteData::~WriteData()
{
}

bool
WriteData::preprocess( SocketPackage& cPackageIn )
{
    std::string sBuffer;

    cPackageIn.resetCounter();
    cPackageIn.getString( sBuffer );    // action name

    std::string sClassID    = cPackageIn.getString( sBuffer ),
                sName       = cPackageIn.getString( sBuffer );
    TFSBasis   *pTemp       = TFSBasisFactory::get(sClassID.c_str())->create(),
               *pItem       = pTemp == NULL ? NULL : pTemp->get( sName );

    delete pTemp;

    writeEveryObject<StatusType>( cPackageIn );
    writeEveryObject<User>      ( cPackageIn );

    TFSBasis::serialize( pItem, cPackageIn, true );
    
    cPackageIn.done();

    return pItem != NULL;
}

bool
WriteData::process( SocketPackage& cPackageIn
                  , SocketPackage& cPackageOut )
{
    std::string         sFilename;
    bool                bCanWrite   = false;

    createFilename( cPackageIn, false, sFilename );
    copyFile( cPackageIn, sFilename );
    bCanWrite   = writeData( cPackageIn, sFilename );

    cPackageOut.resetCounter();
    cPackageOut.add( sFilename + ( bCanWrite ? " written" : " not written") );
    cPackageOut.done();

    return bCanWrite;
}

bool
WriteData::postprocess( SocketPackage& )
{
    return true;
}

TFSAction*
WriteData::create() const
{
    return new WriteData;
}

void
WriteData::createFilename( SocketPackage& cPackageIn, bool bIsBackup, std::string& sFilename )
{
    std::string sBuffer;

    cPackageIn.resetCounter();
    cPackageIn.getString( sBuffer );                        // action name
    ::createFilename( cPackageIn, sFilename, bIsBackup );   // read two strings
}

void
WriteData::copyFile( SocketPackage& cPackageIn, const std::string& sFilename )
{
    if ( isExistingFile(sFilename) )
    {
        std::string sFilecopy;

        createFilename( cPackageIn, true, sFilecopy );
        ::CopyFileA( sFilename.c_str(), sFilecopy.c_str(), FALSE );
    }
}

bool
WriteData::writeData( SocketPackage& cPackageIn, const std::string& sFilename )
{
    unsigned            nOffset,
                        nSize   = cPackageIn.getStoredCount();
    std::ofstream       cFile;
    bool                bCanWrite;
    const char*         szData  = cPackageIn.getData();

    nOffset     = cPackageIn.getCount();

    cFile.open( sFilename.c_str(), std::ios::out|std::ios::binary );
    bCanWrite   = cFile.is_open();
    if ( bCanWrite )
    {
        nSize  -= nOffset;
        cFile.write( szData+nOffset, nSize );
        cFile.close();
    }

    return bCanWrite;
}
