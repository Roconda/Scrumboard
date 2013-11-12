//#include "stdafx.h"

#include "ReadData.h"

#include "SocketPackage.h"
#include "general.h"
#include "TFSBasis.h"

#include "StatusType.h"
#include "User.h"

#include <fstream>
#include <sys/stat.h>

ReadData    ReadData::m_cStaticObject( "read" );

ReadData::ReadData()
    : TFSAction()
{
}

ReadData::ReadData( const char* szID )
    : TFSAction( szID )
{
}

ReadData::~ReadData()
{
}

bool
ReadData::preprocess( SocketPackage& cPackageIn )
{
    cPackageIn.done();

    return true;
}

bool
ReadData::process( SocketPackage& cPackageIn
                 , SocketPackage& cPackageOut )
{
    std::string     sBuffer,
                    sFilename;
    bool            bCanRead    = false;
    std::ifstream   cFile;

    cPackageIn.resetCounter();

    cPackageIn.getString( sBuffer );                // action name
    createFilename( cPackageIn, sFilename, false ); // read two strings

    cFile.open( sFilename.c_str(), std::ios::in|std::ios::binary );
    bCanRead    = cFile.is_open();
    if ( bCanRead )
    {
        struct _stat        nStatus;
        int                 nSize;
        std::vector<char>   caBuffer;

        ::_stat( sFilename.c_str(), &nStatus ); 
        
        nSize   = nStatus.st_size;
        caBuffer.resize( nSize );

        cFile.read( &caBuffer[0], nSize );
        cFile.close();

        cPackageOut.resetCounter();
        cPackageOut.add( &caBuffer[0], nSize );
        cPackageOut.done();
    }
    else
        cPackageOut.resetCounter();

    return bCanRead;
}

bool
ReadData::postprocess( SocketPackage& cPackageOut )
{
    TFSBasis   *pObject = NULL;

    cPackageOut.resetCounter();

    readEveryObject<StatusType>( cPackageOut );
    readEveryObject<User>      ( cPackageOut );

    TFSBasis::serialize( pObject, cPackageOut, false );

    return true;
}

TFSAction*
ReadData::create() const
{
    return new ReadData;
}
