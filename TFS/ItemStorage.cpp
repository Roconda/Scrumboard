//#include "stdafx.h"

#include "ItemStorage.h"

ItemStorageBase::ItemStorageBase()
{
}

ItemStorageBase::~ItemStorageBase()
{
    ItemStorageSet             &cSet    = getStorageContainer();
    ItemStorageSet::iterator    iSet;

    for ( iSet=cSet.begin(); iSet!=cSet.end(); ++iSet )
    {
        ItemStorageBase* pStorage   = *iSet;

        pStorage->removeAll();
    }
}

ItemStorageBase::ItemStorageSet&
ItemStorageBase::getStorageContainer()
{
    static ItemStorageSet   cSet;

    return cSet;
}

void
ItemStorageBase::emptyContainers()
{
    ItemStorageSet             &cSet    = getStorageContainer();
    ItemStorageSet::iterator    iSet;

    for ( iSet=cSet.begin(); iSet!=cSet.end(); ++iSet )
    {
        ItemStorageBase* pStorage   = *iSet;

        pStorage->removeAll();
    }
}

void
ItemStorageBase::removeContainers()
{
    static  bool                bFirst  = true;
    ItemStorageSet             &cSet    = getStorageContainer();
    ItemStorageSet::iterator    iSet;

    if ( bFirst )
    {
        bFirst  = false;

        for ( iSet=cSet.begin(); iSet!=cSet.end(); )
        {
            ItemStorageBase* pStorage   = *iSet;
            ++iSet;

            delete pStorage;
        }

        cSet.clear();
    }
}
