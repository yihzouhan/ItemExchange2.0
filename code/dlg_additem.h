#ifndef DLG_ADDITEM_H
#define DLG_ADDITEM_H

#include <QDialog>

namespace Ui {
class Dlg_AddItem;
}

class Dlg_AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddItem(QWidget *parent = nullptr);
    ~Dlg_AddItem();

private slots:

    void on_save_clicked();

    void on_cancel_clicked();

private:
    Ui::Dlg_AddItem *ui;
};

#endif // DLG_ADDITEM_H
