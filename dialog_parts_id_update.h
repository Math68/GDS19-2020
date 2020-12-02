// 31/05/2019
#ifndef DIALOG_PARTS_ID_UPDATE_H
#define DIALOG_PARTS_ID_UPDATE_H

#include <QMessageBox>
#include <QDialog>

#include "dataBase.h"

namespace Ui {
class Dialog_parts_id_update;
}

class Dialog_parts_id_update : public QDialog
{
    Q_OBJECT

public:
    DataBase PartsId_Database;

    explicit Dialog_parts_id_update(QWidget *parent = nullptr);
    ~Dialog_parts_id_update();

public slots:
    void display_parts_id_selected(QString ColumnName, QString CellData, QString PartIdNumber);

signals:
    void notify_DatabaseToUpdate(QString NewCellValue);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_parts_id_update *ui;
};

#endif // DIALOG_PARTS_ID_UPDATE_H
