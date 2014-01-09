#include "adddefect.h"
#include "ui_adddefect.h"
#include "../TFS/Defect.h"
#include "../tfswrapper.h"
#include "../TFS/Status.h"
#include "../TFS/StatusType.h"
#include "../TFS/User.h"
#include "../TFS/Sprint.h"
#include "../TFS/SprintBacklogItem.h"
#include "../Visitors/sbivisitor.h"
#include "../scrumboardwidgethandler.h"
#include "qmessagebox.h"
#include <QDate>

using std::pair;

AddDefect::AddDefect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDefect)
{
    ui->setupUi(this);

    //-----------fill users combobox---------
    std::vector<User*> users;
    users = TFSWrapper::instance().getAllUsers();
    foreach(User* user, users){
        ui->user->addItem(user->getName());
    }
    //---------------------------------------

    //-----------fill SBI combobox-----------
    SBIVisitor visitor;
    for(int i = 0; i < TFSWrapper::instance().getSelectedSprint()->getWorkItemArray().size(); i++){
        WorkItem *workitem = TFSWrapper::instance().getSelectedSprint()->getWorkItem(i);
        if(workitem)
            workitem->accept(visitor);
    }

    vector<SprintBacklogItem*> &SBIlist = visitor.getList();
    for(vector<SprintBacklogItem*>::const_iterator it = SBIlist.begin(); it != SBIlist.end(); ++it){
        SprintBacklogItem *SBIitem = *it;
        QString name = QString::number(SBIitem->getWorkItemNumber());
        name.append(": ");
        name.append(SBIitem->getTitle());
        ui->SBI->addItem(name);
    }
    //---------------------------------------
}

AddDefect::~AddDefect()
{
    delete ui;
}

void AddDefect::accept(){
    if(this->save()){
        this->destroy();
        ScrumboardWidgetHandler::getInstance().updateScrumboard();
    }
}

void AddDefect::reject(){
    this->destroy();
}

/**
 * @brief create a defect using the data entered
 * @return boolean succeeded or not
 */
bool AddDefect::save(){
    QString *var1, *var2;
    var1 = &ui->DefectTitle->text();
    var2 = &ui->DefectDescription->toPlainText();

    //check if all fields are filled correctly
    if(var1->isEmpty() || var2->isEmpty()){
        QMessageBox *box = new QMessageBox(this);
        box->setText("Niet alles is ingevuld!");
        box->exec();
        return false;
    }


    //start creating the defect
    Defect* defect = new Defect();

    //set title
    QByteArray title = var1->toUtf8();
    defect->setTitle(title.constData());

    //set description
    QByteArray description = var2->toUtf8();
    defect->setDescription(description.constData());

    //add status
    Status* status = new Status();

    StatusType::ItemStorage::iterator iType;
    for(iType = StatusType::getStorage().begin(); iType != StatusType::getStorage().end(); ++iType){
        pair<std::string, StatusType*> x = *iType;
        StatusType *st = x.second;
        if(st->getName() == QString("Not Started")){
            status->setStatusType(*st);
            status->setDay(QDate::currentDate().day());
            status->setMonth(QDate::currentDate().month());
            status->setYear(QDate::currentDate().year());
            break;
        }
    }

    defect->addStatus(*status);

    //set user
    std::vector<User*> users;
    users = TFSWrapper::instance().getAllUsers();
    foreach(User* user, users){
        if(user->getName() == ui->user->currentText()){
            defect->setUser(user);
            break;
        }
    }

    //workitem number
    defect->setWorkItemNumber(100);

    //add defect to list from selected SBI
    QString selected = ui->SBI->currentText();
    QStringList split = selected.split(":");
    int workitemnumber = split.at(0).toInt();
    SprintBacklogItem* item = static_cast<SprintBacklogItem*>(TFSWrapper::instance().getSelectedSprint()->getWorkItem(workitemnumber));
    TFSWrapper::instance().getSelectedSprint()->addWorkItem(*defect);
    item->addDefect(*defect);
    TFSWrapper::instance().saveSelectedProject();

    return true;
}
