#include "domessagerserver.h"
#include "domessagersocket.h"
#include <QTextStream>
#include <QDebug>

namespace cmit {
doMessagerServer::doMessagerServer(QObject *parent)
    : QTcpServer(parent)
{

}

doMessagerServer::~doMessagerServer()
{

}

bool doMessagerServer::startserver(qint16 port) {
    return listen(QHostAddress::Any, port);
}

void doMessagerServer::incomingConnection(qintptr handle)
{
    auto socket = new DoMessagerSocket(handle, this);
    mSockets << socket;

    connect(socket, &DoMessagerSocket::DoReadyRead, [&](DoMessagerSocket *S) {
        qDebug() << "DoReadyRead";
        QTextStream T(S);
        auto text = T.readAll();

        for(auto i : mSockets) {
            QTextStream K(i);
            K << text;
            i->flush();
        }
    });

    connect(socket, &DoMessagerSocket::DoStateChanged, [&](DoMessagerSocket *S, int ST) {
        qDebug() << "DoStateChanged";
        if(ST == QTcpSocket::UnconnectedState) {
            mSockets.removeOne(S);
            for(auto i : mSockets) {
                qDebug() << "Unconnected state";
                QTextStream K(i);
                K << "Сервер: клиент" << S->socketDescriptor() << "был отключен...";
                i->flush();
            }
        }
    });
}
}
