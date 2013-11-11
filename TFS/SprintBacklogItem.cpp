//#include "stdafx.h"

#include "SprintBacklogItem.h"

#include "Defect.h"
#include "Status.h"
#include "RemainingWorkHistory.h"

#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_INT( SprintBacklogItem )

SprintBacklogItem::SprintBacklogItem()
{
    m_dBaselineWork             = 0.0;
    m_dCompletedWork            = 0.0;
    m_dRemainingWork            = 0.0;

    m_nSizeStatus               = 0;
    m_paStatus.resize( INI_SIZE, NULL );

    m_nSizeDefects              = 0;
    m_paDefect.resize( INI_SIZE, NULL );

    m_nSizeRemainingWorkHistory = 0;
    m_paRemainingWorkHistory.resize( INI_SIZE, NULL );
}

SprintBacklogItem::~SprintBacklogItem()
{
    TFSBasis::removeAll<Status>              ( m_paStatus              , m_nSizeStatus );
    TFSBasis::removeAll<Defect>              ( m_paDefect              , m_nSizeDefects );
    TFSBasis::removeAll<RemainingWorkHistory>( m_paRemainingWorkHistory, m_nSizeRemainingWorkHistory );
}

void
SprintBacklogItem::setBaselineWork( double dBaselineWork )
{
    m_dBaselineWork     = dBaselineWork;
}

void
SprintBacklogItem::setCompletedWork( double dCompletedWork )
{
    m_dCompletedWork    = dCompletedWork;
}

void
SprintBacklogItem::setRemainingWork( double dRemainingWork )
{
    m_dRemainingWork    = dRemainingWork;
}

void
SprintBacklogItem::addStatus( const Status& cStatus )
{
    TFSBasis::addElement<Status>( m_paStatus, m_nSizeStatus, cStatus );
}

void
SprintBacklogItem::addDefect( const Defect& cDefect )
{
    TFSBasis::addElement<Defect>( m_paDefect, m_nSizeDefects, cDefect );
}

void
SprintBacklogItem::addRemainingWorkHistory( const RemainingWorkHistory& cHistory )
{
    TFSBasis::addElement<RemainingWorkHistory>( m_paRemainingWorkHistory, m_nSizeRemainingWorkHistory, cHistory );
}

double
SprintBacklogItem::getBaselineWork() const
{
    return m_dBaselineWork;
}

double
SprintBacklogItem::getCompletedWork() const
{
    return m_dCompletedWork;
}

double
SprintBacklogItem::getRemainingWork() const
{
    return m_dRemainingWork;
}

size_t
SprintBacklogItem::sizeStatus() const
{
    return m_nSizeStatus;
}

Status*
SprintBacklogItem::getStatus( size_t nIndex ) const
{
    return TFSBasis::getElementAt<Status>( m_paStatus, m_nSizeStatus, nIndex );
}

const std::vector<Status*>&
SprintBacklogItem::getStatusArray() const
{
    return m_paStatus;
}

size_t
SprintBacklogItem::sizeDefects() const
{
    return m_nSizeDefects;
}

Defect*
SprintBacklogItem::getDefect( size_t nIndex ) const
{
    return TFSBasis::getElementAt<Defect>( m_paDefect, m_nSizeDefects, nIndex );
}

const std::vector<Defect*>&
SprintBacklogItem::getDefectArray() const
{
    return m_paDefect;
}

size_t
SprintBacklogItem::sizeRemainingWorkHistory() const
{
    return m_nSizeRemainingWorkHistory;
}

RemainingWorkHistory*
SprintBacklogItem::getRemainingWorkHistory( size_t nIndex ) const
{
    return TFSBasis::getElementAt<RemainingWorkHistory>( m_paRemainingWorkHistory, m_nSizeRemainingWorkHistory, nIndex );
}

const std::vector<RemainingWorkHistory*>&
SprintBacklogItem::getRemainingWorkHistoryArray() const
{
    return m_paRemainingWorkHistory;
}

void
SprintBacklogItem::removeStatusAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paStatus, m_nSizeStatus, nIndex );
}

void
SprintBacklogItem::removeDefectAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paDefect, m_nSizeDefects, nIndex );
}

void
SprintBacklogItem::removeRemainingWorkHistoryAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paRemainingWorkHistory, m_nSizeRemainingWorkHistory, nIndex );
}

TFSBasis*
SprintBacklogItem::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    WorkItem::serialize( cPackage, bWriteToStorage );

    if ( bWriteToStorage )
    {
        cPackage.add( m_dBaselineWork );
        cPackage.add( m_dCompletedWork );
        cPackage.add( m_dRemainingWork );
    }
    else
    {
        setBaselineWork ( cPackage.getDouble() );
        setCompletedWork( cPackage.getDouble() );
        setRemainingWork( cPackage.getDouble() );
    }

    TFSBasis::serialize<Status>              ( m_paStatus              , m_nSizeStatus              , cPackage, bWriteToStorage );
    TFSBasis::serialize<Defect>              ( m_paDefect              , m_nSizeDefects             , cPackage, bWriteToStorage );
    TFSBasis::serialize<RemainingWorkHistory>( m_paRemainingWorkHistory, m_nSizeRemainingWorkHistory, cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
SprintBacklogItem::ClassID()
{
    return "class SprintBacklogItem";
}
