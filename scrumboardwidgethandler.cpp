#include "scrumboardwidgethandler.h"
#include "tfswrapper.h"
#include "View/scrumboardwidget.h"
#include "TFS/Sprint.h"
#include "TFS/SprintBacklogItem.h"
#include "TFS/TFSVisitor.h"
#include "Visitors/SBIVisitor.h"
#include "TFS/WorkItem.h"
#include "TFS/Status.h"
#include "TFS/StatusType.h"
#include "TFS/Project.h"
using std::pair;


TFSWrapper tfs = TFSWrapper::instance();
QWidget *ScrumboardWidgetHandler::parent;
ScrumboardWidgetHandler::ScrumboardWidgetHandler(QWidget *parent){
    this->parent = parent;
}

void ScrumboardWidgetHandler::setStatusForSBI(ItemUI *item, LaneUI *lane){
    ScrumboardWidget *scrumboard = dynamic_cast<ScrumboardWidget *>(parent);
    QString laneName = scrumboard->compareLane(lane);
    if(laneName != QString("Undefined")){
        SBIVisitor visitor;
        for(int i = 0; i < tfs.getSelectedSprint()->getWorkItemArray().size(); i++){
            WorkItem *workitem = tfs.getSelectedSprint()->getWorkItem(i);
            if(workitem){
                workitem->accept(visitor);
                visitor.visit((SprintBacklogItem &)workitem);
            }
        }
        vector<SprintBacklogItem*> *SBIlist = &visitor.getList();
        for(vector<SprintBacklogItem*>::const_iterator it = SBIlist->begin(); it != SBIlist->end(); ++it){
            SprintBacklogItem *SBIitem = *it._Ptr;
            if(SBIitem->getWorkItemNumber() == item->getID().toInt()){
                Status *status = new Status();
                StatusType::ItemStorage::iterator iType;
                for(iType = StatusType::getStorage().begin(); iType != StatusType::getStorage().end(); ++iType){
                    pair<std::string, StatusType*> x = *iType;
                    StatusType *st = x.second;
                    if(st->getName() == laneName){
                        status->setStatusType(*st);
                        SBIitem->addStatus(*status);
                    }
                }
            }
        }

    }else{
        //exception
    }
}
