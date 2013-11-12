#ifndef ___BH_General
#define ___BH_General

#include <string>

class SocketPackage;

const std::string&
assign( const char*, std::string& );

const std::string&
getWorkingDirectory( std::string& );

const std::string&
createFilename( SocketPackage&, std::string&, bool bWriteBackup=false );

bool
isExistingFile( const std::string& );

#endif
