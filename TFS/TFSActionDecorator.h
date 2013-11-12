#ifndef ___TFSActionDecorator
#define ___TFSActionDecorator

#include "TFSAction.h"

class TFSActionDecorator : public TFSAction
{
protected:
                        TFSActionDecorator( const char* );
                        TFSActionDecorator( TFSAction* );

public:
    virtual            ~TFSActionDecorator();

public:
    virtual bool        preprocess( SocketPackage& );
    virtual bool        process( SocketPackage&
                               , SocketPackage& );
    virtual bool        postprocess( SocketPackage& );

public:
    virtual TFSAction*  create( TFSAction* )    const   = 0;

private:
    virtual TFSAction*  create()                const;

private:
    TFSAction*          m_pDecorated;
};

#endif