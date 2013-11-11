//#include "stdafx.h"

#include "TFSAction.h"
#include "TFSActionFactory.h"

TFSAction::TFSAction( const char* szID )
{
    TFSActionFactory::assignStrategy( szID, this );
}

TFSAction::TFSAction()
{
}

TFSAction::~TFSAction()
{
}
