//#include "stdafx.h"

#include "StatusType.h"

#include "general.h"
#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_STRING( StatusType )

StatusType::StatusType()
{
    initialize();
}

StatusType::StatusType( const std::string& sName )
{
    setName( sName );

    initialize();
}

StatusType::~StatusType()
{
    getStorage().remove( this );
}

void
StatusType::setAllowedOn( int nAllowedOn )
{
    m_nAllowedOn    = nAllowedOn;
}

void
StatusType::setName( const std::string& sName )
{
    getStorage().add( this, sName );
}

void
StatusType::addPrevStatusType( const StatusType& cType )
{
    add( cType, m_saPrevStatus, m_nPrevCount );
}

void
StatusType::addNextStatusType( const StatusType& cType )
{
    add( cType, m_saNextStatus, m_nNextCount );
}

int
StatusType::getAllowedOn() const
{
    return m_nAllowedOn;
}

const char*
StatusType::getName() const
{
    return m_sName.c_str();
}

size_t
StatusType::sizePrevStatusType() const
{
    return m_nPrevCount;
}

const StatusType*
StatusType::getPrevStatusType( size_t nIndex ) const
{
    return get( nIndex, m_saPrevStatus, m_nPrevCount );
}

size_t
StatusType::sizeNextStatusType() const
{
    return m_nNextCount;
}

const StatusType*
StatusType::getNextStatusType( size_t nIndex ) const
{
    return get( nIndex, m_saNextStatus, m_nNextCount );
}

TFSBasis*
StatusType::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    TFSBasis*   pResult = this;

    if ( bWriteToStorage )
    {
        cPackage.add( m_nAllowedOn );
        cPackage.add( m_sName );
    }
    else
    {
        std::string sName;

        setAllowedOn( cPackage.getInt() );

        cPackage.getString( sName );

        if ( getStorage().isPresent(sName) )
            pResult = getStorage().get( sName );
        else
            setName( sName.c_str() );
    }

    serialize( m_saPrevStatus, m_nPrevCount, cPackage, bWriteToStorage );
    serialize( m_saNextStatus, m_nNextCount, cPackage, bWriteToStorage );

    return pResult;
}

StatusType*
StatusType::withName( const char* szName )
{
    if ( szName == NULL || *szName == '\0' )
        return NULL;
    else
        return getStorage().get( szName );
}

bool
StatusType::isPresent( const char* szName )
{
    return getStorage().isPresent( szName );
}

bool
StatusType::operator < ( const StatusType& cStatus ) const
{
    return m_sName < cStatus.m_sName;
}

StatusType::ItemStorage&
StatusType::getStorage()
{
    static  ItemStorage    *pMap = new ItemStorage( &StatusType::m_sName );
    return *pMap;
}

void
StatusType::add( const StatusType&         cType
               , std::vector<std::string>& saStatus
               , size_t&                   nCount )
{
    if ( nCount >= saStatus.size() )
        saStatus.resize( saStatus.size() << 1 );

    saStatus[nCount++]  = cType.getName();
}

const StatusType*
StatusType::get( size_t                          nIndex
               , const std::vector<std::string>& saStatus
               , size_t                          nCount ) const
{
    if ( nIndex >= 0 && nIndex < nCount )
        return StatusType::withName( saStatus[nIndex].c_str() );
    else
        return NULL;
}

void
StatusType::serialize( std::vector<std::string>& saStatus
                     , size_t&                   nCount
                     , SocketPackage&            cPackage
                     , bool                      bWriteToStorage )
{
    size_t  n;

    if ( bWriteToStorage )
    {
        cPackage.add( int(nCount) );

        for ( n=0; n<nCount; n++ )
            cPackage.add( saStatus[n] );
    }
    else
    {
        nCount   = cPackage.getInt();

        saStatus.resize( std::max<size_t>(INI_SIZE,nCount) );

        for ( n=0; n<nCount; n++ )
        {
            cPackage.getString( saStatus[n] );
        }
    }
}

void
StatusType::initialize()
{
    m_nAllowedOn    = 0;

    m_nPrevCount    = 0;
    m_saPrevStatus.resize( INI_SIZE );

    m_nNextCount    = 0;
    m_saNextStatus.resize( INI_SIZE );
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
StatusType::ClassID()
{
    return "class StatusType";
}
