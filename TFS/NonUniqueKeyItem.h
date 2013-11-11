#ifndef ___NonUniqueKeyItem___
#define ___NonUniqueKeyItem___

#include "LessThan.h"

#include <map>
#include <set>

template
<class Key, class Value, class CompareKey=LessThan<Key>, class CompareValue=LessThan<Value*> >
class NonUniqueKeyItem
{
public:
    typedef std::set<Value*,CompareValue>            ValueSet;
    typedef std::map<Key,ValueSet,CompareKey>        Map;
    typedef typename ValueSet::const_iterator        setIterator;
    typedef typename Map::const_iterator             iterator;
    typedef std::set<Key,CompareKey>                 InverseSet;
    typedef std::map<Value*,InverseSet,CompareValue> InverseMap;
    typedef typename InverseSet::const_iterator      inverseSetIterator;
    typedef typename InverseMap::const_iterator      inverseIterator;

public:
                                NonUniqueKeyItem();
    virtual                    ~NonUniqueKeyItem();

public:
    virtual void                add( const Key&
                                   , Value&
                                   , Key Value::* );

public:
    virtual bool                get( const Key&
                                   , const ValueSet* )      const;
    virtual bool                get( const Value&
                                   , const InverseSet* )    const;

public:
    virtual bool                remove( const Key& );
    virtual bool                remove( Value* );

public:
    size_t                      size()                      const;
    typename iterator           begin()                     const;
    typename iterator           end()                       const;

public:
    size_t                      inverseSize()               const;
    typename inverseIterator    inverseBegin()              const;
    typename inverseIterator    inverseEnd()                const;

protected:
    void                        removeKeyFromValue( Key&
                                                  , Value& );

private:
    Map                         m_cMap;
    InverseMap                  m_cInverseMap;
};

#include "NonUniqueKeyItem.hpp"

#endif
