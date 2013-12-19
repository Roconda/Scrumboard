#include "usercreator.h"

UserCreator::UserCreator()
{
}

vector<User*> UserCreator::Create()
{
    vector<User*> users;

    users.push_back(User::withName("Sander"));
    users.push_back(User::withName("Tim"));
    users.push_back(User::withName("Rick"));
    users.push_back(User::withName("Victor"));
    users.push_back(User::withName("Dustin"));
    users.push_back(User::withName("Christiaan"));

    return users;
}
