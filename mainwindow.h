// 31/05/2019
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <dataBase.h>
#include <QSqlQuery>

#include "form_filter.h"
#include "dialog_store_windows.h"
#include "dialog_parts_id_update.h"
#include "dialog_parts_id_delete.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Dialog_parts_id_update *Window_parts_id_update;
    Dialog_parts_id_delete *Window_parts_id_delete;

    Form_filter *capacitorfilter;
    Form_filter *connectorfilter;
    Form_filter *diodefilter;
    Form_filter *fusefilter;
    Form_filter *inductorfilter;
    Form_filter *integratedcircuitfilter;
    Form_filter *ledfilter;
    Form_filter *quartzfilter;
    Form_filter *relayfilter;
    Form_filter *resistorfilter;
    Form_filter *switchfilter;
    Form_filter *transformatorfilter;
    Form_filter *transistorfilter;

    Ui::MainWindow *ui;
    QVBoxLayout *choose_filter_layout=nullptr;
    QVBoxLayout *capacitor_filter_layout=nullptr;
    QVBoxLayout *connector_filter_layout=nullptr;
    QVBoxLayout *diode_filter_layout=nullptr;
    QVBoxLayout *fuse_filter_layout=nullptr;
    QVBoxLayout *inductor_filter_layout=nullptr;
    QVBoxLayout *integrated_circuit_filter_layout=nullptr;
    QVBoxLayout *led_filter_layout=nullptr;
    QVBoxLayout *quartz_filter_layout=nullptr;
    QVBoxLayout *relay_filter_layout=nullptr;
    QVBoxLayout *resistor_filter_layout=nullptr;
    QVBoxLayout *switch_filter_layout=nullptr;
    QVBoxLayout *transformator_filter_layout=nullptr;
    QVBoxLayout *transistor_filter_layout=nullptr;

    QSqlQuery *qry;
    QSqlQueryModel *model = new QSqlQueryModel();

    QString ColumnName, PartIdNumber, CellData;

    DataBase GDS19_DataBase;

// Change on 04/10/20
    Dialog_store_windows *store_window=nullptr;

//
    QString CapacitorTable = "SELECT Parts_id, Value, Quantity, Voltage, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Capacitor' AND Value != '' ORDER BY Value";
    QString ConnectorTable = "SELECT Parts_id, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number FROM Parts WHERE Component='Connector' AND Reference != '' ORDER BY Reference";
    QString DiodeTable = "SELECT Parts_id, Reference, Quantity, Type, Power, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Diode' AND Reference != '' ORDER BY Reference";
    QString FuseTable = "SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Fuse' AND Reference != '' ORDER BY Reference";
    QString InductorTable = "SELECT Parts_id, Value, Quantity, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Inductor' AND Value != '' ORDER BY Value";
    QString IntegratedCircuitsTable = "SELECT Parts_id, Reference, Quantity, Type, Description, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Integrated Circuit' AND Reference != '' ORDER BY Reference";
    QString LedTable = "SELECT Parts_id, Reference, Quantity, Color, Diameter, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Led' AND Reference != '' ORDER BY Reference";
    QString QuartzTable = "SELECT Parts_id, Value, Quantity, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Quartz' AND Value != '' ORDER BY Value";
    QString RelayTable ="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Relay' AND Reference != '' ORDER BY Reference";
    QString ResistorTable = "SELECT Parts_id, Value, Quantity, Power, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE component='Resistor' AND Value != '' ORDER BY Value";
    QString SwitchTable = "SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Switch' AND Reference != '' ORDER BY Reference";
    QString TransformatorTable = "SELECT Parts_id, Reference, Quantity, Power, Voltage, Supplier, Item_number FROM Parts WHERE Component='Transformator' AND Reference != '' ORDER BY Reference";
    QString TransistorTable = "SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Transistor' AND Reference != '' ORDER BY Reference";

    QString SearchCapacitorbyPartId = "SELECT Parts_id, Component, Value, Quantity, Voltage, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Capacitor' AND Parts_id='%1'";
    QString SearchConnectorbyPartId = "SELECT Parts_id, Component, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number FROM Parts WHERE Component='Connector' AND Parts_id='%1'";
    QString SearchDiodebyPartId = "SELECT Parts_id, Component, Reference, Quantity, Type, Power, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Diode' AND Parts_id='%1'";
    QString SearchFusebyPartId = "SELECT Parts_id, Component, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Fuse' AND Parts_id='%1'"; //AND Reference != '' ORDER BY Reference";
    QString SearchInductorbyPartId = "SELECT Parts_id, Component, Value, Quantity, Mounting, Package, Current, Tolerance, Supplier, Item_number FROM Parts WHERE Component='Inductor' AND Parts_id='%1'";
    QString SearchIntegratedCircuitbyPartId = "SELECT Parts_id, Component, Reference, Quantity, Type, Description, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Integrated Circuit' AND Parts_id='%1'";
    QString SearchLedbyPartId = "SELECT Parts_id, Component, Reference, Quantity, Color, Diameter, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Led' AND Parts_id='%1'";
    QString SearchQuartzbyPartId = "SELECT Parts_id, Component, Value, Quantity, Mounting, Package, Supplier, Item_number FROM Parts WHERE Component='Quartz' AND Parts_id='%1'";
    QString SearchRelaybyPartId ="SELECT Parts_id, Component, Reference, Quantity, Mounting, Package, Voltage, Current, Configuration, Supplier, Item_number FROM Parts WHERE Component='Relay' AND Parts_id='%1'";
    QString SearchResistorbyPartId = "SELECT Parts_id, Component, Value, Quantity, Power, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE component='Resistor' AND Parts_id='%1'";
    QString SearchSwitchbyPartId = "SELECT Parts_id, Component, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Switch' AND Parts_id='%1'"; // AND Reference != '' ORDER BY Reference";
    QString SearchTransformatorbyPartId = "SELECT Parts_id, Component, Reference, Quantity, Power, Voltage, Supplier, Item_number FROM Parts WHERE Component='Transformator' AND Parts_id='%1'"; //AND Reference != '' ORDER BY Reference";
    QString SearchTransistorbyPartId = "SELECT Parts_id, Component, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Transistor' AND Parts_id='%1'";


public slots:
    void on_pushButton_search_component_clicked();
    void on_pushButton_store_component_clicked();

    void RefreshTable(QString dataToRefresh);
    void displayTable(QString data);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void DataBaseUpdate(QString NewCellValue);
    void DataBaseDeleteRow();

    void SelectItemNumbers();

    void ClearTable();

    void DisplayRow(QString Component, QString PartId);

    QString GetComponentFromPartId(QString PartId);
    QString GetComponentFromItemNumber(QString ItemNumber);
    QString GetPartIdFromItemNumber(QString ItemNumber);

    void UpdateTableRow(QString NewItemNumber);


signals:
    void notify_parts_id_to_update(QString ColumnName, QString CellData, QString PartIdNumber);
    void notify_parts_id_to_delete(QString CellData);
private slots:
    void on_pushButton_SearchBy_clicked();
};

#endif // MAINWINDOW_H
