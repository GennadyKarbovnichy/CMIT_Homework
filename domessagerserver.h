#ifndef DOMESSAGERSERVER_H
#define DOMESSAGERSERVER_H

#include <QTcpServer>

namespace cmit {

class doMessagerSocket;

class doMessagerServer : QTcpServer
{
public:
    doMessagerServer(QObject *parent = 0);
    ~doMessagerServer();
    bool startserver(qint16 port);
protected:
    void incomingConnection(qintptr handle);
private:
    QList<doMessagerSocket *> mSockets;
};
}

#endif // DOMESSAGERSERVER_H
