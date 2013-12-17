#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H

#include <QObject>
#include <vector>

// forward declarations
class Project;
class SprintBacklogItem;
class User;
class Sprint;

class TFSWrapper : public QObject
{
    Q_OBJECT

// members
private:
    Project *selectedProject;
    size_t selectedSprint;
    SprintBacklogItem* selectedSBI;
    User* selectedUser;

// functions
private:
    TFSWrapper(QObject *parent = 0);
    TFSWrapper(TFSWrapper const&);
    void operator=(TFSWrapper const&);

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

// QT signals!
signals:
    void remoteTFSDataChanged();
};

#endif // TFSWRAPPER_H
