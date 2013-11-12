#ifndef ___TFSVisitor
#define ___TFSVisitor

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

class TFSVisitor
{
protected:
                    TFSVisitor()                    {}

public:
    virtual        ~TFSVisitor()                    {}

public:
    virtual void    visit( Attachment& )            {}
    virtual void    visit( Defect& )                {}
    virtual void    visit( ProductBacklogItem& )    {}
    virtual void    visit( Project& )               {}
    virtual void    visit( RemainingWorkHistory& )  {}
    virtual void    visit( Sprint& )                {}
    virtual void    visit( SprintBacklogItem& )     {}
    virtual void    visit( Status& )                {}
    virtual void    visit( StatusType& )            {}
    virtual void    visit( User& )                  {}
    virtual void    visit( WorkItem& )              {}
};

#endif
