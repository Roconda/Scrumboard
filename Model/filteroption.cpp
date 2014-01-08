#include "filteroption.h"
#include "filterdecorator.h"

FilterOption::FilterOption(FilterDecorator* component)
{
    this->component = component;
}
