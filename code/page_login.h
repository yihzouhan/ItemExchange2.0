#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include "itemSql.h"
#include "signup.h"

//连接数据库（初始化）
void sqlite_Init();

namespace Ui {
class Page_login;
}

class Page_login : public QWidget
{
    Q_OBJECT

public:
    explicit Page_login(QWidget *parent = nullptr);
    ~Page_login();

private slots:
    //登录界面-登录按钮
    void on_btn_login_clicked();

    //登录界面-注册按钮
    void on_btn_register_clicked();

signals:
    //成功登录，跳转到主页面
    void sendLoginSuccess();

private:
    Ui::Page_login *ui;
};

#endif // PAGE_LOGIN_H
