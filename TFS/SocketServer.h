#ifndef __SockerServer
#define __SockerServer

#include "AbstractSocketServer.h"

class SocketServer : public AbstractSocketServer
{
public:
                    SocketServer( unsigned );

public:
    virtual void    handleTCPClient( TCPSocket* );
};

#endif
