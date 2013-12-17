#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H

#include <QObject>

#include "tfssignalobject.h"

// forward declarations
class Project;
class SprintBacklogItem;
class User;
class Sprint;

class TFSWrapper
{
// members
private:
    Project *selectedProject;
    size_t selectedSprint;
    SprintBacklogItem* selectedSBI;
    User* selectedUser;

// functions
private:
    TFSWrapper();

// members
public:
    TFSSignalObject *signalObject;

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
   void setSelectedSBI(SprintBacklogItem *backlogitem);
   SprintBacklogItem *getSelectedSBI();
   std::vector<User*> getAllUsers();
};

#endif // TFSWRAPPER_H
