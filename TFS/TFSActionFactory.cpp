//#include "stdafx.h"

#include "TFSActionFactory.h"
#include "TFSAction.h"
#include "TFSActionDecorator.h"
#include "SocketPackage.h"

#include <assert.h>

TFSActionFactory::TFSActionFactory()
{
}

TFSAction*
TFSActionFactory::create( const char* szDescription )
{
    std::list<std::string>              saID;
    std::list<std::string>::iterator    iList;
    TFSAction                          *pAction = NULL,
                                       *pTemp;

    decompose( szDescription, saID );

    for ( iList=saID.begin(); pAction == NULL && iList!=saID.end(); ++iList )
        pAction = createStrategy( iList->c_str() );

    for ( iList=saID.begin(); iList!=saID.end(); ++iList )
    {
        pTemp   = createDecorator( iList->c_str(), pAction );
        if ( pTemp != NULL )
            pAction = pTemp;
    }

    return pAction;
}

void
TFSActionFactory::process( const char*    szDescription
                         , SocketPackage& cPackageIn
                         , SocketPackage& cPackageOut )
{
    TFSAction  *pAction = create( szDescription );

    if ( pAction != NULL )
    {
        pAction->preprocess( cPackageIn );
        pAction->process( cPackageIn, cPackageOut );
        pAction->postprocess( cPackageOut );

        delete pAction;
    }
}

void
TFSActionFactory::assignStrategy( const char* szID, TFSAction* pAction )
{
    StrategyMap&    cMap    = getStrategyMap();

    assert( szID    != NULL );
    assert( pAction != NULL );
    assert( cMap.find(szID) == cMap.end() );

    cMap[szID]  = pAction;
}

void
TFSActionFactory::assignDecorator( const char* szID, TFSActionDecorator* pAction )
{
    DecoratorMap&   cMap    = getDecoratorMap();

    assert( szID    != NULL );
    assert( pAction != NULL );
    assert( cMap.find(szID) == cMap.end() );

    cMap[szID]  = pAction;
}

TFSAction*
TFSActionFactory::createStrategy( const char* szID )
{
    StrategyMap&            cMap    = getStrategyMap();
    StrategyMap::iterator   iFind   = cMap.find( szID == NULL ? "" : szID );

    if ( iFind == cMap.end() )
        return NULL;
    else
        return iFind->second->create();
}

TFSAction*
TFSActionFactory::createDecorator( const char* szID, TFSAction* pDecorated )
{
    DecoratorMap&           cMap    = getDecoratorMap();
    DecoratorMap::iterator  iFind   = cMap.find( szID == NULL ? "" : szID );

    if ( iFind == cMap.end() )
        return NULL;
    else
        return iFind->second->create( pDecorated );
}

TFSActionFactory::StrategyMap&
TFSActionFactory::getStrategyMap()
{
    static  StrategyMap     cMap;
    return cMap;
}

TFSActionFactory::DecoratorMap&
TFSActionFactory::getDecoratorMap()
{
    static  DecoratorMap    cMap;
    return cMap;
}

void
TFSActionFactory::decompose( const char* szID, std::list<std::string>& saID )
{
    std::string             sID     = szID == NULL ? "" : szID;
    size_t                  nFirst  = sID.find_first_not_of( " " ),
                            nLast   = sID.find_last_not_of( " " );

    saID.clear();

    if ( nFirst != size_t(-1) && nLast != size_t(-1) && nLast >= nFirst )
        sID = sID.substr( nFirst, nLast-nFirst+1 );
    else
        sID = "";

    while ( sID.size() > 0 )
    {
        nLast   = sID.find( ' ' );
        if ( nLast == size_t(-1) )
        {
            saID.push_back( sID );

            sID     = "";
        }
        else
        {
            saID.push_back( sID.substr(0,nLast) );

            sID     = sID.substr( nLast+1, sID.size()-nLast-1 );
            nFirst  = sID.find_first_not_of( " " );

            sID     = sID.substr( nFirst, sID.size()-nFirst );
        }
    }
}
