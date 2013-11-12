//#include "stdafx.h"

#include "RemainingWorkHistory.h"

#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_INT( RemainingWorkHistory )

RemainingWorkHistory::RemainingWorkHistory()
{
    m_nRemainingWork    = 0;
}

RemainingWorkHistory::~RemainingWorkHistory()
{
}

void
RemainingWorkHistory::setDay( int nDay )
{
    m_cDate.day         = nDay;
}

void
RemainingWorkHistory::setMonth( int nMonth )
{
    m_cDate.month       = nMonth;
}

void
RemainingWorkHistory::setYear( int nYear )
{
    m_cDate.year        = nYear;
}

void
RemainingWorkHistory::setRemainingWork( int nWork )
{
    m_nRemainingWork    = nWork;
}

int
RemainingWorkHistory::getDay() const
{
    return m_cDate.day;
}

int
RemainingWorkHistory::getMonth() const
{
    return m_cDate.month;
}

int
RemainingWorkHistory::getYear() const
{
    return m_cDate.year;
}

int
RemainingWorkHistory::getRemainingWork() const
{
    return m_nRemainingWork;
}

TFSBasis*
RemainingWorkHistory::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    if ( bWriteToStorage )
        cPackage.add( m_nRemainingWork );
    else
        setRemainingWork( cPackage.getInt() );

    m_cDate.serialize( cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
RemainingWorkHistory::ClassID()
{
    return "class RemainingWorkHistory";
}
