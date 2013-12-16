#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H

#include <QObject>

#include "tfssignalobject.h"

// forward declarations
class Project;
class Sprint;

class TFSWrapper
{
// members
private:
    Project *selectedProject;
    size_t selectedSprint;

// functions
private:
    TFSWrapper();

// members
public:
    TFSSignalObject *testobject;

// functions
public:
   static TFSWrapper& instance()
   {
      static TFSWrapper INSTANCE;
      return INSTANCE;
   }
   Project *getSelectedProject();
   void saveSelectedProject();
   Sprint *setSelectedSprint(size_t index);
   Sprint *getSelectedSprint();
   size_t getSelectedSprintIndex();
};

#endif // TFSWRAPPER_H
