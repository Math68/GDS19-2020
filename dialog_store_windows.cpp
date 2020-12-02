// Last update 24/10/2019

// 25/11/19 Code Optimisation

#include "dialog_store_windows.h"
#include "ui_dialog_store_windows.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QDebug>

Dialog_store_windows::Dialog_store_windows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_store_windows)
{
    ui->setupUi(this);

    QSqlDatabase::database();

    FillComboBoxOneItem(SelectPartsData, "Mounting", ui->comboBox_store_mounting);
    FillComboBoxOneItem(SelectPartsData, "Supplier", ui->comboBox_store_supplier);
}

Dialog_store_windows::~Dialog_store_windows()
{
    delete ui;
}

void Dialog_store_windows::FillComboBox(QString _String, QString _Item, QString _Component, QComboBox *Combobox){

    //SelectData="SELECT DISTINCT %1 FROM parts WHERE Component = '%2' ORDER BY %1";

    QSqlQuery qry;
    qry.exec(_String.arg(_Item, _Component));
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

void Dialog_store_windows::FillComboBoxOneItem(QString _String, QString _Item, QComboBox *Combobox){

    QSqlQuery qry;
    qry.exec(_String.arg(_Item));
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

void Dialog_store_windows::set_capacitor_store_window()
{
    SelectedComponent=Capacitor;

    this->setWindowTitle("Store Capacitor");

    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);

    Combobox_store_tolerance = new QComboBox;
    Combobox_store_tolerance->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_voltage,2,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,2,1);
    ui->gridLayout_store->addWidget(Label_store_tolerance,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_tolerance,2,4);

    FillComboBox(SelectData,"Voltage","Capacitor",Combobox_store_voltage);
    FillComboBox(SelectData,"Tolerance","Capacitor",Combobox_store_tolerance);
    FillComboBox(SelectData,"Package","Capacitor",ui->comboBox_store_package);
}

void Dialog_store_windows::set_connector_store_window()
{
    SelectedComponent=Connector;

    this->setWindowTitle("Store Connector");

    delete ui->label_store_value;
    delete ui->label_store_mounting;
    delete ui->label_store_package;
    delete ui->comboBox_store_package;
    delete ui->comboBox_store_mounting;

    Lineedit_store_description = new QLineEdit;
    ComboBox_store_contacts = new QComboBox;
    ComboBox_store_spacing = new QComboBox;

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_contacts,1,0);
    ui->gridLayout_store->addWidget(ComboBox_store_contacts,1,1);
    ui->gridLayout_store->addWidget(Label_store_spacing,1,3);
    ui->gridLayout_store->addWidget(ComboBox_store_spacing,1,4);
    ui->gridLayout_store->addWidget(Label_store_description,2,0);
    ui->gridLayout_store->addWidget(Lineedit_store_description,2,1,1,4);

    FillComboBox(SelectData,"Contacts","Connector",ComboBox_store_contacts);
    FillComboBox(SelectData,"Spacing","Connector",ComboBox_store_spacing);
}

void Dialog_store_windows::set_diode_store_window()
{
    SelectedComponent=Diode;

    this->setWindowTitle("Store Diode");

    delete ui->label_store_value;

    ComboBox_store_type = new QComboBox;
    ComboBox_store_type->setEditable(1);
    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);
    Combobox_store_current = new QComboBox;
    Combobox_store_current->setEditable(1);
    Combobox_store_power = new QComboBox;
    Combobox_store_power->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_type,2,0);
    ui->gridLayout_store->addWidget(ComboBox_store_type,2,1);
    ui->gridLayout_store->addWidget(Label_store_power,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_power,2,4);
    ui->gridLayout_store->addWidget(Label_store_voltage,3,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,3,1);
    ui->gridLayout_store->addWidget(Label_store_current,3,3);
    ui->gridLayout_store->addWidget(Combobox_store_current,3,4);

    FillComboBox(SelectData,"Voltage","Diode",Combobox_store_voltage);
    FillComboBox(SelectData,"Current","Diode",Combobox_store_current);
    FillComboBox(SelectData,"Type","Diode",ComboBox_store_type);
    FillComboBox(SelectData,"Package","Diode",ui->comboBox_store_package);
    FillComboBox(SelectData,"Power","Diode",Combobox_store_power);
}

