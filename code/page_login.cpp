#include "page_login.h"
#include "ui_page_login.h"
#include "itemSql.h"
#include <QMessageBox>
#include "signal.h"
Page_login::Page_login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page_login)
{
    ui->setupUi(this);
}

Page_login::~Page_login()
{
    delete ui;
}

//登录按钮的实现
void Page_login::on_btn_login_clicked()
{

    //sqlite_Init();
    //获取账号
    QString username = ui->le_count->text();
    //获取密码
    QString password = ui->le_password->text();
    //判断账号密码是否为空，为空则提示不能为空
    if(username=="")
    {
        QMessageBox::warning(this,"","用户名不能为空");
    }
    else if (password=="")
    {
        QMessageBox::warning(this,"","密码不能为空");
    }
    //判断账号密码是否匹配
    else
    {
    QString sql=QString("select * from username where username='%1' and password='%2'")
            .arg(username).arg(password);
    QSqlQuery query(sql);
    //账号密码匹配失败
    if(query.next())
       {
           qDebug()<<"Login error";
           QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
       }
    //账号密码匹配成功
     else
     {
         qDebug()<<"Login success";
         QMessageBox::information(this,"登录认证","登录成功");
         //登录成功后可以跳转到主页面
         this->close();
         emit sendLoginSuccess();
     }


    }

}

//注册按钮的实现
void Page_login::on_btn_register_clicked()
{
    //关闭登录界面，打开注册界面
    this->close();
    Signup *s = new Signup;
    s->show();
}


//连接数据库（初始化）的实现
void sqlite_Init()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("username.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    //创建登录列表
    QString createsql=QString("create table if not exists username(id integer primary key autoincrement,"
                        "username ntext unique not NULL,"
                        "password ntext not NULL)");
    QSqlQuery query;
    if(!query.exec(createsql)){
        qDebug()<<"table create error";
    }
    else{
        qDebug()<<"table create success";
    }
}
