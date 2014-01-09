#include "workhistorycreator.h"

WorkHistoryCreator::WorkHistoryCreator()
{
}

vector<RemainingWorkHistory*> WorkHistoryCreator::Create(vector<SprintBacklogItem *> sbis)
{
    vector<RemainingWorkHistory*> histories;

    RemainingWorkHistory* history1 = new RemainingWorkHistory();
    history1->setDay(5);
    history1->setMonth(12);
    history1->setYear(2013);
    history1->setRemainingWork(10);
    sbis[0]->addRemainingWorkHistory(*history1);
    histories.push_back(history1);

    RemainingWorkHistory* history2 = new RemainingWorkHistory();
    history2->setDay(5);
    history2->setMonth(12);
    history2->setYear(2013);
    history2->setRemainingWork(1);
    sbis[1]->addRemainingWorkHistory(*history2);
    histories.push_back(history2);

    RemainingWorkHistory* history3 = new RemainingWorkHistory();
    history3->setDay(6);
    history3->setMonth(12);
    history3->setYear(2013);
    history3->setRemainingWork(5);
    sbis[1]->addRemainingWorkHistory(*history3);
    histories.push_back(history3);

    RemainingWorkHistory* history4 = new RemainingWorkHistory();
    history4->setDay(6);
    history4->setMonth(12);
    history4->setYear(2013);
    history4->setRemainingWork(2);
    sbis[2]->addRemainingWorkHistory(*history4);
    histories.push_back(history4);

    RemainingWorkHistory* history5 = new RemainingWorkHistory();
    history5->setDay(7);
    history5->setMonth(12);
    history5->setYear(2013);
    history5->setRemainingWork(5);
    sbis[2]->addRemainingWorkHistory(*history5);
    histories.push_back(history5);

    RemainingWorkHistory* history6 = new RemainingWorkHistory();
    history6->setDay(8);
    history6->setMonth(12);
    history6->setYear(2013);
    history6->setRemainingWork(1);
    sbis[3]->addRemainingWorkHistory(*history6);
    histories.push_back(history6);

    RemainingWorkHistory* history7 = new RemainingWorkHistory();
    history7->setDay(10);
    history7->setMonth(12);
    history7->setYear(2013);
    history7->setRemainingWork(1);
    sbis[4]->addRemainingWorkHistory(*history7);
    histories.push_back(history7);

    RemainingWorkHistory* history8 = new RemainingWorkHistory();
    history8->setDay(10);
    history8->setMonth(12);
    history8->setYear(2013);
    history8->setRemainingWork(1);
    sbis[5]->addRemainingWorkHistory(*history8);
    histories.push_back(history8);

    RemainingWorkHistory* history9 = new RemainingWorkHistory();
    history9->setDay(10);
    history9->setMonth(12);
    history9->setYear(2013);
    history9->setRemainingWork(1);
    sbis[6]->addRemainingWorkHistory(*history9);
    histories.push_back(history9);

    RemainingWorkHistory* history10 = new RemainingWorkHistory();
    history10->setDay(10);
    history10->setMonth(12);
    history10->setYear(2013);
    history10->setRemainingWork(1);
    sbis[7]->addRemainingWorkHistory(*history10);
    histories.push_back(history10);

    RemainingWorkHistory* history11 = new RemainingWorkHistory();
    history11->setDay(14);
    history11->setMonth(12);
    history11->setYear(2013);
    history11->setRemainingWork(2);
    sbis[8]->addRemainingWorkHistory(*history11);
    histories.push_back(history11);

    RemainingWorkHistory* history12 = new RemainingWorkHistory();
    history12->setDay(14);
    history12->setMonth(12);
    history12->setYear(2013);
    history12->setRemainingWork(2);
    sbis[9]->addRemainingWorkHistory(*history12);
    histories.push_back(history12);

    RemainingWorkHistory* history13 = new RemainingWorkHistory();
    history13->setDay(16);
    history13->setMonth(12);
    history13->setYear(2013);
    history13->setRemainingWork(5);
    sbis[9]->addRemainingWorkHistory(*history13);
    histories.push_back(history13);

    RemainingWorkHistory* history14 = new RemainingWorkHistory();
    history14->setDay(17);
    history14->setMonth(12);
    history14->setYear(2013);
    history14->setRemainingWork(5);
    sbis[10]->addRemainingWorkHistory(*history14);
    histories.push_back(history14);

    RemainingWorkHistory* history15 = new RemainingWorkHistory();
    history15->setDay(2);
    history15->setMonth(1);
    history15->setYear(2014);
    history15->setRemainingWork(4);
    sbis[11]->addRemainingWorkHistory(*history15);
    histories.push_back(history15);

    RemainingWorkHistory* history16 = new RemainingWorkHistory();
    history16->setDay(4);
    history16->setMonth(1);
    history16->setYear(2014);
    history16->setRemainingWork(4);
    sbis[12]->addRemainingWorkHistory(*history16);
    histories.push_back(history16);

    RemainingWorkHistory* history17 = new RemainingWorkHistory();
    history17->setDay(7);
    history17->setMonth(1);
    history17->setYear(2014);
    history17->setRemainingWork(3);
    sbis[13]->addRemainingWorkHistory(*history17);
    histories.push_back(history17);

    RemainingWorkHistory* history18 = new RemainingWorkHistory();
    history18->setDay(8);
    history18->setMonth(1);
    history18->setYear(2014);
    history18->setRemainingWork(6);
    sbis[13]->addRemainingWorkHistory(*history18);
    histories.push_back(history18);

    RemainingWorkHistory* history19 = new RemainingWorkHistory();
    history19->setDay(9);
    history19->setMonth(1);
    history19->setYear(2014);
    history19->setRemainingWork(10);
    sbis[13]->addRemainingWorkHistory(*history19);
    histories.push_back(history19);

    RemainingWorkHistory* history20 = new RemainingWorkHistory();
    history20->setDay(12);
    history20->setMonth(1);
    history20->setYear(2014);
    history20->setRemainingWork(1);
    sbis[14]->addRemainingWorkHistory(*history20);
    histories.push_back(history20);

    RemainingWorkHistory* history21 = new RemainingWorkHistory();
    history21->setDay(13);
    history21->setMonth(1);
    history21->setYear(2014);
    history21->setRemainingWork(3);
    sbis[14]->addRemainingWorkHistory(*history21);
    histories.push_back(history21);

    RemainingWorkHistory* history22 = new RemainingWorkHistory();
    history22->setDay(13);
    history22->setMonth(1);
    history22->setYear(2014);
    history22->setRemainingWork(8);
    sbis[15]->addRemainingWorkHistory(*history22);
    histories.push_back(history22);

    RemainingWorkHistory* history23 = new RemainingWorkHistory();
    history23->setDay(14);
    history23->setMonth(1);
    history23->setYear(2014);
    history23->setRemainingWork(16);
    sbis[15]->addRemainingWorkHistory(*history23);
    histories.push_back(history23);

    RemainingWorkHistory* history24 = new RemainingWorkHistory();
    history24->setDay(15);
    history24->setMonth(1);
    history24->setYear(2014);
    history24->setRemainingWork(20);
    sbis[15]->addRemainingWorkHistory(*history24);
    histories.push_back(history24);

    RemainingWorkHistory* history25 = new RemainingWorkHistory();
    history25->setDay(16);
    history25->setMonth(1);
    history25->setYear(2014);
    history25->setRemainingWork(8);
    sbis[16]->addRemainingWorkHistory(*history25);
    histories.push_back(history25);

    RemainingWorkHistory* history26 = new RemainingWorkHistory();
    history26->setDay(20);
    history26->setMonth(1);
    history26->setYear(2014);
    history26->setRemainingWork(10);
    sbis[16]->addRemainingWorkHistory(*history26);
    histories.push_back(history26);

    RemainingWorkHistory* history27 = new RemainingWorkHistory();
    history27->setDay(22);
    history27->setMonth(1);
    history27->setYear(2014);
    history27->setRemainingWork(1);
    sbis[17]->addRemainingWorkHistory(*history27);
    histories.push_back(history27);

    RemainingWorkHistory* history28 = new RemainingWorkHistory();
    history28->setDay(23);
    history28->setMonth(1);
    history28->setYear(2014);
    history28->setRemainingWork(5);
    sbis[17]->addRemainingWorkHistory(*history28);
    histories.push_back(history28);

    RemainingWorkHistory* history29 = new RemainingWorkHistory();
    history29->setDay(1);
    history29->setMonth(2);
    history29->setYear(2014);
    history29->setRemainingWork(3);
    sbis[18]->addRemainingWorkHistory(*history29);
    histories.push_back(history29);

    RemainingWorkHistory* history30 = new RemainingWorkHistory();
    history30->setDay(3);
    history30->setMonth(2);
    history30->setYear(2014);
    history30->setRemainingWork(10);
    sbis[18]->addRemainingWorkHistory(*history30);
    histories.push_back(history30);

    RemainingWorkHistory* history31 = new RemainingWorkHistory();
    history31->setDay(10);
    history31->setMonth(2);
    history31->setYear(2014);
    history31->setRemainingWork(10);
    sbis[19]->addRemainingWorkHistory(*history31);
    histories.push_back(history31);

    RemainingWorkHistory* history32 = new RemainingWorkHistory();
    history32->setDay(13);
    history32->setMonth(2);
    history32->setYear(2014);
    history32->setRemainingWork(10);
    sbis[19]->addRemainingWorkHistory(*history32);
    histories.push_back(history32);

    RemainingWorkHistory* history33 = new RemainingWorkHistory();
    history33->setDay(18);
    history33->setMonth(2);
    history33->setYear(2014);
    history33->setRemainingWork(5);
    sbis[20]->addRemainingWorkHistory(*history33);
    histories.push_back(history33);

    RemainingWorkHistory* history34 = new RemainingWorkHistory();
    history34->setDay(22);
    history34->setMonth(2);
    history34->setYear(2014);
    history34->setRemainingWork(10);
    sbis[20]->addRemainingWorkHistory(*history34);
    histories.push_back(history34);

    RemainingWorkHistory* history35 = new RemainingWorkHistory();
    history35->setDay(25);
    history35->setMonth(2);
    history35->setYear(2014);
    history35->setRemainingWork(5);
    sbis[21]->addRemainingWorkHistory(*history35);
    histories.push_back(history35);

    RemainingWorkHistory* history36 = new RemainingWorkHistory();
    history36->setDay(28);
    history36->setMonth(2);
    history36->setYear(2014);
    history36->setRemainingWork(4);
    sbis[22]->addRemainingWorkHistory(*history36);
    histories.push_back(history36);

    RemainingWorkHistory* history37 = new RemainingWorkHistory();
    history37->setDay(1);
    history37->setMonth(3);
    history37->setYear(2014);
    history37->setRemainingWork(10);
    sbis[22]->addRemainingWorkHistory(*history37);
    histories.push_back(history37);

    RemainingWorkHistory* history38 = new RemainingWorkHistory();
    history38->setDay(1);
    history38->setMonth(3);
    history38->setYear(2014);
    history38->setRemainingWork(5);
    sbis[23]->addRemainingWorkHistory(*history38);
    histories.push_back(history38);

    RemainingWorkHistory* history39 = new RemainingWorkHistory();
    history39->setDay(3);
    history39->setMonth(3);
    history39->setYear(2014);
    history39->setRemainingWork(15);
    sbis[23]->addRemainingWorkHistory(*history39);
    histories.push_back(history39);

    return histories;
}
