//#include "stdafx.h"

#include "TFSTransaction.h"

#include "SocketPackage.h"
#include "TFSActionFactory.h"

#include "Project.h"

#define REMOTE_WRITE    "remote write"
#define LOCAL_WRITE     "write"
#define REMOTE_READ     "remote read"
#define LOCAL_READ      "read"
#define REMOTE_LIST     "remote list"
#define LOCAL_LIST      "list"

void
TFSTransaction::remoteWriteProject( const char* szName )
{
    projectAction( szName, REMOTE_WRITE );
}

void
TFSTransaction::localWriteProject( const char* szName )
{
    projectAction( szName, LOCAL_WRITE );
}

Project*
TFSTransaction::remoteReadProject( const char* szName )
{
    if (Project::getStorage().isPresent(szName) )
        delete Project::getStorage().get( szName );

    projectAction( szName, REMOTE_READ );

    if ( Project::isPresent(szName) )
        return Project::withName( szName );
    else
        return NULL;
}

Project*
TFSTransaction::localReadProject( const char* szName )
{
    if (Project::getStorage().isPresent(szName) )
        delete Project::getStorage().get( szName );

    projectAction( szName, LOCAL_READ );

    if ( Project::isPresent(szName) )
        return Project::withName( szName );
    else
        return NULL;
}

void
TFSTransaction::remoteListProjects(ProjectList& saProjectList )
{
    listProjects( REMOTE_LIST, saProjectList );
}

void
TFSTransaction::localListProjects(ProjectList& saProjectList )
{
    listProjects( LOCAL_LIST, saProjectList );
}

void
TFSTransaction::removeAllData()
{
    TFSBasis::removeAll();
}

#ifndef TFS_SERVER
#include "SocketClient.h"
#endif

void
TFSTransaction::setRemoteAddress( const char* szAddress
                                , unsigned    nPort )
{
#ifndef TFS_SERVER
    SocketClient::setAddress( szAddress, nPort );
#endif
}

void
TFSTransaction::listProjects( const char* szAction, ProjectList& saProjectList )
{
    SocketPackage   cPackageIn,
                    cPackageOut;
    std::string     sClassID    = Project::ClassID(),
                    sFilename;
    int             n, max,
                    begin       = int( sClassID.size()+1 );
    size_t          position;

    cPackageIn.add( szAction );
    cPackageIn.add( Project::ClassID() );

    TFSActionFactory::process( szAction
                             , cPackageIn
                             , cPackageOut );

    saProjectList.clear();

    cPackageOut.resetCounter();
    max = cPackageOut.getInt();
    for ( n=0; n<max; n++ )
    {
        cPackageOut.getString( sFilename );
        position    = sFilename.rfind( '.' );

        saProjectList.push_back( sFilename.substr(begin,position-begin) ); 
    }
}

void
TFSTransaction::projectAction( const char* szName, const char* szAction )
{
    SocketPackage   cPackageIn,
                    cPackageOut;

    cPackageIn.add( szAction );
    cPackageIn.add( Project::ClassID() );
    cPackageIn.add( szName );

    TFSActionFactory::process( szAction
                             , cPackageIn
                             , cPackageOut );
}
