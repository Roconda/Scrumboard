//#include "stdafx.h"

#include "UniqueKeyItem.h"

#include <string>
#include <time.h>

template <>
int firstValue<int>()
{
    return int( time(NULL) );
}

template <>
std::string firstValue<std::string>()
{
    return "a";
}

template <>
int nextValue<int>( const int& nLastValue )
{
    return nLastValue + 1;
}

template <>
std::string nextValue<std::string>( const std::string& sLastValue )
{
    return sLastValue + "z";
}
