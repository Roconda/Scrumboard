#ifndef __ReadData
#define __ReadData

#include "TFSAction.h"

class ReadData : public TFSAction
{
private:
                        ReadData();
                        ReadData( const char* );

public:
    virtual            ~ReadData();

public:
    virtual bool        preprocess( SocketPackage& );
    virtual bool        process( SocketPackage&
                               , SocketPackage& );
    virtual bool        postprocess( SocketPackage& );

public:
    virtual TFSAction*  create()        const;

public:
    template <class Class>
    static  void        readEveryObject( SocketPackage& );

private:
    static ReadData     m_cStaticObject;
};

#include "ReadData.hpp"

#endif
