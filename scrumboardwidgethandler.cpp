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
#include "TFS/RemainingWorkHistory.h"
#include <QDate>

using std::pair;


TFSWrapper *tfs = TFSWrapper::instance();
bool ScrumboardWidgetHandler::setStatusForSBI(ItemUI *item, LaneUI *lane){
    ScrumboardWidget *scrumboard = dynamic_cast<ScrumboardWidget *>(parent);
    QString laneName = scrumboard->compareLane(lane);
    if(laneName != QString("Undefined")){
        QString itemID = item->getID().remove(0,1);
        SprintBacklogItem* SBIitem = this->getItemForID(itemID.toInt());

        //if SBIitem exist
        if(SBIitem){
            StatusType::ItemStorage::iterator iType;
            for(iType = StatusType::getStorage().begin(); iType != StatusType::getStorage().end(); ++iType){
                pair<std::string, StatusType*> x = *iType;
                StatusType *st = x.second;

                //compare status name from lane with status name from storage
                if(st->getName() == laneName){
                    //Is this drag allowed?
                    if(acceptStatus(SBIitem->getStatus(SBIitem->sizeStatus() -1)->getStatusType()->getName(), laneName)){
                        //if item is doing to done lane
                        if(laneName == "Done"){
                            setItemDone(SBIitem);
                        }

                        Status *status = new Status();
                        status->setStatusType(*st);
                        status->setDay(QDate::currentDate().day());
                        status->setMonth(QDate::currentDate().month());
                        status->setYear(QDate::currentDate().year());
                        SBIitem->addStatus(*status);
                        tfs->saveSelectedProject();
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }else{
        //exception LaneUI name does not exist!
        return false;
    }
}

void ScrumboardWidgetHandler::setItemDone(SprintBacklogItem* SBIitem){
    RemainingWorkHistory *history = new RemainingWorkHistory();
    history->setDay(QDate::currentDate().day());
    history->setMonth(QDate::currentDate().month());
    history->setYear(QDate::currentDate().year());
    SBIitem->addRemainingWorkHistory(*history);
    SBIitem->setRemainingWork(0.0);
    SBIitem->setCompletedWork(SBIitem->getBaselineWork());
}

bool ScrumboardWidgetHandler::acceptStatus(QString currentLane, QString toLane){
    if(currentLane == "Not Started" && toLane == "Started"){
        return true;
    }else if(currentLane == "Started" && toLane == "Not Started"){
        return true;
    }else if(currentLane == "Started" && toLane == "To Verify"){
        return true;
    }else if(currentLane == "To Verify" && toLane == "Done"){
        return true;
    }else if(currentLane == "To Verify" && toLane == "Started"){
        return true;
    }else{
        return false;
    }
}

SprintBacklogItem* ScrumboardWidgetHandler::getItemForID(int id){
    SBIVisitor visitor;
    for(int i = 0; i < tfs->getSelectedSprint()->getWorkItemArray().size(); i++){
        WorkItem *workitem = tfs->getSelectedSprint()->getWorkItem(i);
        if(workitem)
            workitem->accept(visitor);
    }

    vector<SprintBacklogItem*> &SBIlist = visitor.getList();
    for(vector<SprintBacklogItem*>::const_iterator it = SBIlist.begin(); it != SBIlist.end(); ++it){
        SprintBacklogItem *SBIitem = *it;
        if(SBIitem->getWorkItemNumber() == id){
            return SBIitem;
        }
    }

    return NULL;
}
