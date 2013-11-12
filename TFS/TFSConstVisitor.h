#ifndef ___TFSConstVisitor
#define ___TFSConstVisitor

class Attachment;
class Defect;
class ProductBacklogItem;
class Project;
class RemainingWorkHistory;
class Sprint;
class SprintBacklogItem;
class Status;
class StatusType;
class User;
class WorkItem;

class TFSConstVisitor
{
protected:
                    TFSConstVisitor()                       {}

public:
    virtual        ~TFSConstVisitor()                       {}

public:
    virtual void    visit( const Attachment& )              {}
    virtual void    visit( const Defect& )                  {}
    virtual void    visit( const ProductBacklogItem& )      {}
    virtual void    visit( const Project& )                 {}
    virtual void    visit( const RemainingWorkHistory& )    {}
    virtual void    visit( const Sprint& )                  {}
    virtual void    visit( const SprintBacklogItem& )       {}
    virtual void    visit( const Status& )                  {}
    virtual void    visit( const StatusType& )              {}
    virtual void    visit( const User& )                    {}
    virtual void    visit( const WorkItem& )                {}
};

#endif
