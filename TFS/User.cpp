//#include "stdafx.h"

#include "User.h"

#include "general.h"
#include "SocketPackage.h"

TFSBASIS_IMPLEMENT_STRING( User )

User::User()
{
}

User::User( const std::string& sName )
{
    getStorage().add( this, sName );
}

User::~User()
{
    getStorage().remove( this );
}

const char*
User::getName() const
{
    return m_sName.c_str();
}

TFSBasis*
User::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    TFSBasis*   pResult = this;

    if ( bWriteToStorage )
        cPackage.add( m_sName );
    else
    {
        std::string sName;

        cPackage.getString( sName );

        if ( getStorage().isPresent(sName) )
            pResult = getStorage().get( sName );
        else
            getStorage().add( this, sName );
    }

    return pResult;
}

User*
User::withName( const char* szName )
{
    if ( szName == NULL || *szName == '\0' )
        return NULL;
    else
        return getStorage().get( szName );
}

bool
User::isPresent( const char* szName )
{
    return getStorage().isPresent( szName );
}

size_t
User::size()
{
    return getStorage().size();
}

User::ItemStorage::iterator
User::begin()
{
    return getStorage().begin();
}

User::ItemStorage::iterator
User::end()
{
    return getStorage().end();
}

bool
User::operator < ( const User& cUser ) const
{
    return m_sName < cUser.m_sName;
}

User::ItemStorage&
User::getStorage()
{
    static  ItemStorage    *pMap    = new ItemStorage( &User::m_sName );
    return *pMap;
}

//  RTTI generates a memory leak message: typeid( Class ).name();
const char*
User::ClassID()
{
    return "class User";
}
