//#include "stdafx.h"

#include "TFSActionDecorator.h"

#include "TFSActionFactory.h"

TFSActionDecorator::TFSActionDecorator( const char* szID )
    : TFSAction()
    , m_pDecorated( NULL )
{
    TFSActionFactory::assignDecorator( szID, this );
}

TFSActionDecorator::TFSActionDecorator( TFSAction* pDecorated )
    : TFSAction()
    , m_pDecorated( pDecorated )
{
}

TFSActionDecorator::~TFSActionDecorator()
{
    delete m_pDecorated;
}

bool
TFSActionDecorator::preprocess( SocketPackage& cPackageIn )
{
    if ( m_pDecorated == NULL )
        return true;
    else
        return m_pDecorated->preprocess( cPackageIn );
}

bool
TFSActionDecorator::process( SocketPackage& cPackageIn
                           , SocketPackage& cPackageOut )
{
    if ( m_pDecorated == NULL )
        return true;
    else
        return m_pDecorated->process( cPackageIn, cPackageOut );
}

bool
TFSActionDecorator::postprocess( SocketPackage& cPackageOut )
{
    if ( m_pDecorated == NULL )
        return true;
    else
        return m_pDecorated->postprocess( cPackageOut );
}

TFSAction*
TFSActionDecorator::create() const
{
    return NULL;
}
