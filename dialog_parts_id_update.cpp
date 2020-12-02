// 31/05/2019
#include "dialog_parts_id_update.h"
#include "ui_dialog_parts_id_update.h"

#include "mainwindow.h"

Dialog_parts_id_update::Dialog_parts_id_update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_parts_id_update)
{
    ui->setupUi(this);
}

Dialog_parts_id_update::~Dialog_parts_id_update()
{
    delete ui;
}

void Dialog_parts_id_update::display_parts_id_selected(QString ColumnName, QString CellData, QString PartIdNumber){

    //qDebug() << "Affichage dans display_part_id_selected" << ColumnName << CellData;

    ui->label->setText(ColumnName);
    ui->lineEdit->setText(CellData);
    ui->label_3->setText(PartIdNumber);
}

void Dialog_parts_id_update::on_buttonBox_accepted()
{
    notify_DatabaseToUpdate(ui->lineEdit->text());
    accept();
}
