//#include "stdafx.h"

#include "WorkItem.h"

#include "Attachment.h"
#include "general.h"
#include "SocketPackage.h"
#include "User.h"

TFSBASIS_IMPLEMENT_INT( WorkItem )

WorkItem::WorkItem()
{
    m_nWorkItemNumber   = 0;

    m_nCount            = 0;
    m_paAttachment.resize( INI_SIZE, NULL );

    setUser( User::NoName );
}

WorkItem::~WorkItem()
{
    TFSBasis::removeAll<Attachment>( m_paAttachment, m_nCount );
}

void
WorkItem::setAdditionalInfo( const char* szAdditionalInfo )
{
    assign( szAdditionalInfo, m_sAdditionalInfo );
}

void
WorkItem::setDescription( const char* szDescription )
{
    assign( szDescription, m_sDescription );
}

void
WorkItem::setIterationPath( const char* szIterationPath )
{
    assign( szIterationPath, m_sIterationPath );
}

void
WorkItem::setTitle( const char* szTitle )
{
    assign( szTitle, m_sTitle );
}

void
WorkItem::setWorkItemNumber( int nWorkItemNumber )
{
    m_nWorkItemNumber   = nWorkItemNumber;
}

void
WorkItem::setUser( const User* pUser )
{
    m_sUser = pUser == NULL ? "" : pUser->getName();
}

void
WorkItem::addAttachment( const Attachment& cAttachment )
{
    TFSBasis::addElement<Attachment>( m_paAttachment, m_nCount, cAttachment );
}

const char*
WorkItem::getAdditionalInfo() const
{
    return m_sAdditionalInfo.c_str();
}

const char*
WorkItem::getDescription() const
{
    return m_sDescription.c_str();
}

const char*
WorkItem::getIterationPath() const
{
    return m_sIterationPath.c_str();
}

const char*
WorkItem::getTitle() const
{
    return m_sTitle.c_str();
}

int
WorkItem::getWorkItemNumber() const
{
    return m_nWorkItemNumber;
}

User*
WorkItem::getUser()
{
    return User::withName( m_sUser.c_str() );
}

size_t
WorkItem::getNumberOfAttachements() const
{
    return m_nCount;
}

Attachment*
WorkItem::getAttachment( size_t nIndex ) const
{
    return TFSBasis::getElementAt<Attachment>( m_paAttachment, m_nCount, nIndex );
}

const std::vector<Attachment*> &
WorkItem::getAttachmentArray() const
{
    return m_paAttachment;
}

void
WorkItem::removeAttachmentAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paAttachment, m_nCount, nIndex );
}

TFSBasis*
WorkItem::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    TFSBasis   *pObject = NULL;

    if ( bWriteToStorage )
    {
        cPackage.add( m_sAdditionalInfo );
        cPackage.add( m_sDescription );
        cPackage.add( m_sIterationPath );
        cPackage.add( m_sTitle );
        cPackage.add( m_nWorkItemNumber );

        cPackage.add( m_sUser );
        pObject = getUser();
        TFSBasis::serialize( pObject, cPackage, true );
    }
    else
    {
        std::string sBuffer;

        WorkItem::setAdditionalInfo( cPackage.getString(sBuffer).c_str() );
        WorkItem::setDescription   ( cPackage.getString(sBuffer).c_str() );
        WorkItem::setIterationPath ( cPackage.getString(sBuffer).c_str() );
        WorkItem::setTitle         ( cPackage.getString(sBuffer).c_str() );
        WorkItem::setWorkItemNumber( cPackage.getInt() );

        m_sUser     = cPackage.getString( sBuffer );
        TFSBasis::serialize( pObject, cPackage, false );
    }

    TFSBasis::serialize<Attachment>( m_paAttachment, m_nCount, cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
WorkItem::ClassID()
{
    return "class WorkItem";
}
