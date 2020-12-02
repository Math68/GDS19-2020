// 31/05/2019
#include "dialog_parts_id_delete.h"
#include "ui_dialog_parts_id_delete.h"

Dialog_parts_id_delete::Dialog_parts_id_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_parts_id_delete)
{
    ui->setupUi(this);
}

Dialog_parts_id_delete::~Dialog_parts_id_delete()
{
    delete ui;
}

void Dialog_parts_id_delete::display_parts_id_to_deleted(QString CellData)
{
    ui->label->setText(CellData);
}

void Dialog_parts_id_delete::on_pushButton_2_clicked()
{
    close();
}

void Dialog_parts_id_delete::on_pushButton_clicked()
{
    notify_DatabaseRowToDelete();
    accept();
}