void Dialog_store_windows::set_fuse_store_window(){

    SelectedComponent=Fuse;

    this->setWindowTitle("Store Fuse");

    delete ui->label_store_value;
    ui->gridLayout_store->addWidget(Label_store_reference,0,0);

    ComboBox_store_type = new QComboBox;
    ComboBox_store_type->setEditable(1);
    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);
    Combobox_store_current = new QComboBox;
    Combobox_store_current->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_type,3,0);
    ui->gridLayout_store->addWidget(ComboBox_store_type,3,1);
    ui->gridLayout_store->addWidget(Label_store_voltage,4,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,4,1);
    ui->gridLayout_store->addWidget(Label_store_current,4,3);
    ui->gridLayout_store->addWidget(Combobox_store_current,4,4);

    FillComboBox(SelectData,"Voltage","Fuse",Combobox_store_voltage);
    FillComboBox(SelectData,"Current","Fuse",Combobox_store_current);
    FillComboBox(SelectData,"Type","Fuse",ComboBox_store_type);
}

void Dialog_store_windows::set_inductor_store_window()
{
    SelectedComponent=Inductor;

    this->setWindowTitle("Store Inductor");

    Combobox_store_tolerance = new QComboBox;
    Combobox_store_tolerance->setEditable(1);
    Combobox_store_current = new QComboBox;
    Combobox_store_current->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_current,2,0);
    ui->gridLayout_store->addWidget(Combobox_store_current,2,1);
    ui->gridLayout_store->addWidget(Label_store_tolerance,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_tolerance,2,4);

    FillComboBox(SelectData,"Tolerance","Inductor",Combobox_store_tolerance);
    FillComboBox(SelectData,"Current","Inductor",Combobox_store_current);
    FillComboBox(SelectData,"Package","Inductor",ui->comboBox_store_package);
}

void Dialog_store_windows::set_integrated_circuit_store_window()
{
    SelectedComponent=IntegratedCircuit;

    this->setWindowTitle("Store Integrated Circuit");

    delete ui->label_store_value;
    Lineedit_store_description = new QLineEdit();

    ComboBox_store_type = new QComboBox;
    ComboBox_store_type->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_type,2,0);
    ui->gridLayout_store->addWidget(ComboBox_store_type,2,1);
    ui->gridLayout_store->addWidget(Label_store_description,3,0);
    ui->gridLayout_store->addWidget(Lineedit_store_description,3,1,1,4);

    FillComboBox(SelectData,"Package","Integrated Circuit",ui->comboBox_store_package);
    FillComboBox(SelectData,"Type","Integrated Circuit",ComboBox_store_type);
}

void Dialog_store_windows::set_led_store_window()
{
    SelectedComponent=Led;

    this->setWindowTitle("Store Led");

    delete ui->label_store_value;
    Combobox_store_color = new QComboBox;
    Combobox_store_color->setEditable(1);
    Combobox_store_diameter = new QComboBox;
    Combobox_store_diameter->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_color,2,0);
    ui->gridLayout_store->addWidget(Combobox_store_color,2,1);
    ui->gridLayout_store->addWidget(Label_store_diameter,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_diameter,2,4);

    FillComboBox(SelectData,"Package","Led",ui->comboBox_store_package);
    FillComboBox(SelectData,"Color","Led",Combobox_store_color);
    FillComboBox(SelectData,"Diameter","Led",Combobox_store_diameter);
}

void Dialog_store_windows::set_quartz_store_window()
{
    SelectedComponent=Quartz;

    this->setWindowTitle("Store Quartz");

    FillComboBox(SelectData,"Package","Quartz",ui->comboBox_store_package);
}

void Dialog_store_windows::set_relay_store_window()
{
    SelectedComponent=Relay;

    this->setWindowTitle("Store Relay");

    delete ui->label_store_value;

    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);
    Combobox_store_current = new QComboBox;
    Combobox_store_current->setEditable(1);
    Combobox_store_configuration = new QComboBox;
    Combobox_store_configuration->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_voltage,2,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,2,1);
    ui->gridLayout_store->addWidget(Label_store_current,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_current,2,4);
    ui->gridLayout_store->addWidget(Label_store_configuration,3,0);
    ui->gridLayout_store->addWidget(Combobox_store_configuration,3,1);

    FillComboBox(SelectData,"Package","Relay",ui->comboBox_store_package);
    FillComboBox(SelectData,"Voltage","Relay",Combobox_store_voltage);
    FillComboBox(SelectData,"Current","Relay",Combobox_store_current);
    FillComboBox(SelectData,"Configuration","Relay",Combobox_store_configuration);
}

