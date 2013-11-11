#ifndef ___ItemStorage____
#define ___ItemStorage____

#include <set>
#include <map>

class ItemStorageBase
{
protected:
                            ItemStorageBase();

public:
    virtual                ~ItemStorageBase();

public:
    virtual void            removeAll() = 0;

public:
    typedef std::set<ItemStorageBase*> ItemStorageSet;

public:
    static  ItemStorageSet& getStorageContainer();
    static  void            emptyContainers();

protected:
    static  void            removeContainers();
};

template
<class Class>
class ItemStorage : public ItemStorageBase
{
public:
                            ItemStorage( bool );

public:
                            ItemStorage();
    virtual                ~ItemStorage();

public:
    virtual void            add( Class* );
    virtual void            remove( Class* );

public:
    virtual bool            isPresent( Class* )   const;

public:
    virtual void            removeAll();

private:
    class ClassSet : public std::set<Class*> {};

private:
    ClassSet                m_cSet;
    bool                    m_bDeleteContainers;
};

template
<class Class,class Key>
class ItemStorageWithKey : public ItemStorage<Class>
{
public:
    typedef std::map<Key,Class*>          Map;
    typedef typename Map::const_iterator  iterator;

public:
                                ItemStorageWithKey( Key Class::* );
    virtual                    ~ItemStorageWithKey();

public:
    virtual bool                add( Class*, const Key& );
    virtual void                remove( Class* );

public:
    virtual void                removeAll();

public:
    virtual Class*              get( const Key& );
    virtual bool                isPresent( const Key& );

public:
    virtual size_t              size()      const;
    virtual typename iterator   begin()     const;
    virtual typename iterator   end()       const;

private:
    Map                         m_cMap;
    Key                 Class::*m_cField;
};

#include "ItemStorage.hpp"

#endif
