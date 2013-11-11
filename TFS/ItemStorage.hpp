template
<class Class>
ItemStorage<Class>::ItemStorage( bool )
    : ItemStorageBase()
{
    m_bDeleteContainers = true;
}

template
<class Class>
ItemStorage<Class>::ItemStorage()
    : ItemStorageBase()
{
    m_bDeleteContainers = false;
}

template
<class Class>
ItemStorage<Class>::~ItemStorage()
{
    removeAll();

    if ( m_bDeleteContainers )
        removeContainers();
}

template
<class Class>
void
ItemStorage<Class>::add( Class* pClass )
{
    if ( pClass != NULL )
        m_cSet.insert( pClass );
}

template
<class Class>
void
ItemStorage<Class>::remove( Class* pClass )
{
    if ( isPresent(pClass) )
        m_cSet.erase( pClass );
}

template
<class Class>
bool
ItemStorage<Class>::isPresent( Class* pClass ) const
{
    return m_cSet.find(pClass) != m_cSet.end();
}

template
<class Class>
void
ItemStorage<Class>::removeAll()
{
    std::set<Class*>::iterator  iSet;
    Class*                      pClass;

    for ( iSet=m_cSet.begin(); iSet!=m_cSet.end(); iSet=m_cSet.begin() )
    {
        pClass  = *iSet;

        if ( pClass->storedInHeap() )
            delete pClass;
    }

    m_cSet.clear();
}

template
<class Class,class Key>
ItemStorageWithKey<Class,Key>::ItemStorageWithKey( Key Class::*cField )
    : ItemStorage<Class>()
    , m_cField( cField )
{
    getStorageContainer().insert( this );
}

template
<class Class,class Key>
ItemStorageWithKey<Class,Key>::~ItemStorageWithKey()
{
    getStorageContainer().erase( this );

    m_cMap.clear();
}

template
<class Class,class Key>
bool
ItemStorageWithKey<Class,Key>::add( Class* pClass, const Key& cKey )
{
    bool    bCanInsert  = pClass != NULL;

    if ( bCanInsert && cKey != pClass->*m_cField )
    {
        Map::iterator   iMap    = m_cMap.find( cKey );

        bCanInsert  = iMap == m_cMap.end();

        if ( bCanInsert )
        {
            Map::iterator   iDelete = m_cMap.find( pClass->*m_cField );

            if ( iDelete != m_cMap.end() )
                m_cMap.erase( iDelete );

            pClass->*m_cField   = cKey;
            m_cMap[cKey]        = pClass;
        }
    }

    return bCanInsert;
}

template
<class Class,class Key>
void
ItemStorageWithKey<Class,Key>::remove( Class* pClass )
{
    bool    bCanDelete  = pClass != NULL;

    if ( bCanDelete )
    {
        Map::iterator   iDelete = m_cMap.find( pClass->*m_cField );

        if ( iDelete != m_cMap.end() )
            m_cMap.erase( iDelete );
    }
}

template
<class Class,class Key>
void
ItemStorageWithKey<Class,Key>::removeAll()
{
    m_cMap.clear();
}

template
<class Class,class Key>
Class*
ItemStorageWithKey<Class,Key>::get( const Key& cKey )
{
    Map::iterator   iMap    = m_cMap.find( cKey );

    if ( iMap == m_cMap.end() )
    {
        Class*  pClass  = new Class( /*cKey*/ );

        add( pClass, cKey );

        return pClass;
    }
    else
        return iMap->second;
}

template
<class Class,class Key>
bool
ItemStorageWithKey<Class,Key>::isPresent( const Key& cKey )
{
    return m_cMap.find( cKey ) != m_cMap.end();
}

template
<class Class,class Key>
size_t
ItemStorageWithKey<Class,Key>::size() const
{
    return m_cMap.size();
}
        
template
<class Class,class Key>
typename ItemStorageWithKey<Class,Key>::iterator
ItemStorageWithKey<Class,Key>::begin() const
{
    return m_cMap.begin();
}

template
<class Class,class Key>
typename ItemStorageWithKey<Class,Key>::iterator
ItemStorageWithKey<Class,Key>::end() const
{
    return m_cMap.end();
}
