#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}


//返回按钮的实现
void Signup::on_btn_back_clicked()
{
    //关闭注册界面，打开登录界面
    Page_login *p = new Page_login;
    p->show();
    this->close();
}


//确认按钮的实现
void Signup::on_btn_confirm_clicked()
{
    sqlite_Init();
    //获取输入的信息（账号、密码、地址、联系电话）
    QString username = ui->le_username->text();
    QString password = ui->le_password->text();
    QString address = ui->le_address->text();
    QString phone = ui->le_phone->text();
    QString sql=QString("insert into username values('%1','%2','%3','%4','%5','%6')")
            .arg(username)
            .arg(password)
            .arg(address)
            .arg(phone)
            .arg("visitor");
    //创建执行语句对象
    QSqlQuery query;
    //判断执行结果
    if(query.exec(sql))
    {
        qDebug()<<"insert into error";
        QMessageBox::information(this,"注册认证","注册失败！");
    }
    else
    {
        qDebug()<<"insert into success";
        query.exec(sql);
        QMessageBox::information(this,"注册认证","注册成功！");
        Page_login *p = new Page_login;
        p->show();
        this->close();
    }

}