void Dialog_store_windows::set_resistor_store_window()
{
    SelectedComponent=Resistor;

    this->setWindowTitle("Store Resistor");

    Combobox_store_power = new QComboBox;
    Combobox_store_power->setEditable(1);
    Combobox_store_tolerance = new QComboBox;
    Combobox_store_tolerance->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_power,2,0);
    ui->gridLayout_store->addWidget(Combobox_store_power,2,1);
    ui->gridLayout_store->addWidget(Label_store_tolerance,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_tolerance,2,4);

    FillComboBox(SelectData,"Package","Resistor",ui->comboBox_store_package);
    FillComboBox(SelectData,"Power","Resistor",Combobox_store_power);
    FillComboBox(SelectData,"Tolerance","Resistor",Combobox_store_tolerance);
}

void Dialog_store_windows::set_switch_store_window()
{
    SelectedComponent=Switch;

    this->setWindowTitle("Store Switch");

    delete ui->label_store_value;

    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);
    Combobox_store_current = new QComboBox;
    Combobox_store_current->setEditable(1);
    Combobox_store_configuration = new QComboBox;
    Combobox_store_configuration->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_voltage,2,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,2,1);
    ui->gridLayout_store->addWidget(Label_store_current,2,3);
    ui->gridLayout_store->addWidget(Combobox_store_current,2,4);
    ui->gridLayout_store->addWidget(Label_store_configuration,3,0);
    ui->gridLayout_store->addWidget(Combobox_store_configuration,3,1);

    FillComboBox(SelectData,"Package","Switch",ui->comboBox_store_package);
    FillComboBox(SelectData,"Voltage","Switch",Combobox_store_voltage);
    FillComboBox(SelectData,"Current","Switch",Combobox_store_current);
    FillComboBox(SelectData,"Configuration","Switch",Combobox_store_configuration);
}

void Dialog_store_windows::set_transformator_store_window()
{
    SelectedComponent=Transformator;

    this->setWindowTitle("Store Transformator");

    delete ui->label_store_value;
    delete ui->label_store_mounting;
    delete ui->label_store_package;
    delete ui->comboBox_store_package;
    delete ui->comboBox_store_mounting;

    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);
    Combobox_store_power = new QComboBox;
    Combobox_store_power->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_voltage,1,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,1,1);
    ui->gridLayout_store->addWidget(Label_store_power,1,3);
    ui->gridLayout_store->addWidget(Combobox_store_power,1,4);
}

void Dialog_store_windows::set_transistor_store_window()
{
    SelectedComponent=Transistor;

    this->setWindowTitle("Store Transistor");

    delete ui->label_store_value;
    ComboBox_store_type = new QComboBox;
    ComboBox_store_type->setEditable(1);
    Combobox_store_voltage = new QComboBox;
    Combobox_store_voltage->setEditable(1);
    Combobox_store_current = new QComboBox;
    Combobox_store_current->setEditable(1);

    ui->gridLayout_store->addWidget(Label_store_reference,0,0);
    ui->gridLayout_store->addWidget(Label_store_type,2,0);
    ui->gridLayout_store->addWidget(ComboBox_store_type,2,1);
    ui->gridLayout_store->addWidget(Label_store_voltage,3,0);
    ui->gridLayout_store->addWidget(Combobox_store_voltage,3,1);
    ui->gridLayout_store->addWidget(Label_store_current,3,3);
    ui->gridLayout_store->addWidget(Combobox_store_current,3,4);

    FillComboBox(SelectData,"Package","Transistor",ui->comboBox_store_package);
    FillComboBox(SelectData,"Type","Transistor",ComboBox_store_type);
    FillComboBox(SelectData,"Voltage","Transistor",Combobox_store_voltage);
    FillComboBox(SelectData,"Current","Transistor",Combobox_store_current);
}

