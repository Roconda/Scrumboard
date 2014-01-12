#include "filteroption.h"

FilterOption::FilterOption(FilterDecorator *component, QString phrase)
{
    this->component = component;
    this->phrase = phrase;
}
