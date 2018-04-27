#include <QApplication>
#include <QtWidgets>
#include "mainwindows.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindows window;
    window.setGeometry(100,100,800,800);
    window.show();
//    QString status = QString("%1").arg(*argv);
//    QMessageBox msgBox;
//    msgBox.setText(status);
//    msgBox.exec();
    return app.exec();
}
