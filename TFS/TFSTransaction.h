#ifndef ___TFSTransaction
#define ___TFSTransaction

class Project;

#include <list>
#include <string>

class TFSTransaction
{
public:
    static  void        remoteWriteProject( const char* );
    static  void        localWriteProject( const char* );

public:
    static  Project*    remoteReadProject( const char* );
    static  Project*    localReadProject( const char* );

public:
    typedef std::list<std::string> ProjectList;

public:
    static  void        remoteListProjects( ProjectList& );
    static  void        localListProjects( ProjectList& );

public:
    static  void        removeAllData();

public:
    static  void        setRemoteAddress( const char*
                                        , unsigned );

private:
    static  void        listProjects( const char*, ProjectList& );

private:
    static  void        projectAction( const char*, const char* );
};

#endif
