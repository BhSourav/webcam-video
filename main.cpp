#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->setAttribute(Qt::WA_DeleteOnClose, true);

    cout<< "working till now 1"<<endl;

    w->show();

    cout<< "working till now 2"<<endl;

    return a.exec();
}
