//#include "stdafx.h"

#include "general.h"

#include "SocketPackage.h"

#include <windows.h>

#define szExtension         ".dat"
#define szExtensionBackup   ".bak"

const std::string&
assign( const char* szValue, std::string& sValue )
{
    return sValue  = ( szValue == NULL ? "" : szValue );
}

const std::string&
getWorkingDirectory( std::string& sDir )
{
#ifdef TFS_SERVER
    static const int    MAX_SIZE    = 255;
    char                szModulename[MAX_SIZE];

    ::GetModuleFileNameA( NULL, szModulename, MAX_SIZE );
    sDir    = szModulename;
    sDir    = sDir.substr(0, sDir.rfind('\\')+1 );
#else
    sDir    = "";
#endif

    return sDir;
}

const std::string&
createFilename( SocketPackage& cPackage, std::string& sFilename, bool bWriteBackup )
{
    std::string         sBuffer,
                        sClassID,
                        sName;

    sClassID    = cPackage.getString( sBuffer );
    sName       = cPackage.getString( sBuffer );

    sFilename   = sClassID + " " + sName + ( bWriteBackup ? szExtensionBackup : szExtension );
    sFilename   = getWorkingDirectory(sBuffer) + sFilename;

    return sFilename;
}

bool
isExistingFile( const std::string& sFilePath )
{
    DWORD dwAttribute = ::GetFileAttributesA( sFilePath.c_str() );

    return    dwAttribute                              != INVALID_FILE_ATTRIBUTES
        &&  ( dwAttribute & FILE_ATTRIBUTE_DIRECTORY ) == 0;
}
