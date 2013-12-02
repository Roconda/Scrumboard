#ifndef TFSWRAPPER_H
#define TFSWRAPPER_H

class Project;


class TFSWrapper
{
private:
    Project *selectedProject;
    TFSWrapper();
public:
   static TFSWrapper& instance()
   {
      static TFSWrapper INSTANCE;
      return INSTANCE;
   }
   Project *getSelectedProject();
   void SaveSelectedProject();
};

#endif // TFSWRAPPER_H
