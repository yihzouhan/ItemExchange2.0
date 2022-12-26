#include "itemSql.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include<QSqlQuery>
#include <QtSql>
#include <QtDebug>
#include <QApplication>
itemSql * itemSql::ptritemSql = nullptr;
itemSql::itemSql(QObject *parent) : QObject(parent)
{

}

//初始化
void itemSql::init()
{
    if (QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
//应用程序的文件位置
#if 0
    auto str = QApplication::applicationDirPath()+"data.db";
    qDebug()<<str;
#endif
    m_db.setDatabaseName("D:\\data.db");
    if (!m_db.open())
        qDebug()<<"db not open";
}


//物品总数实现
quint32 itemSql::getItemCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from item;");
    quint32 uiCnt = 0;
    while(sql.next())
    {
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

//查询第几页数据（从第0页开始）
QList<ItemInfo> itemSql::getPageItem(quint32 page, quint32 uiCnt)
{
    QList<ItemInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from item order by id limit %1 offset %2").
            arg(uiCnt).arg(page*uiCnt);
    sql.exec(strsql);

    ItemInfo message;
    while(sql.next())
    {
        message.id = sql.value(0).toUInt();
        message.name = sql.value(1).toString();
        message.info = sql.value(2).toString();
        message.address = sql.value(3).toString();
        message.phone = sql.value(4).toString();
        message.mail = sql.value(5).toString();
        l.push_back(message);
    }
    return l;
}


//增加物品实现
bool itemSql::addItem(ItemInfo message)
{
     QSqlQuery sql(m_db);
     //获取物品输入的信息
     QString strSql=QString("insert into item values(null,'%1','%2','%3','%4','%5')").
             arg(message.name).
             arg(message.info).
             arg(message.address).
             arg(message.phone).
             arg(message.mail);
     return sql.exec(strSql);
}

//删除物品
bool itemSql::delItem(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from item where id = %1").arg(id));
}


//清空实现
bool itemSql::clearItemTable()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from item");
    return sql.exec("delete from sqlite_sequence where name = 'item' ");
}


//查询所有用户实现
QList<UserInfo> itemSql::getAllUser()
{
    QList<UserInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from username");

    UserInfo info;
    while(sql.next())
    {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.address = sql.value(2).toString();
        info.phone = sql.value(3).toString();
        info.aut = sql.value(4).toString();
        l.push_back(info);
    }
    return l;
}

//查询用户名是否存在实现
bool itemSql::isExit(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select *from username where username = '%1'").arg(strUser));
    //bool ret = false;
    return sql.next();
}



//添加单个用户实现
bool itemSql::AddUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql=QString("insert into username values('%1','%2','%3')").
            arg(info.username).
            arg(info.password).
            arg(info.aut);
    return sql.exec(strSql);
}


