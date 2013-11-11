#ifndef __SocketClient
#define __SocketClient

#include "TFSActionDecorator.h"

#include <string>

class SocketPackage;

class SocketClient : public TFSActionDecorator
{
private:
                            SocketClient( const char* );
                            SocketClient( TFSAction* );

public:
    virtual bool            process( SocketPackage&
                                   , SocketPackage& );

    virtual TFSAction*      create( TFSAction* )    const;

public:
    static  void            setAddress( const char*
                                      , unsigned );

private:
    static  std::string     m_sAddress;
    static  unsigned        m_nPort;

private:
    static  SocketClient    m_cStaticObject;
};

#endif
