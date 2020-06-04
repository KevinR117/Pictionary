#include <QApplication>

#include "clientmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication *app_pictionary = new QApplication(argc, argv);

    ClientMainWindow *mainWindow = new ClientMainWindow();
    mainWindow->show();

    return app_pictionary->exec();
}

