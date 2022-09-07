#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QWidget>

class MyTCPServer : public QTcpServer
{
public:
    MyTCPServer();
};

#endif // MYTCPSERVER_H