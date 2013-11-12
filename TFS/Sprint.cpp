//#include "stdafx.h"

#include "Sprint.h"

#include "WorkItem.h"
#include "general.h"
#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_INT( Sprint )

Sprint::Sprint()
{
    m_nSizeWorkItems    = 0;
    m_paWorkItem.resize( INI_SIZE, NULL );
}

Sprint::~Sprint()
{
    TFSBasis::removeAll<WorkItem>( m_paWorkItem, m_nSizeWorkItems );
}

void
Sprint::setName( const char* szName )
{
    assign( szName, m_sName );
}

void
Sprint::setBeginDay( int nBeginDay )
{
    m_cBegin.day     = nBeginDay;
}

void
Sprint::setBeginMonth( int nBeginMonth )
{
    m_cBegin.month   = nBeginMonth;
}

void
Sprint::setBeginYear( int nBeginYear )
{
    m_cBegin.year    = nBeginYear;
}

void
Sprint::setEndDay( int nEndDay )
{
    m_cEnd.day       = nEndDay;
}

void
Sprint::setEndMonth( int nEndMonth )
{
    m_cEnd.month     = nEndMonth;
}

void
Sprint::setEndYear( int nEndYear )
{
    m_cEnd.year      = nEndYear;
}

void
Sprint::addWorkItem( const WorkItem& cWorkItem )
{
    TFSBasis::addElement<WorkItem>( m_paWorkItem, m_nSizeWorkItems, cWorkItem);
}

const char*
Sprint::getName() const
{
    return m_sName.c_str();
}

int
Sprint::getBeginDay() const
{
    return m_cBegin.day;
}

int
Sprint::getBeginMonth() const
{
    return m_cBegin.month;
}

int
Sprint::getBeginYear() const
{
    return m_cBegin.year;
}

int
Sprint::getEndDay() const
{
    return m_cEnd.day;
}

int
Sprint::getEndMonth() const
{
    return m_cEnd.month;
}

int
Sprint::getEndYear() const
{
    return m_cEnd.year;
}

size_t
Sprint::sizeWorkItems() const
{
    return m_nSizeWorkItems;
}

WorkItem*
Sprint::getWorkItem( size_t nIndex ) const
{
    return TFSBasis::getElementAt<WorkItem>( m_paWorkItem, m_nSizeWorkItems, nIndex );
}

const std::vector<WorkItem*>&
Sprint::getWorkItemArray() const
{
    return m_paWorkItem;
}

void
Sprint::removeWorkItemAt( size_t nIndex )
{
    return TFSBasis::removeElementAt( m_paWorkItem, m_nSizeWorkItems, nIndex );
}

TFSBasis*
Sprint::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    if ( bWriteToStorage )
    {
        cPackage.add( m_sName );
    }
    else
    {
        std::string sBuffer;

        setName( cPackage.getString(sBuffer).c_str() );
    }

    TFSBasis::serialize<WorkItem>( m_paWorkItem, m_nSizeWorkItems, cPackage, bWriteToStorage );
    m_cBegin.serialize( cPackage, bWriteToStorage );
    m_cEnd  .serialize( cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
Sprint::ClassID()
{
    return "class Sprint";
}
