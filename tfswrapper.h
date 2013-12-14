#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H
#include "TFS/User.h"

#include <QObject>

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
    TFSWrapper(const TFSWrapper &other);
    TFSWrapper &operator=(const TFSWrapper &other);

// members
public:

// functions
public:
   static TFSWrapper* instance()
   {
       static TFSWrapper *INSTANCE = new TFSWrapper;
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
