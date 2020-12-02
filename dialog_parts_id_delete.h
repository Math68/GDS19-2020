// 31/05/2019
#ifndef DIALOG_PARTS_ID_DELETE_H
#define DIALOG_PARTS_ID_DELETE_H

#include <QDialog>

namespace Ui {
class Dialog_parts_id_delete;
}

class Dialog_parts_id_delete : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_parts_id_delete(QWidget *parent = nullptr);
    ~Dialog_parts_id_delete();

public slots:
    void display_parts_id_to_deleted(QString CellData);

signals:
    void notify_DatabaseRowToDelete();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_parts_id_delete *ui;
};

#endif // DIALOG_PARTS_ID_DELETE_H
