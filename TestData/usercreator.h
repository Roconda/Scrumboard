#ifndef USERCREATOR_H
#define USERCREATOR_H

#include "../TFS/User.h"

#include <vector>
using std::vector;

class UserCreator
{
public:
    UserCreator();
    vector<User*> Create();
};

#endif // USERCREATOR_H
