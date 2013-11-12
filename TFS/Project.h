#ifndef ___Project
#define ___Project

#include "TFSBasis.h"
#include "ItemStorage.h"
#include "Date.h"

#include <string>
#include <vector>

class Sprint;

class Project : public TFSBasis
{
public:
    typedef ItemStorageWithKey<Project,std::string> ItemStorage;

private:
                                        Project();
                                        Project( const std::string& );

public:
    virtual                            ~Project();

private:
    virtual void                        setName( const std::string& );

public:
    virtual void                        setBeginDay( int );
    virtual void                        setBeginMonth( int );
    virtual void                        setBeginYear( int );
    virtual void                        setEndDay( int );
    virtual void                        setEndMonth( int );
    virtual void                        setEndYear( int );

    virtual void                        addSprint( const Sprint& );

public:
    virtual const char*                 getName()                       const;
    virtual int                         getBeginDay()                   const;
    virtual int                         getBeginMonth()                 const;
    virtual int                         getBeginYear()                  const;
    virtual int                         getEndDay()                     const;
    virtual int                         getEndMonth()                   const;
    virtual int                         getEndYear()                    const;

    virtual size_t                      sizeSprints()                   const;
    virtual Sprint*                     getSprint( size_t )             const;
    virtual const std::vector<Sprint*>& getSprintArray()                const;

public:
    virtual void                        removeSprintAt( size_t );

public:
    virtual TFSBasis*                   serialize( SocketPackage&, bool );

public:
    static  Project*                    withName( const char* );
    static  bool                        isPresent( const char* );

public:
    virtual bool                        operator < ( const Project& )   const;

public:
    static  ItemStorage&                getStorage();

private:
    virtual void                        initialize();

    TFSBASIS_DECLARE( Project )

private:
    std::string                         m_sName;
    Date                                m_cBegin,
                                        m_cEnd;

    size_t                              m_nSizeSprints;
    std::vector<Sprint*>                m_paSprint;

private:
    friend class ItemStorage;
};

#endif
