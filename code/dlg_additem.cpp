#include "dlg_additem.h"
#include "ui_dlg_additem.h"
#include "itemSql.h"
#include <QMessageBox>
Dlg_AddItem::Dlg_AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddItem)
{
    ui->setupUi(this);
}

Dlg_AddItem::~Dlg_AddItem()
{
    delete ui;
}


//添加物品
void Dlg_AddItem::on_save_clicked()
{
    ItemInfo message;
    auto ptr = itemSql::getinstance();
    message.name = ui->le_name->text();
    message.info = ui->le_info->text();
    message.phone = ui->le_phone->text();
    message.mail = ui->le_mail->text();
    message.address = ui->le_address->text();
    ptr->addItem(message);
    QMessageBox::information(nullptr,"物品","添加成功");
    this->hide();
}


void Dlg_AddItem::on_cancel_clicked()
{
    this->hide();
}

