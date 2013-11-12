//#include "stdafx.h"

#include "TFSBasis.h"

#include "SocketPackage.h"
#include "TFSBasisFactory.h"

TFSBasis::TFSBasis()
{
    getStorage().add( this );
}

TFSBasis::~TFSBasis()
{
    getStorage().remove( this );
}

void
TFSBasis::serialize( TFSBasis*& pObject, SocketPackage& cPackage, bool bWriteToStorage )
{
    if ( bWriteToStorage )
    {
        cPackage.add( getClassID(pObject) );

        if ( pObject != NULL )
            pObject->serialize( cPackage, bWriteToStorage );
    }
    else
    {
        std::string sBuffer;
        TFSBasis*   pCopy;

        pObject = TFSBasisFactory::create( cPackage.getString(sBuffer).c_str() );

        if ( pObject != NULL )
        {
            pCopy   = pObject->serialize( cPackage, bWriteToStorage );

            if ( pCopy != pObject )
            {
                if ( TFSBasis::canBeDeleted(pObject) )
                    delete pObject;

                pObject = pCopy;
            }
        }
    }
}

const char*
TFSBasis::getClassID( TFSBasis* pObject )
{
    if ( pObject == NULL )
        return "null";
    else
        return pObject->getClassID();
}

bool
TFSBasis::exists( TFSBasis* pObject )
{
    return pObject != NULL && getStorage().isPresent( pObject );
}

bool
TFSBasis::canBeDeleted( TFSBasis* pObject )
{
    return exists( pObject ) && pObject->storedInHeap();
}

bool
TFSBasis::accept( TFSBasis* pObject, TFSVisitor& cVisitor )
{
    bool    bExists = pObject != NULL && exists( pObject );

    if ( bExists )
        pObject->accept( cVisitor );

    return bExists;
}

bool
TFSBasis::accept( TFSBasis* pObject, TFSConstVisitor& cVisitor )
{
    bool    bExists = pObject != NULL && exists( pObject );

    if ( bExists )
        pObject->accept( cVisitor );

    return bExists;
}

void
TFSBasis::removeAll()
{
    ItemStorageBase::emptyContainers();

    getStorage().removeAll();
}

ItemStorage<TFSBasis>&
TFSBasis::getStorage()
{
    static  ItemStorage<TFSBasis>   cStorage( true );

    return cStorage;
}
