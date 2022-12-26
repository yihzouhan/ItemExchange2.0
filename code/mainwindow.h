#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page_login.h"
#include "itemSql.h"
#include <dlg_additem.h>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //主界面-退出按钮
    void on_exit_clicked();

    //主界面-增加物品按钮
    void on_btn_add_clicked();

    //主界面-更新物品列表按钮
    void updataTable();

    //主界面-删除物品按钮
    void on_btn_del_clicked();

    //主界面-搜索按钮
    void on_btn_search_clicked();

private:
    Ui::MainWindow *ui;
    Page_login m_dlgLogin;
    itemSql *m_ptrItemSql;
    QStringList m_lItem;
    Dlg_AddItem m_dlgAddItem;
};



#endif // MAINWINDOW_H
