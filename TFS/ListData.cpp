//#include "stdafx.h"

#include "ListData.h"

#include "SocketPackage.h"

#include "General.h"

#include <windows.h>

#define szExtension "*.dat"

ListData    ListData::m_cStaticObject( "list" );

ListData::ListData()
    : TFSAction()
{
}

ListData::ListData( const char* szID )
    : TFSAction( szID )
{
}

ListData::~ListData()
{
}

bool
ListData::preprocess( SocketPackage& cPackageIn )
{
    return true;
}


bool
ListData::process( SocketPackage& cPackageIn
                 , SocketPackage& cPackageOut )
{
    std::string             sBuffer,
                            sStartsWith;
    std::set<std::string>   saFilenameSet;
    std::string             sModulename;

    cPackageIn.resetCounter();
    cPackageIn.getString( sBuffer );    // action name

    sStartsWith = cPackageIn.getString( sBuffer );

    fillFilenameSet( getWorkingDirectory(sModulename)+sStartsWith+szExtension, saFilenameSet );
    fillPackage( saFilenameSet, cPackageOut );

    return true;
}


bool
ListData::postprocess( SocketPackage& cPackageIn )
{
    return true;
}

void
ListData::fillFilenameSet( const std::string& sFilename, StringSet& saFilenameSet )
{
    HANDLE                  hFindFile;
    WIN32_FIND_DATAA        cFindFileData;

    hFindFile   = ::FindFirstFileA( sFilename.c_str(), &cFindFileData );

    if ( hFindFile != INVALID_HANDLE_VALUE )
    {
        do
        {
            if ( !(cFindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
                saFilenameSet.insert( cFindFileData.cFileName );
        }
        while ( ::FindNextFileA(hFindFile, &cFindFileData) != 0 );
    }

    ::FindClose( hFindFile );
}

void
ListData::fillPackage( const StringSet& saFilenameSet, SocketPackage& cPackageOut )
{
    StringSet::const_iterator   iSet;

    cPackageOut.resetCounter();

    cPackageOut.add( int(saFilenameSet.size()) );
    for ( iSet=saFilenameSet.begin(); iSet!=saFilenameSet.end(); ++iSet )
        cPackageOut.add( *iSet );

    cPackageOut.done();
}

TFSAction*
ListData::create() const
{
    return new ListData;
}
