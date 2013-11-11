//#include "stdafx.h"

// voor abs
#include <stdlib.h>

#include "ObjectStoredInStack.h"

#define LARGE_NUMBER    1000

ObjectStoredInStack::ObjectStoredInStack( bool bStoredOnStack )
    : m_bStoredOnStack( bStoredOnStack )
{
}

ObjectStoredInStack::ObjectStoredInStack()
    : m_bStoredOnStack( setStoredOnStack() )
{
}

ObjectStoredInStack::~ObjectStoredInStack()
{
}

bool
ObjectStoredInStack::storedInHeap() const
{
    return !m_bStoredOnStack;
}

bool
ObjectStoredInStack::storedInStack() const
{
    return m_bStoredOnStack;
}

bool
ObjectStoredInStack::setStoredOnStack() const
{
    ObjectStoredInStack cOnStack( true );

    return abs( this - &cOnStack ) < LARGE_NUMBER;
}
