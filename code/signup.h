#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "page_login.h"
namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    //注册界面-返回按钮
    void on_btn_back_clicked();

    //注册界面-确认按钮
    void on_btn_confirm_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
