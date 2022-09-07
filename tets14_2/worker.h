#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QWidget>

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WORKER_H