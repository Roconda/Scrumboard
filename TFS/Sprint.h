#ifndef ___Sprint
#define ___Sprint

#include "TFSBasis.h"
#include "UniqueKeyItem.h"
#include "Date.h"

#include <vector>

class WorkItem;

class Sprint : public TFSBasis
{
public:
                                            Sprint();
    virtual                                ~Sprint();

public:
    virtual void                            setName( const char* );
    virtual void                            setBeginDay( int );
    virtual void                            setBeginMonth( int );
    virtual void                            setBeginYear( int );
    virtual void                            setEndDay( int );
    virtual void                            setEndMonth( int );
    virtual void                            setEndYear( int );

    virtual void                            addWorkItem( const WorkItem& );

public:
    virtual const char*                     getName()               const;
    virtual int                             getBeginDay()           const;
    virtual int                             getBeginMonth()         const;
    virtual int                             getBeginYear()          const;
    virtual int                             getEndDay()             const;
    virtual int                             getEndMonth()           const;
    virtual int                             getEndYear()            const;

    virtual size_t                          sizeWorkItems()         const;
    virtual WorkItem*                       getWorkItem( size_t )   const;
    virtual const std::vector<WorkItem*>&   getWorkItemArray()      const;

public:
    virtual void                            removeWorkItemAt( size_t );

public:
    virtual TFSBasis*                       serialize( SocketPackage&, bool );

private:
    TFSBASIS_DECLARE( Sprint )

private:
    std::string                     m_sName;
    Date                            m_cBegin,
                                    m_cEnd;

    size_t                          m_nSizeWorkItems;
    std::vector<WorkItem*>          m_paWorkItem;
};

#endif
