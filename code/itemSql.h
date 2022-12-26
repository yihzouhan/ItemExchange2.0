#ifndef ITEMSQL_H
#define ITEMSQL_H
#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>

//物品信息
struct ItemInfo
{
    int id;
    QString name;
    QString info;
    QString address;
    QString phone;
    QString mail;

};

//用户信息
struct UserInfo
{
    QString username;
    QString password;
    QString address;
    QString phone;
    QString aut;
};

class itemSql : public QObject
{
    Q_OBJECT
public:
    static itemSql *ptritemSql;
    static itemSql *getinstance()
    {
        if(nullptr == ptritemSql)
        {
            ptritemSql = new itemSql;
        }
        return ptritemSql;
    }

    explicit itemSql(QObject *parent = nullptr);

    //数据库连接初始化
    void init();

    //物品总数
    quint32 getItemCnt();

    //查询第几页数据
    QList<ItemInfo> getPageItem(quint32 page,quint32 uiCnt);

    //增加物品
    bool addItem(ItemInfo);

    //删除物品
    bool delItem(int id);

    //清空
    bool clearItemTable();


    //查询所有用户
    QList<UserInfo> getAllUser();

    //查询用户名是否存在
    bool isExit(QString strUser);

    //修改用户权限
    void changeuserAut(QString str);

    //添加单个用户
    bool AddUser(UserInfo info);
signals:
private:
    QSqlDatabase m_db;
};


#endif // ITEMSQL_H
