#ifndef ___UniqueKeyItem___
#define ___UniqueKeyItem___

#include "LessThan.h"
#include "UniqueKey.h"

#include <map>

template
<class Key, class Value, class Compare=LessThan<Key> >
class UniqueKeyItem
{
public:
    class Map : public std::map<Key,Value*,Compare>    {};

    typedef typename Map::const_iterator    iterator;

public:
                            UniqueKeyItem();
    virtual                ~UniqueKeyItem();

public:
    virtual bool            add( const Key&
                               , Value&
                               , Key Value::* );
    virtual Value*          get( const Key& )   const;

    virtual bool            remove( const Key& );

public:
    size_t                  size()              const;
    typename iterator       begin()             const;
    typename iterator       end()               const;

public:
    virtual Key             getUniqueKey()      const;

private:
    Map                     m_cMap;
};

#include "UniqueKeyItem.hpp"

#endif
