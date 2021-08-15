#include "domessagersocket.h"

namespace cmit {
DoMessagerSocket::DoMessagerSocket(qintptr handle, QObject *parent)
    : QTcpSocket(parent)
{
    setSocketDescriptor(handle);

    connect(this, &DoMessagerSocket::readyRead, [&]() {
        emit DoReadyRead(this);
    });

    connect(this, &DoMessagerSocket::stateChanged, [&](int S) {
        emit DoStateChanged(this, S);
    });
}

DoMessagerSocket::~DoMessagerSocket()
{

}
}
