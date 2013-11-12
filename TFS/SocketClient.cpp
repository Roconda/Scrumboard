//#include "stdafx.h"

#include "SocketClient.h"

#include "SocketPackage.h"
#include "PracticalSocket.h"

#include "SocketSettings.h"

#include "general.h"

std::string     SocketClient::m_sAddress   = TFS_ADDRESS;
unsigned        SocketClient::m_nPort      = TFS_PORT_NUMBER;

SocketClient    SocketClient::m_cStaticObject( "remote" );

SocketClient::SocketClient( const char* szID )
    : TFSActionDecorator( szID )
{
}

SocketClient::SocketClient( TFSAction* pDecorated )
    : TFSActionDecorator( pDecorated )
{
}

bool
SocketClient::process( SocketPackage& cPackageIn
                     , SocketPackage& cPackageOut )
{
    TCPSocket   socket( m_sAddress.c_str(), m_nPort );

    socket.send( cPackageIn.getData(), cPackageIn.getCount() );

    //  process call of decorated object is carried out at the server.

    return cPackageOut.read( socket );
}

TFSAction*
SocketClient::create( TFSAction* pDecorated ) const
{
    return new SocketClient( pDecorated );
}

void
SocketClient::setAddress( const char* szAddress
                        , unsigned    nPort )
{
    assign( szAddress, m_sAddress );

    m_nPort     = nPort;
}
