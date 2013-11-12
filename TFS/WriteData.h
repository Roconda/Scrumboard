#ifndef __WriteData
#define __WriteData

#include "TFSAction.h"

#include <string>

class WriteData : public TFSAction
{
private:
                        WriteData();
                        WriteData( const char* );

public:
    virtual            ~WriteData();

public:
    virtual bool        preprocess( SocketPackage& );
    virtual bool        process( SocketPackage&
                               , SocketPackage& );
    virtual bool        postprocess( SocketPackage& );

public:
    virtual TFSAction*  create()        const;

public:
    template <class Class>
    static  void        writeEveryObject( SocketPackage& );

private:
    virtual void        createFilename( SocketPackage&, bool, std::string& );
    virtual void        copyFile( SocketPackage&, const std::string& );
    virtual bool        writeData( SocketPackage&, const std::string& );

private:
    static WriteData    m_cStaticObject;
};

#include "WriteData.hpp"

#endif
