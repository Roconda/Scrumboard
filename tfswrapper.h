#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H
#include "TFS/User.h"

// forward declarations
class Project;
class Sprint;


class TFSWrapper
{
// members
private:
    Project *selectedProject;
    size_t selectedSprint;
    User* selectedUser;

// functions
private:
    TFSWrapper();

// members
public:

// functions
public:
   static TFSWrapper& instance()
   {
      static TFSWrapper INSTANCE;
      return INSTANCE;
   }
   Project* getSelectedProject();
   void saveSelectedProject();
   Sprint* setSelectedSprint(size_t index);
   Sprint* getSelectedSprint();
   size_t getSelectedSprintIndex();
   User* getSelectedUser();
};

#endif // TFSWRAPPER_H
