#include <QCoreApplication>
#include <domessagerserver.h>

using namespace cmit;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    doMessagerServer server;
    if(!server.startserver(3333)) {
        qDebug() << "Error: " << server.errorString();
        return 1;
    }
    qDebug() << "Server started...";
    return a.exec();
}
