#ifndef TFSSIGNALOBJECT_H
#define TFSSIGNALOBJECT_H

#include <QObject>

class TFSSignalObject : public QObject
{
    Q_OBJECT

public:
    explicit TFSSignalObject(QObject *parent = 0);

signals:
    void remoteTFSDataChanged();

public slots:

};

#endif // TFSSIGNALOBJECT_H
