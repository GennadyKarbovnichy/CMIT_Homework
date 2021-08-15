#ifndef DOMESSAGERSOCKET_H
#define DOMESSAGERSOCKET_H

#include <QTcpSocket>

namespace cmit {

class DoMessagerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    DoMessagerSocket(qintptr handle,QObject *parent = 0);
    ~DoMessagerSocket();
signals:
    void DoReadyRead(DoMessagerSocket *);
    void DoStateChanged(DoMessagerSocket *, int);
};
}
#endif // DOMESSAGERSOCKET_H
