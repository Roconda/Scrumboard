//#include "stdafx.h"

#include "ProductBacklogItem.h"

#include "general.h"

#include "SprintBacklogItem.h"
#include "Status.h"

#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_INT( ProductBacklogItem )

ProductBacklogItem::ProductBacklogItem()
{
    m_nEstimatedPoints  = 0;
    m_nPriority         = 0;


    m_nSizeStatus       = 0;
    m_paStatus     .resize( INI_SIZE, NULL );

    m_nSizeBackLogItems = 0;
    m_paBackLogItem.resize( INI_SIZE, NULL );
}

ProductBacklogItem::~ProductBacklogItem()
{
    TFSBasis::removeAll<Status>           ( m_paStatus     , m_nSizeStatus );
    TFSBasis::removeAll<SprintBacklogItem>( m_paBackLogItem, m_nSizeBackLogItems );
}

void
ProductBacklogItem::setDefinitionOfDone( const char* szDefinitionOfDone )
{
    assign( szDefinitionOfDone, m_sDefinitionOfDone );    
}

void
ProductBacklogItem::setEstimatedPoints( int nEstimatedPoints )
{
    m_nEstimatedPoints  = nEstimatedPoints;
}

void
ProductBacklogItem::setPriority( int nPriority )
{
    m_nPriority         = nPriority;
}

void
ProductBacklogItem::addBacklogItem( const SprintBacklogItem& cItem )
{
    TFSBasis::addElement<SprintBacklogItem>( m_paBackLogItem, m_nSizeBackLogItems, cItem );
}

void
ProductBacklogItem::addStatus( const Status& cStatus )
{
    TFSBasis::addElement<Status>( m_paStatus, m_nSizeStatus, cStatus );
}

const char*
ProductBacklogItem::getDefinitionOfDone() const
{
    return m_sDefinitionOfDone.c_str();
}

int
ProductBacklogItem::getEstimatedPoints() const
{
    return m_nEstimatedPoints;
}

int
ProductBacklogItem::getPriority() const
{
    return m_nPriority;
}

size_t
ProductBacklogItem::getSizeBacklogItems() const
{
    return m_nSizeBackLogItems;
}

SprintBacklogItem*
ProductBacklogItem::getBacklogItem( size_t nIndex ) const
{
    return TFSBasis::getElementAt<SprintBacklogItem>( m_paBackLogItem, m_nSizeBackLogItems, nIndex );
}

const std::vector<SprintBacklogItem*>&
ProductBacklogItem::getBacklogItemArray() const
{
    return m_paBackLogItem;
}

size_t
ProductBacklogItem::getSizeStatus() const
{
    return m_nSizeStatus;
}

Status*
ProductBacklogItem::getStatus( size_t nIndex ) const
{
    return TFSBasis::getElementAt<Status>( m_paStatus, m_nSizeStatus, nIndex );
}

const std::vector<Status*>&
ProductBacklogItem::getStatusArray() const
{
    return m_paStatus;
}

void
ProductBacklogItem::removeBacklogItemAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paBackLogItem, m_nSizeBackLogItems, nIndex );
}

void
ProductBacklogItem::removeStatusAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paStatus, m_nSizeStatus, nIndex );
}

TFSBasis*
ProductBacklogItem::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    WorkItem::serialize( cPackage, bWriteToStorage );

    if ( bWriteToStorage )
    {
        cPackage.add( m_sDefinitionOfDone );
        cPackage.add( m_nEstimatedPoints );
        cPackage.add( m_nPriority );
    }
    else
    {
        std::string     sBuffer;

        setDefinitionOfDone( cPackage.getString(sBuffer).c_str() );
        setEstimatedPoints ( cPackage.getInt() );
        setPriority        ( cPackage.getInt() );
    }

    TFSBasis::serialize<Status>           ( m_paStatus     , m_nSizeStatus      , cPackage, bWriteToStorage );
    TFSBasis::serialize<SprintBacklogItem>( m_paBackLogItem, m_nSizeBackLogItems, cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
ProductBacklogItem::ClassID()
{
    return "class ProductBacklogItem";
}
