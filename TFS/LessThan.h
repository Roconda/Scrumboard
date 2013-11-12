#ifndef ____BH_Equal___
#define ____BH_Equal___

template
<class Key>
class LessThan
{
public:
    bool operator () ( const Key& cKey1, const Key& cKey2 ) const
    {
        return cKey1 < cKey2;
    }
};

template
<class Key>
class PointerLessThan
{
public:
    bool operator ()(  const Key* pKey1, const Key* pKey2 ) const
    {
        if ( pKey1 == pKey2 )
            return false;

        if ( pKey1 == NULL || pKey2 == NULL )
            return pKey2 == NULL;

        return *pKey1 < *pKey2;
    }
};

#endif
