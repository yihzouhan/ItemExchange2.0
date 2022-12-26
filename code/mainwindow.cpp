#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),m_ptrItemSql(nullptr)
{
    ui->setupUi(this);

    m_dlgLogin.show();
    auto f = [&]
    {
        this->show();
    };
    connect(&m_dlgLogin,&Page_login::sendLoginSuccess,this,f);

    //左侧用户栏
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList l;
    l<<"用户类型";
    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);

    l.clear();
    l<<"管理员";
    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"普通用户";
    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

    pf->addChild(p1);
    pf->addChild(p2);

    //左侧用户栏处于打开状态
    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);

    //获取物品信息数据表
    m_ptrItemSql = itemSql::getinstance();
    m_ptrItemSql->init();
    updataTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//退出按钮实现
void MainWindow::on_exit_clicked()
{
    exit(0);
}

//增加物品按钮实现
void MainWindow::on_btn_add_clicked()
{
    m_dlgAddItem.exec();
    updataTable();

}

//更新数据库
void MainWindow::updataTable()
{

    //设定物品列表表头
    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(1);
    QStringList l;
    l<<"序号"<<"id"<<"物品名称"<<"物品说明"<<"物品所在地址"<<"联系人手机"<<"邮箱";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    //只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //每个选项不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //获取列表中的物品信息
    auto cnt = m_ptrItemSql->getItemCnt();
    QList<ItemInfo> lItem = m_ptrItemSql->getPageItem(0,cnt);

    ui->tableWidget->setRowCount(cnt);
    for(auto i = 0;i<lItem.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lItem[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lItem[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(lItem[i].info));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(lItem[i].address));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(lItem[i].phone));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(lItem[i].mail));
    }

}

//删除按钮实现
void MainWindow::on_btn_del_clicked()
{
    int i = ui->tableWidget->currentRow();
    if(i>=0)
    {
       //获取所选行数
       int id = ui->tableWidget->item(i,1)->text().toUInt();
       m_ptrItemSql->delItem(id);
       //更新列表并提示
       updataTable();
       QMessageBox::information(nullptr,"物品","删除成功");
    }
}

//搜索物品实现
void MainWindow::on_btn_search_clicked()
{
    //表头设置
    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(1);
    QStringList l;
    l<<"序号"<<"id"<<"物品名称"<<"物品说明"<<"物品所在地址"<<"联系人手机"<<"邮箱";
    ui->tableWidget->setHorizontalHeaderLabels(l);

    //获取总的物品数
    auto cnt = m_ptrItemSql->getItemCnt();
    QList<ItemInfo> lItem = m_ptrItemSql->getPageItem(0,cnt);

    //获取关键字
    QString strFilter = ui->le_search->text();
    ui->tableWidget->setRowCount(cnt);
    //相关物品数
    int index = 0;
    for(auto i = 0;i<lItem.size();i++)
    {
        //筛选物品名称和物品说明中包含搜索关键字的选项
        if(!lItem[i].name.contains(strFilter)&&!lItem[i].info.contains(strFilter))
        {
            continue;
        }
        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(lItem[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lItem[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(lItem[i].info));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(lItem[i].address));
        ui->tableWidget->setItem(index,5,new QTableWidgetItem(lItem[i].phone));
        ui->tableWidget->setItem(index,6,new QTableWidgetItem(lItem[i].mail));
        index++;
    }
    //显示搜索结果
    ui->tableWidget->setRowCount(index);
}

