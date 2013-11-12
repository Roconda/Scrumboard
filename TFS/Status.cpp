//#include "stdafx.h"

#include "Status.h"

#include "general.h"
#include "SocketPackage.h"

#include "StatusType.h"
#include "User.h"

TFSBASIS_IMPLEMENT_INT( Status )

Status::Status()
{
    setUser( User::NoName );

    m_pStatusType   = NULL;
}

Status::~Status()
{
}

void
Status::setDay( int nDay )
{
    m_cDate.day     = nDay;
}

void
Status::setMonth( int nMonth )
{
    m_cDate.month   = nMonth;
}

void
Status::setYear( int nYear )
{
    m_cDate.year    = nYear;
}

void
Status::setAnnotation( const char* szAnnotation )
{
    assign( szAnnotation, m_sAnnotation );
}

void
Status::setUser( const User* pUser )
{
    m_sUser = pUser == NULL ? "" : pUser->getName();
}

void
Status::setStatusType( const StatusType& cStatusType )
{
    m_pStatusType   = (StatusType*) &cStatusType;
}

int
Status::getDay() const
{
    return m_cDate.day;
}

int
Status::getMonth() const
{
    return m_cDate.month;
}

int
Status::getYear() const
{
    return m_cDate.year;
}

const char*
Status::getAnnotation() const
{
    return m_sAnnotation.c_str();
}

User*
Status::getUser() const
{
    return User::withName( m_sUser.c_str() );
}

StatusType*
Status::getStatusType() const
{
    return m_pStatusType;
}

TFSBasis*
Status::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    TFSBasis   *pObject = NULL;

    if ( bWriteToStorage )
    {
        cPackage.add( m_sAnnotation );

        cPackage.add( m_sUser );
        pObject = getUser();
        TFSBasis::serialize( pObject, cPackage, true );

        pObject = m_pStatusType;
        TFSBasis::serialize( pObject, cPackage, true );
    }
    else
    {
        std::string sBuffer;

        setAnnotation( cPackage.getString(sBuffer).c_str() );

        m_sUser         = cPackage.getString( sBuffer );
        TFSBasis::serialize( pObject, cPackage, false );

        TFSBasis::serialize( pObject, cPackage, false );
        m_pStatusType   = dynamic_cast<StatusType*>( pObject );
    }

    m_cDate.serialize( cPackage, bWriteToStorage );

    return this;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
Status::ClassID()
{
    return "class Status";
}
