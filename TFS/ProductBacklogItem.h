#ifndef ___ProductBacklogItem
#define ___ProductBacklogItem

#include "WorkItem.h"

class SprintBacklogItem;
class Status;

class ProductBacklogItem : public WorkItem
{
public:
                                                    ProductBacklogItem();
    virtual                                        ~ProductBacklogItem();

public:
    virtual void                                    setDefinitionOfDone( const char* );
    virtual void                                    setEstimatedPoints( int );
    virtual void                                    setPriority( int );

    virtual void                                    addBacklogItem( const SprintBacklogItem& );
    virtual void                                    addStatus( const Status& );

public:
    virtual const char*                             getDefinitionOfDone()           const;
    virtual int                                     getEstimatedPoints()            const;
    virtual int                                     getPriority()                   const;

    virtual size_t                                  getSizeBacklogItems()           const;
    virtual SprintBacklogItem*                      getBacklogItem( size_t )        const;
    virtual const std::vector<SprintBacklogItem*>&  getBacklogItemArray()           const;

    virtual size_t                                  getSizeStatus()                 const;
    virtual Status*                                 getStatus( size_t )             const;
    virtual const std::vector<Status*>&             getStatusArray()                const;

public:
    virtual void                                    removeBacklogItemAt( size_t );
    virtual void                                    removeStatusAt( size_t );

public:
    virtual TFSBasis*                               serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( ProductBacklogItem )

private:
    std::string                                     m_sDefinitionOfDone;
    int                                             m_nEstimatedPoints,
                                                    m_nPriority;

    size_t                                          m_nSizeStatus,
                                                    m_nSizeBackLogItems;
    std::vector<Status*>                            m_paStatus;
    std::vector<SprintBacklogItem*>                 m_paBackLogItem;
};

#endif
