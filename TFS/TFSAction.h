#ifndef ___TFSAction
#define ___TFSAction

class SocketPackage;

class TFSAction
{
protected:
                    TFSAction();
                    TFSAction( const char* );

public:
    virtual        ~TFSAction();

public:
    virtual bool        preprocess( SocketPackage& )    = 0;
    virtual bool        process( SocketPackage&
                               , SocketPackage& )       = 0;
    virtual bool        postprocess( SocketPackage& )   = 0;

public:
    virtual TFSAction*  create()                const   = 0;
};

#endif
