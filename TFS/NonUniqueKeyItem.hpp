template
<class Key, class Value, class CompareKey, class CompareValue>
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::NonUniqueKeyItem()
{
}

template
<class Key, class Value, class CompareKey, class CompareValue>
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::~NonUniqueKeyItem()
{
}

template
<class Key, class Value, class CompareKey, class CompareValue>
void
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::add( const Key&  cKey
                                                        , Value&      cValue
                                                        , Key Value::*cField  )
{
    if ( cKey != cValue.*cField )
    {
        removeKeyFromValue( cValue.*cField, cValue );

        m_cMap       [cKey]   .insert( &cValue );
        m_cInverseMap[&cValue].insert( cKey );

        cValue.*cField  = cKey;
    }
}

template
<class Key, class Value, class CompareKey, class CompareValue>
bool
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::get( const Key&      cKey
                                                        , const ValueSet* pSet ) const
{
    iterator    iFind   = m_cMap.find( cKey );
    bool        bFound  = iFind != m_cMap.end();

    if ( bFound )
        pSet    = &iFind->second;
    else
        pSet    = NULL;

    return bFound;
}

template
<class Key, class Value, class CompareKey, class CompareValue>
bool
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::get( const Value&      cValue
                                                        , const InverseSet* pSet ) const
{
    inverseIterator iFind   = m_cInverseMap.find( (Value*) &cValue );
    bool            bFound  = iFind != m_cInverseMap.end();

    if ( bFound )
        pSet    = &iFind->second;
    else
        pSet    = NULL;

    return bFound;
}

template
<class Key, class Value, class CompareKey, class CompareValue>
bool
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::remove( const Key& cKey )
{
    Map::iterator   iFind   = m_cMap.find( cKey );
    bool            bFound  = iFind != m_cMap.end();

    if ( bFound )
    {
        ValueSet&               cSet    = iFind->second;
        ValueSet::iterator      iSet;
        InverseMap::iterator    iInverseFind;

        for ( iSet=cSet.begin(); iSet!=cSet.end(); ++iSet )
        {
            iInverseFind    = m_cInverseMap.find( *iSet );

            if ( iInverseFind->second.size() <= 1 )
                m_cInverseMap.erase( iInverseFind );
            else
                iInverseFind->second.erase( cKey );
        }

        m_cMap.erase( iFind );
    }

    return bFound;
}

template
<class Key, class Value, class CompareKey, class CompareValue>
bool
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::remove( Value* pValue )
{
    InverseMap::iterator    iFind   = m_cInverseMap.find( pValue );
    bool                    bFound  = iFind != m_cInverseMap.end();

    if ( bFound )
    {
        InverseSet&             cSet    = iFind->second;
        InverseSet::iterator    iSet;
        Map::iterator           iInverseFind;

        for ( iSet=cSet.begin(); iSet!=cSet.end(); ++iSet )
        {
            iInverseFind    = m_cMap.find( *iSet );

            if ( iInverseFind->second.size() <= 1 )
                m_cMap.erase( iInverseFind );
            else
                iInverseFind->second.erase( pValue );
        }

        m_cInverseMap.erase( iFind );
    }

    return bFound;
}

template
<class Key, class Value, class CompareKey, class CompareValue>
void
NonUniqueKeyItem<Key,Value,CompareKey,CompareValue>::removeKeyFromValue( Key&   cKey
                                                                       , Value& cValue )
{
    {
        Map::iterator           iFind   = m_cMap.find( cKey );
        if ( iFind != m_cMap.end() )
        {
            ValueSet               &cSet        = iFind->second;
            ValueSet::iterator      iSetFind    = cSet.find( &cValue );

            if ( iSetFind != cSet.end() )
            {
                cSet.erase( iSetFind );

                if ( cSet.size() == 0 )
                    m_cMap.erase( iFind );
            }
        }
    }

    {
        InverseMap::iterator    iFind   = m_cInverseMap.find( &cValue );
        if ( iFind != m_cInverseMap.end() )
        {
            InverseSet             &cSet        = iFind->second;
            InverseSet::iterator    iSetFind    = cSet.find( cKey );

            if ( iSetFind != cSet.end() )
            {
                cSet.erase( iSetFind );

                if ( cSet.size() == 0 )
                    m_cInverseMap.erase( iFind );
            }
        }
    }
}
