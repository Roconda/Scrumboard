//#include "stdafx.h"

#include "Defect.h"

#include "general.h"
#include "SocketPackage.h"

#include "Status.h"

TFSBASIS_IMPLEMENT_INT( Defect )

Defect::Defect()
{
    m_nSizeStatus   = 0;
    m_paStatus.resize( INI_SIZE, NULL );
}

Defect::~Defect()
{
    TFSBasis::removeAll<Status>( m_paStatus, m_nSizeStatus );
}

void
Defect::setInfo( const char* szInfo )
{
    assign( szInfo, m_sInfo );
}

void
Defect::addStatus( const Status& cStatus )
{
    TFSBasis::addElement<Status>( m_paStatus, m_nSizeStatus, cStatus );
}

const char*
Defect::getInfo() const
{
    return m_sInfo.c_str();
}

size_t
Defect::getCountStatus() const
{
    return m_nSizeStatus;
}

Status*
Defect::getStatus( size_t nIndex ) const
{
    return TFSBasis::getElementAt<Status>( m_paStatus, m_nSizeStatus, nIndex );
}

const std::vector<Status*>&
Defect::getStatusArray() const
{
    return m_paStatus;
}

void
Defect::removeStatusAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paStatus, m_nSizeStatus, nIndex );
}

TFSBasis*
Defect::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    WorkItem::serialize( cPackage, bWriteToStorage );

    if ( bWriteToStorage )
    {
        cPackage.add( m_sInfo );
    }
    else
    {
        std::string sBuffer;

        setInfo( cPackage.getString(sBuffer).c_str() );
    }

    TFSBasis::serialize<Status>( m_paStatus, m_nSizeStatus, cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
Defect::ClassID()
{
    return "class Defect";
}
