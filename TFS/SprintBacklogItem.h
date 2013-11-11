#ifndef ___SprintBacklogItem___
#define ___SprintBacklogItem___

#include "WorkItem.h"

class Defect;
class Status;
class RemainingWorkHistory;

class SprintBacklogItem : public WorkItem
{
public:
                                                        SprintBacklogItem();
    virtual                                            ~SprintBacklogItem();

public:
    virtual void                                        setBaselineWork( double );
    virtual void                                        setCompletedWork( double );
    virtual void                                        setRemainingWork( double );

    virtual void                                        addStatus( const Status& );
    virtual void                                        addDefect( const Defect& );
    virtual void                                        addRemainingWorkHistory( const RemainingWorkHistory& );

public:
    virtual double                                      getBaselineWork()                   const;
    virtual double                                      getCompletedWork()                  const;
    virtual double                                      getRemainingWork()                  const;

    virtual size_t                                      sizeStatus()                        const;
    virtual Status*                                     getStatus( size_t )                 const;
    virtual const std::vector<Status*>&                 getStatusArray()                    const;

    virtual size_t                                      sizeDefects()                       const;
    virtual Defect*                                     getDefect( size_t )                 const;
    virtual const std::vector<Defect*>&                 getDefectArray()                    const;

    virtual size_t                                      sizeRemainingWorkHistory()          const;
    virtual RemainingWorkHistory*                       getRemainingWorkHistory( size_t )   const;
    virtual const std::vector<RemainingWorkHistory*>&   getRemainingWorkHistoryArray()      const;

public:
    virtual void                                        removeStatusAt( size_t );
    virtual void                                        removeDefectAt( size_t );
    virtual void                                        removeRemainingWorkHistoryAt( size_t );

public:
    virtual TFSBasis*                                   serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( SprintBacklogItem )

private:
    double                                              m_dBaselineWork,
                                                        m_dCompletedWork,
                                                        m_dRemainingWork;

    size_t                                              m_nSizeStatus,
                                                        m_nSizeDefects,
                                                        m_nSizeRemainingWorkHistory;
    std::vector<Status*>                                m_paStatus;
    std::vector<Defect*>                                m_paDefect;
    std::vector<RemainingWorkHistory*>                  m_paRemainingWorkHistory;
};

#endif