void Dialog_store_windows::on_pushButton_store_save_clicked()
{
    QString NewItemNumber;

    NewItemNumber=ui->lineEdit_store_item_number->text();
//    qDebug() << NewItemNumber;
    // Check Item Number

    if(SelectedComponent==Capacitor)
        save_capacitor();

    else if(SelectedComponent==Connector)
         save_connector();

    else if(SelectedComponent==Diode)
         save_diode();

    else if(SelectedComponent==Fuse)
        save_fuse();

    else if(SelectedComponent==Inductor)
        save_inductor();

    else if(SelectedComponent==IntegratedCircuit)
        save_integrated_circuit();

    else if(SelectedComponent==Led)
        save_led();

    else if(SelectedComponent==Quartz)
        save_quartz();

    else if(SelectedComponent==Relay)
        save_relay();

    else if(SelectedComponent==Resistor)
        save_resistor();

    else if(SelectedComponent==Switch)
        save_switch();

    else if(SelectedComponent==Transformator)
        save_transformator();

    else if(SelectedComponent==Transistor)
        save_transistor();

    notify_component_has_been_saved(NewItemNumber);
    close();
}

void Dialog_store_windows::on_pushButton_store_cancel_clicked()
{
    close();
}

void Dialog_store_windows::save_capacitor()
{
  QSqlQuery query;
    query.exec("insert into Parts (Component, Value, Quantity, Mounting, Package, Tolerance, Supplier, Item_number, Voltage)"
               " values('Capacitor','"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Combobox_store_tolerance->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"',"
               "  '"+Combobox_store_voltage->currentText()+"')");
}

void Dialog_store_windows::save_connector()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number)"
               " values('Connector','"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ComboBox_store_contacts->currentText()+"',"
               "'"+ComboBox_store_spacing->currentText()+"',"
               "'"+Lineedit_store_description->text()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_diode()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Mounting, Package, Type, Voltage, Current, Supplier, Item_number)"
               " values('Diode',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+ComboBox_store_type->currentText()+"',"
               "'"+Combobox_store_voltage->currentText()+"',"
               "'"+Combobox_store_current->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_fuse()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Mounting, Package, Type, Voltage, Current, Supplier, Item_number)"
               " values('Fuse',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+ComboBox_store_type->currentText()+"',"
               "'"+Combobox_store_voltage->currentText()+"',"
               "'"+Combobox_store_current->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_inductor()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Value, Quantity, Mounting, Package, Tolerance, Current, Supplier, Item_number)"
               " values('Inductor',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Combobox_store_tolerance->currentText()+"',"
               "'"+Combobox_store_current->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_integrated_circuit()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Type, Quantity, Mounting, Package, Description, Supplier, Item_number)"
               " values('Integrated Circuit',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ComboBox_store_type->currentText()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Lineedit_store_description->text()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_led()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Mounting, Package, Color, Diameter, Supplier, Item_number)"
               " values('Led',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Combobox_store_color->currentText()+"',"
               "'"+Combobox_store_diameter->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_quartz()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Value, Quantity, Mounting, Package, Supplier, Item_number)"
               " values('Quartz',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_relay()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Mounting, Package, Voltage, Current, Configuration, Supplier, Item_number)"
               " values('Relay',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Combobox_store_voltage->currentText()+"',"
               "'"+Combobox_store_current->currentText()+"',"
               "'"+Combobox_store_configuration->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_resistor()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Value, Quantity, Mounting, Package, Power, Tolerance, Supplier, Item_number)"
               " values('Resistor',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Combobox_store_power->currentText()+"',"
               "'"+Combobox_store_tolerance->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_switch()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Mounting, Package, Voltage, Current, Configuration, Supplier, Item_number)"
               " values('Switch',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+Combobox_store_voltage->currentText()+"',"
               "'"+Combobox_store_current->currentText()+"',"
               "'"+Combobox_store_configuration->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"')");
}

void Dialog_store_windows::save_transformator()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Supplier, Item_number, Voltage, Power)"
               " values('Transformator',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"',"
               "'"+Combobox_store_voltage->currentText()+"',"
               "'"+Combobox_store_power->currentText()+"')");
}

void Dialog_store_windows::save_transistor()
{
    QSqlQuery query;
    query.exec("insert into Parts (Component, Reference, Quantity, Mounting, Package, Type, Supplier, Item_number, Voltage, Current)"
               " values('Transistor',"
               "'"+ui->lineEdit_store_value->text()+"',"
               "'"+ui->lineEdit_store_quantity->text()+"',"
               "'"+ui->comboBox_store_mounting->currentText()+"',"
               "'"+ui->comboBox_store_package->currentText()+"',"
               "'"+ComboBox_store_type->currentText()+"',"
               "'"+ui->comboBox_store_supplier->currentText()+"',"
               "'"+ui->lineEdit_store_item_number->text()+"',"
               "'"+Combobox_store_voltage->currentText()+"',"
               "'"+Combobox_store_current->currentText()+"')");
}
