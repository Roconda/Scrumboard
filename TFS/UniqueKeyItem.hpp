template
<class Key, class Value, class Compare>
UniqueKeyItem<Key,Value,Compare>::UniqueKeyItem()
{
}

template
<class Key, class Value, class Compare>
UniqueKeyItem<Key,Value,Compare>::~UniqueKeyItem()
{
}

template
<class Key, class Value, class Compare>
bool
UniqueKeyItem<Key,Value,Compare>::add( const Key&  cKey
                                     , Value&      cValue
                                     , Key Value::*cField )
{
    bool    bNotThere   = m_cMap.find( cKey ) == m_cMap.end();

    if ( bNotThere )
    {
        if ( cKey != cValue.*cField )
        {
            remove( cValue.*cField );

            cValue.*cField  = cKey;

            m_cMap[cKey]    = &cValue;
        }
    }

    return bNotThere;
}

template
<class Key, class Value, class Compare>
Value*
UniqueKeyItem<Key,Value,Compare>::get( const Key& cKey ) const
{
    iterator    iFind   = m_cMap.find( cKey );

    if ( iFind == m_cMap.end() )
        return NULL;
    else
        return (Value*) iFind->second;
}

template
<class Key, class Value, class Compare>
bool
UniqueKeyItem<Key,Value,Compare>::remove( const Key& cKey )
{
    Map::iterator   iFind       = m_cMap.find( cKey );
    bool            bIsPresent  = iFind != m_cMap.end();

    if ( bIsPresent )
        m_cMap.erase( iFind );

    return bIsPresent;
}

template
<class Key, class Value, class Compare>
size_t
UniqueKeyItem<Key,Value,Compare>::size() const
{
    return m_cMap.size();
}

template
<class Key, class Value, class Compare>
typename UniqueKeyItem<Key,Value,Compare>::iterator
UniqueKeyItem<Key,Value,Compare>::begin() const
{
    return m_cMap.begin();
}

template
<class Key, class Value, class Compare>
typename UniqueKeyItem<Key,Value,Compare>::iterator
UniqueKeyItem<Key,Value,Compare>::end() const
{
    return m_cMap.end();
}

template
<class Key,class Value, class Compare>
Key
UniqueKeyItem<Key,Value,Compare>::getUniqueKey() const
{
    return  m_cMap.size() == 0 ? firstValue<Key>() : nextValue<Key>( m_cMap.rbegin()->first );
}
