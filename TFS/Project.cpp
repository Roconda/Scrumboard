//#include "stdafx.h"

#include "Project.h"

#include "Sprint.h"
#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_STRING( Project )

Project::Project()
{
    initialize();
}

Project::Project( const std::string& sName )
{
    setName( sName );

    initialize();
}

Project::~Project()
{
    getStorage().remove( this );

    TFSBasis::removeAll<Sprint>( m_paSprint, m_nSizeSprints );
}

void
Project::setName( const std::string& sName )
{
    getStorage().add( this, sName );
}

void
Project::setBeginDay( int nBeginDay )
{
    m_cBegin.day     = nBeginDay;
}

void
Project::setBeginMonth( int nBeginMonth )
{
    m_cBegin.month   = nBeginMonth;
}

void
Project::setBeginYear( int nBeginYear )
{
    m_cBegin.year    = nBeginYear;
}

void
Project::setEndDay( int nEndDay )
{
    m_cEnd.day       = nEndDay;
}

void
Project::setEndMonth( int nEndMonth )
{
    m_cEnd.month     = nEndMonth;
}

void
Project::setEndYear( int nEndYear )
{
    m_cEnd.year      = nEndYear;
}

void
Project::addSprint( const Sprint& cSprint )
{
    TFSBasis::addElement<Sprint>( m_paSprint, m_nSizeSprints, cSprint );
}

const char*
Project::getName() const
{
    return m_sName.c_str();
}

int
Project::getBeginDay() const
{
    return m_cBegin.day;
}

int
Project::getBeginMonth() const
{
    return m_cBegin.month;
}

int
Project::getBeginYear() const
{
    return m_cBegin.year;
}

int
Project::getEndDay() const
{
    return m_cEnd.day;
}

int
Project::getEndMonth() const
{
    return m_cEnd.month;
}

int
Project::getEndYear() const
{
    return m_cEnd.year;
}

size_t
Project::sizeSprints() const
{
    return m_nSizeSprints;
}

Sprint*
Project::getSprint( size_t nIndex )  const
{
    return TFSBasis::getElementAt<Sprint>( m_paSprint, m_nSizeSprints, nIndex );
}

void
Project::removeSprintAt( size_t nIndex )
{
    TFSBasis::removeElementAt( m_paSprint, m_nSizeSprints, nIndex );
}

const std::vector<Sprint*>&
Project::getSprintArray() const
{
    return m_paSprint;
}

TFSBasis*
Project::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    TFSBasis*   pResult = this;

    if ( bWriteToStorage )
    {
        cPackage.add( m_sName );
    }
    else
    {
        std::string sName;

        cPackage.getString( sName );

        if ( getStorage().isPresent(sName) )
            pResult = getStorage().get( sName );
        else
            setName( sName );
    }

    m_cBegin.serialize( cPackage, bWriteToStorage );
    m_cEnd  .serialize( cPackage, bWriteToStorage );

    TFSBasis::serialize<Sprint>( m_paSprint, m_nSizeSprints, cPackage, bWriteToStorage );

    return pResult;
}

Project*
Project::withName( const char* szProjectName )
{
    if ( szProjectName == NULL || szProjectName == '\0' )
        return NULL;
    else
        return getStorage().get( szProjectName );
}

bool
Project::isPresent( const char* szProjectName )
{
    return getStorage().isPresent( szProjectName );
}

bool
Project::operator < ( const Project& cProject ) const
{
    return m_sName < cProject.m_sName;
}

Project::ItemStorage&
Project::getStorage()
{
    static  ItemStorage    *pMap = new ItemStorage( &Project::m_sName );
    return *pMap;
}

void
Project::initialize()
{
    m_nSizeSprints  = 0;
    m_paSprint.resize( INI_SIZE, NULL );
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
Project::ClassID()
{
    return "class Project";
}
