#ifndef __RemainingWorkHistory
#define __RemainingWorkHistory

#include "TFSBasis.h"
#include "NonUniqueKeyItem.h"
#include "UniqueKeyItem.h"
#include "Date.h"

class SocketPackage;

class RemainingWorkHistory : public TFSBasis
{
public:
                        RemainingWorkHistory();
    virtual            ~RemainingWorkHistory();

public:
    virtual void        setDay( int );
    virtual void        setMonth( int );
    virtual void        setYear( int );

    virtual void        setRemainingWork( int );

public:
    virtual int         getDay()            const;
    virtual int         getMonth()          const;
    virtual int         getYear()           const;
    virtual int         getRemainingWork()  const;

public:
    virtual TFSBasis*   serialize( SocketPackage&, bool );

public:
    TFSBASIS_DECLARE( RemainingWorkHistory )

private:
    Date                m_cDate;
    int                 m_nRemainingWork;
};

#endif
