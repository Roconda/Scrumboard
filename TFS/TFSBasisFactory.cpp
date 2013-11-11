//#include "stdafx.h"

#include "TFSBasisFactory.h"

#include "TFSBasisCreator.h"

#include <assert.h>

TFSBasisFactory::TFSBasisFactory()
{
}

TFSBasisFactory::~TFSBasisFactory()
{
}

void
TFSBasisFactory::add( const TFSBasisCreatorInterface& cCreator )
{
    Map&    cMap    = getMap();

    assert( cMap.find(cCreator.getID()) == cMap.end() );

    cMap[cCreator.getID()]  = &cCreator;
}

TFSBasis*
TFSBasisFactory::create( const char* szID )
{
    const TFSBasisCreatorInterface* pCreator    = get( szID );

    return pCreator == NULL ? NULL : pCreator->create();
}

const TFSBasisCreatorInterface*
TFSBasisFactory::get( const char* szID )
{
    Map&                cMap    = getMap();
    Map::const_iterator cFind   = cMap.find( szID == NULL ? "" : szID );

    if ( cFind == cMap.end() )
        return NULL;
    else
        return cFind->second;
}

TFSBasisFactory::Map&
TFSBasisFactory::getMap()
{
    static  Map cMap;
    return cMap;
}
