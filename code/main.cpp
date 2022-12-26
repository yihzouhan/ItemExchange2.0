#include "mainwindow.h"
#include "page_login.h"
#include <QApplication>
#include "itemSql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    itemSql sql;

    return a.exec();
}
