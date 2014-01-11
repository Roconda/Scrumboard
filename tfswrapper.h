#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H

#include <QObject>
#include <vector>

// forward declarations
class Project;
class ProductBacklogItem;
class User;
class Sprint;

class TFSWrapper : public QObject
{
    Q_OBJECT

// members
private:
    Project *selectedProject;
    size_t selectedSprint;
    size_t selectedPBI;
    User* selectedUser;

// functions
private:
    TFSWrapper(QObject *parent = 0);
    TFSWrapper(TFSWrapper const&);
    void operator=(TFSWrapper const&);
    static const char* SELECTED_PROJECT;

// functions
public:
   static TFSWrapper& instance()
   {
      static TFSWrapper INSTANCE;
      return INSTANCE;
   }
   /* project */
   Project* getSelectedProject();
   void saveSelectedProject();
   /* sprint */
   Sprint* setSelectedSprint(size_t index);
   Sprint* getSelectedSprint();
   size_t getSelectedSprintIndex();
   /* user */
   User* getSelectedUser();
   size_t getSelectedUserIndex();
   User *setSelectedUser(size_t index);
   std::vector<User*> getAllUsers();
   /* PBI */
   ProductBacklogItem *setSelectedPBI(size_t pbi);
   ProductBacklogItem *getSelectedPBI();
   size_t getSelectedPBIIndex();

// QT signals!
signals:
    void remoteTFSDataChanged();
};

#endif // TFSWRAPPER_H
