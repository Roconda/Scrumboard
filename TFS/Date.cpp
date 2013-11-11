//#include "stdafx.h"

#include "Date.h"

#include "SocketPackage.h"

Date::Date()
{
    year    = 0;
    month   = 0;
    day     = 0;
}

Date::~Date()
{
}

void
Date::serialize( SocketPackage& cPackage, bool bWriteToStorage )
{
    if ( bWriteToStorage )
    {
        cPackage.add( day );
        cPackage.add( month );
        cPackage.add( year );
    }
    else
    {
        day     = cPackage.getInt();
        month   = cPackage.getInt();
        year    = cPackage.getInt();
    }
}
