#ifndef ___Defect___
#define ___Defect___

#include "WorkItem.h"

#include "UniqueKeyItem.h"

#include <string>
#include <vector>

class Status;

class Defect : public WorkItem
{
public:
                                        Defect();
    virtual                            ~Defect();

public:
    virtual void                        setInfo( const char* );

    virtual void                        addStatus( const Status& );

public:
    virtual const char*                 getInfo()           const;

    virtual size_t                      getCountStatus()    const;
    virtual Status*                     getStatus( size_t ) const;
    virtual const std::vector<Status*>& getStatusArray()    const;

public:
    virtual void                        removeStatusAt( size_t );

public:
    virtual TFSBasis*                   serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( Defect )

private:
    std::string                         m_sInfo;

    std::vector<Status*>                m_paStatus;
    size_t                              m_nSizeStatus;
};

#endif
