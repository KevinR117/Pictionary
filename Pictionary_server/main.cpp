#include <QApplication>

#include "serverwindow.h"

int main(int argc, char *argv[])
{
    QApplication *app_server = new QApplication(argc, argv);

    ServerWindow *serverStateWindow = new ServerWindow();
    serverStateWindow->show();

    return app_server->exec();
}
