#ifndef __ListData
#define __ListData

#include "TFSAction.h"

#include <set>
#include <string>

class ListData : public TFSAction
{
private:
                        ListData();
                        ListData( const char* );

public:
    virtual            ~ListData();

public:
    virtual bool        preprocess( SocketPackage& );
    virtual bool        process( SocketPackage&
                               , SocketPackage& );
    virtual bool        postprocess( SocketPackage& );

public:
    virtual TFSAction*  create()        const;


private:
    typedef std::set<std::string> StringSet;

private:
    virtual void        fillFilenameSet( const std::string&, StringSet& );
    virtual void        fillPackage( const StringSet&, SocketPackage& );

private:
    static ListData     m_cStaticObject;
};

#endif
