// 31/05/2019
#include "form_filter.h"
#include "ui_form_filter.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

Form_filter::Form_filter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_filter){
    ui->setupUi(this);

    Label_filter_value->setAlignment(Qt::AlignRight);
    Label_filter_voltage->setAlignment(Qt::AlignRight);
    Label_filter_tolerance->setAlignment(Qt::AlignRight);
    Label_filter_reference->setAlignment(Qt::AlignRight);
    Label_filter_contacts->setAlignment(Qt::AlignRight);
    Label_filter_type->setAlignment(Qt::AlignRight);
    Label_filter_spacing->setAlignment(Qt::AlignRight);
    Label_filter_power->setAlignment(Qt::AlignRight);
    Label_filter_diameter->setAlignment(Qt::AlignRight);
    Label_filter_current->setAlignment(Qt::AlignRight);
    Label_filter_color->setAlignment(Qt::AlignRight);
    Label_filter_configuration->setAlignment(Qt::AlignRight);

    //Label_filter_spacing->setFixedSize(65,20);
    //comboBox_filter_spacing->minimumSizeHint(); //setFixedSize(70,20);

    //connect(comboBox_filter_value, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_value_currentTextChanged(QString)));
}

Form_filter::~Form_filter(){
    delete ui;
}

void Form_filter::clearlists(){
    ListFilterCombobox.clear();
    ListFilterData.clear();
}

// ***********************************************************
// ***** SET FILTER
// ***********************************************************

void Form_filter::set_capacitor_filter(){
    componentToFilter=Capacitor;

    ui->gridLayout_filter->addWidget(Label_filter_value,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_value,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_tolerance,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_tolerance,1,5);

    fill_capacitor_combobox();

    connect(comboBox_filter_value, SIGNAL (currentTextChanged(QString)), this,  SLOT(on_comboBox_filter_value_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));
    connect(comboBox_filter_tolerance, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_tolerance_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_connector_filter(){
    componentToFilter=Connector;

    ui->label_filter_mounting->hide();
    ui->comboBox_filter_mounting->hide();

    ui->label_filter_package->hide();
    ui->comboBox_filter_package->hide();

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_contacts,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_contacts,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_spacing,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_spacing,1,5);

    ui->gridLayout_filter->setColumnMinimumWidth(4,65);
    ui->gridLayout_filter->setColumnMinimumWidth(5,65);

    fill_connector_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_contacts, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_contacts_currentTextChanged(QString)));
    connect(comboBox_filter_spacing, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_spacing_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_diode_filter(){
    componentToFilter=Diode;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_type,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_type,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_power,2,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_power,2,1);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,2,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,2,3);
    ui->gridLayout_filter->addWidget(Label_filter_current,2,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_current,2,5);

    fill_diode_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_type, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_type_currentTextChanged(QString)));
    connect(comboBox_filter_power, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_power_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));
    connect(comboBox_filter_current, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_current_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_fuse_filter(){
    componentToFilter=Fuse;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_type,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_type,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,1,5);
    ui->gridLayout_filter->addWidget(Label_filter_current,1,6);
    ui->gridLayout_filter->addWidget(comboBox_filter_current,1,7);

    fill_fuse_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_type, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_type_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));
    connect(comboBox_filter_current, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_current_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_inductor_filter(){
    componentToFilter=Inductor;

    ui->gridLayout_filter->addWidget(Label_filter_value,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_value,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_current,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_current,1,3);

    fill_inductor_combobox();

    connect(comboBox_filter_value, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_value_currentTextChanged(QString)));
    connect(comboBox_filter_current, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_current_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_integrated_circuit_filter(){
    componentToFilter=Integrated_Circuit;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_type,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_type,1,3);

    fill_integrated_circuit_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_type, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_type_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_led_filter(){
    componentToFilter=Led;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_color,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_color,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_diameter,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_diameter,1,5);

    fill_led_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_color, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_color_currentTextChanged(QString)));
    connect(comboBox_filter_diameter, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_diameter_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_quartz_filter(){
    componentToFilter=Quartz;

    ui->gridLayout_filter->addWidget(Label_filter_value,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_value,1,1);

    fill_quartz_combobox();

    connect(comboBox_filter_value, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_value_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_relay_filter(){
    componentToFilter=Relay;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_configuration,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_configuration,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,1,5);
    ui->gridLayout_filter->addWidget(Label_filter_current,1,6);
    ui->gridLayout_filter->addWidget(comboBox_filter_current,1,7);

    fill_relay_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_configuration, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_configuration_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));
    connect(comboBox_filter_current, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_current_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_resistor_filter(){

    componentToFilter=Resistor;

    ui->gridLayout_filter->addWidget(Label_filter_value,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_value,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_power,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_power,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_tolerance,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_tolerance,1,5);

    fill_resistor_combobox();

    connect ( comboBox_filter_value, SIGNAL (currentTextChanged(QString)), this,  SLOT(on_comboBox_filter_value_currentTextChanged(QString)));
    connect( comboBox_filter_power, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_power_currentTextChanged(QString)));
    connect( comboBox_filter_tolerance, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_tolerance_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_switch_filter(){
    componentToFilter=Switch;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_configuration,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_configuration,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,1,5);
    ui->gridLayout_filter->addWidget(Label_filter_current,1,6);
    ui->gridLayout_filter->addWidget(comboBox_filter_current,1,7);

    fill_switch_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_configuration, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_configuration_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));
    connect(comboBox_filter_current, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_current_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_transformator_filter(){
    componentToFilter=Transformator;

    ui->label_filter_mounting->hide();
    ui->comboBox_filter_mounting->hide();
    ui->label_filter_package->hide();
    ui->comboBox_filter_package->hide();

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,2,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,2,1);
    ui->gridLayout_filter->addWidget(Label_filter_power,2,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_power,2,3);

    fill_transformator_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_power, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_power_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));

    clearlists();
}

void Form_filter::set_transistor_filter(){

    componentToFilter=Transistor;

    ui->gridLayout_filter->addWidget(Label_filter_reference,1,0);
    ui->gridLayout_filter->addWidget(comboBox_filter_reference,1,1);
    ui->gridLayout_filter->addWidget(Label_filter_type,1,2);
    ui->gridLayout_filter->addWidget(comboBox_filter_type,1,3);
    ui->gridLayout_filter->addWidget(Label_filter_voltage,1,4);
    ui->gridLayout_filter->addWidget(comboBox_filter_voltage,1,5);
    ui->gridLayout_filter->addWidget(Label_filter_current,1,6);
    ui->gridLayout_filter->addWidget(comboBox_filter_current,1,7);

    fill_transistor_combobox();

    connect(comboBox_filter_reference, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_reference_currentTextChanged(QString)));
    connect(comboBox_filter_type, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_type_currentTextChanged(QString)));
    connect(comboBox_filter_voltage, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_voltage_currentTextChanged(QString)));
    connect(comboBox_filter_current, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboBox_filter_current_currentTextChanged(QString)));

    clearlists();
}

// ******************************************************
// ***** FILL COMBOBOX
// ******************************************************

void Form_filter::FillComboBox(QString _String, QString _Item, QString _Component, QComboBox *Combobox){

    //QString SelectData = "SELECT DISTINCT %1 FROM Parts WHERE Component='%2' ORDER BY %1";

    QSqlQuery qry;
    qry.exec(_String.arg(_Item, _Component));
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

void Form_filter::fill_capacitor_combobox(){

    FillComboBox(SelectData, "Item_number", "Capacitor", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Capacitor", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Capacitor", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Capacitor", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Value", "Capacitor", comboBox_filter_value);
    FillComboBox(SelectData, "Voltage", "Capacitor", comboBox_filter_voltage);
    FillComboBox(SelectData, "Tolerance", "Capacitor", comboBox_filter_tolerance);
}

void Form_filter::fill_connector_combobox(){

    FillComboBox(SelectData, "Item_number", "Connector", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Connector", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Reference", "Connector", comboBox_filter_reference);
    FillComboBox(SelectData, "Contacts", "Connector", comboBox_filter_contacts);
    FillComboBox(SelectData, "Spacing", "Connector", comboBox_filter_spacing);
}

void Form_filter::fill_diode_combobox(){

    FillComboBox(SelectData, "Item_number", "Diode", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Diode", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Diode", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Diode", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Diode", comboBox_filter_reference);
    FillComboBox(SelectData, "Type", "Diode", comboBox_filter_type);
    FillComboBox(SelectData, "Power", "Diode", comboBox_filter_power);
    FillComboBox(SelectData, "Voltage", "Diode", comboBox_filter_voltage);
    FillComboBox(SelectData, "Current", "Diode", comboBox_filter_current);
}

void Form_filter::fill_fuse_combobox(){

    FillComboBox(SelectData, "Item_number", "Fuse", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Fuse", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Fuse", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Fuse", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Fuse", comboBox_filter_reference);
    FillComboBox(SelectData, "Type", "Fuse", comboBox_filter_type);
    FillComboBox(SelectData, "Power", "Fuse", comboBox_filter_power);
    FillComboBox(SelectData, "Voltage", "Fuse", comboBox_filter_voltage);
    FillComboBox(SelectData, "Current", "Fuse", comboBox_filter_current);
}

void Form_filter::fill_inductor_combobox(){

    FillComboBox(SelectData, "Item_number", "Inductor", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Inductor", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Inductor", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Inductor", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Value", "Inductor", comboBox_filter_value);
    FillComboBox(SelectData, "Current", "Inductor", comboBox_filter_current);
}

void Form_filter::fill_integrated_circuit_combobox(){

    FillComboBox(SelectData, "Item_number", "Integrated Circuit", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Integrated Circuit", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Integrated Circuit", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Integrated Circuit", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Integrated Circuit", comboBox_filter_reference);
    FillComboBox(SelectData, "Type", "Integrated Circuit", comboBox_filter_type);
}

void Form_filter::fill_led_combobox(){

    FillComboBox(SelectData, "Item_number", "Led", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Led", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Led", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Led", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Led", comboBox_filter_reference);
    FillComboBox(SelectData, "Color", "Led", comboBox_filter_color);
    FillComboBox(SelectData, "Diameter", "Led", comboBox_filter_diameter);
}

void Form_filter::fill_quartz_combobox(){

    FillComboBox(SelectData, "Item_number", "Quartz", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Quartz", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Quartz", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Quartz", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Value", "Quartz", comboBox_filter_value);
}

void Form_filter::fill_relay_combobox(){

    FillComboBox(SelectData, "Item_number", "Relay", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Relay", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Relay", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Relay", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Relay", comboBox_filter_reference);
    FillComboBox(SelectData, "Configuration", "Relay", comboBox_filter_configuration);
    FillComboBox(SelectData, "Voltage", "Relay", comboBox_filter_voltage);
    FillComboBox(SelectData, "Current", "Relay", comboBox_filter_current);
}

void Form_filter::fill_resistor_combobox(){

    FillComboBox(SelectData, "Item_number", "Resistor", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Resistor", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Resistor", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Resistor", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Value", "Resistor", comboBox_filter_value);
    FillComboBox(SelectData, "Power", "Resistor", comboBox_filter_power);
    FillComboBox(SelectData, "Tolerance", "Resistor", comboBox_filter_tolerance);
}

void Form_filter::fill_switch_combobox(){

    FillComboBox(SelectData, "Item_number", "Switch", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Switch", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Switch", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Switch", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Switch", comboBox_filter_reference);
    FillComboBox(SelectData, "Configuration", "Switch", comboBox_filter_configuration);
    FillComboBox(SelectData, "Voltage", "Switch", comboBox_filter_voltage);
    FillComboBox(SelectData, "Current", "Switch", comboBox_filter_current);
}

void Form_filter::fill_transformator_combobox(){

    FillComboBox(SelectData, "Item_number", "Transformator", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Transformator", ui->comboBox_filter_supplier);
    //FillComboBox(SelectData, "Mounting", "Transformator", ui->comboBox_filter_mounting);
    //FillComboBox(SelectData, "Package", "Transformator", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Transformator", comboBox_filter_reference);
    FillComboBox(SelectData, "Power", "Transformator", comboBox_filter_power);
    FillComboBox(SelectData, "Voltage", "Transformator", comboBox_filter_voltage);
}

void Form_filter::fill_transistor_combobox(){

    FillComboBox(SelectData, "Item_number", "Transistor", ui->comboBox_filter_item_number);
    FillComboBox(SelectData, "Supplier", "Transistor", ui->comboBox_filter_supplier);
    FillComboBox(SelectData, "Mounting", "Transistor", ui->comboBox_filter_mounting);
    FillComboBox(SelectData, "Package", "Transistor", ui->comboBox_filter_package);
    FillComboBox(SelectData, "Reference", "Transistor", comboBox_filter_reference);
    FillComboBox(SelectData, "Type", "Transistor", comboBox_filter_type);
    FillComboBox(SelectData, "Voltage", "Transistor", comboBox_filter_voltage);
    FillComboBox(SelectData, "Current", "Transistor", comboBox_filter_current);
}

// **************************************************************
// ***** Combobox change managing
// **************************************************************

// Prise en compte changement combobox
/*
 *  21/10/17 + 20.01.19
 * Verification si la ListFilterCombobox n'est pas vide
 * si oui recherche de l'index de la Combobox selectionné
 * si l'index est !=-1 (-1 correspond à une combobox vide)
 *  Remplacement des données dans la DataList
 *
 *  Si non
 *  Rajout de la combobox à la ListFilterC
 *  Rajout des données à la DataList.
*/

void Form_filter::on_comboBox_filter_reference_currentTextChanged(const QString &arg1){
    if(comboBox_filter_reference->currentText() !="" ){ // != ""
        // Si qq chose de selectionné
        if(ListFilterCombobox.indexOf("Reference")==-1){
            // Si Reference ne fait pas partie de la liste des Combobox selectionné
            ListFilterCombobox<<"Reference";
            // Ajout a la liste des combobox
            ListFilterData.insert( ListFilterCombobox.indexOf("Reference") , arg1 );
            // Ajout de la donnée a la liste des données a l'index de Reference
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Reference") , arg1 );
            // Si la combo est deja dans la liste il suffit de remplacer la donnée
        }
    }
    else if(comboBox_filter_reference->currentText()=="" && ListFilterCombobox.indexOf("Reference")!=-1){
        // Si l element a ete deselectionné et fait partie de la liste des combobox
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Reference"));
        // Retrait de la donnée de la liste des données
        ListFilterCombobox.removeOne("Reference");
        // Retrait de Reference de la liste des combobox
    }
}

void Form_filter::on_comboBox_filter_value_currentTextChanged(const QString &arg1){
    // 20.01.19

    qDebug()<<"Value modified !!!";

    if(comboBox_filter_value->currentText()!="") //
    {
        qDebug() << "Value is not empty !!!";

        if(ListFilterCombobox.indexOf("Value")==-1){
            ListFilterCombobox<<"Value";
            ListFilterData.insert(ListFilterCombobox.indexOf("Value") , arg1 );
        }
        else{
            ListFilterData.replace(ListFilterCombobox.indexOf("Value"), arg1 );
        }
    }
    else if(comboBox_filter_value->currentText()=="" && ListFilterCombobox.indexOf("Value")!=-1){
        qDebug() << "Value is empty as the list !!!";
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Value"));
        ListFilterCombobox.removeOne("Value");
    }
}

void Form_filter::on_comboBox_filter_type_currentTextChanged(const QString &arg1){
    if(comboBox_filter_type->currentText()!=""){
        if(ListFilterCombobox.indexOf("Type")==-1){
            ListFilterCombobox<<"Type";
            ListFilterData.insert( ListFilterCombobox.indexOf("Type") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Type") , arg1 );
        }
    }
    else if(comboBox_filter_spacing->currentText()=="" && ListFilterCombobox.indexOf("Type")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Type"));
        ListFilterCombobox.removeOne("Type");
    }
}

void Form_filter::on_comboBox_filter_power_currentTextChanged(const  QString &arg1){
    if(comboBox_filter_power->currentText()!=""){
        if(ListFilterCombobox.indexOf("Power")==-1){
            ListFilterCombobox<<"Power";
            ListFilterData.insert( ListFilterCombobox.indexOf("Power") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Power") , arg1 );
        }
    }
    else if(comboBox_filter_power->currentText()=="" && ListFilterCombobox.indexOf("Power")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Power"));
        ListFilterCombobox.removeOne("Power");
    }
}

void Form_filter::on_comboBox_filter_voltage_currentTextChanged(const QString &arg1){
  if(comboBox_filter_voltage->currentText()!=""){
      if(ListFilterCombobox.indexOf("Voltage")==-1){
          ListFilterCombobox<<"Voltage";
          ListFilterData.insert( ListFilterCombobox.indexOf("Voltage") , arg1 );
      }
      else{
          ListFilterData.replace( ListFilterCombobox.indexOf("Voltage") , arg1 );
      }
  }
  else if(comboBox_filter_voltage->currentText()=="" && ListFilterCombobox.indexOf("Voltage")!=-1){
      ListFilterData.removeAt(ListFilterCombobox.indexOf("Voltage"));
      ListFilterCombobox.removeOne("Voltage");
  }
}

void Form_filter::on_comboBox_filter_current_currentTextChanged(const QString &arg1){
    if(comboBox_filter_current->currentText()!=""){
        if(ListFilterCombobox.indexOf("Current")==-1){
            ListFilterCombobox<<"Current";
            ListFilterData.insert( ListFilterCombobox.indexOf("Current") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Current") , arg1 );
        }
    }
    else if(comboBox_filter_current->currentText()=="" && ListFilterCombobox.indexOf("Current")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Current"));
        ListFilterCombobox.removeOne("Current");
    }
}

void Form_filter::on_comboBox_filter_tolerance_currentTextChanged(const QString &arg1){
    if(comboBox_filter_tolerance->currentText()!=""){
        if(ListFilterCombobox.indexOf("Tolerance")==-1){
            ListFilterCombobox<<"Tolerance";
            ListFilterData.insert( ListFilterCombobox.indexOf("Tolerance") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Tolerance") , arg1 );
        }
    }
    else if(comboBox_filter_tolerance->currentText()=="" && ListFilterCombobox.indexOf("Tolerance")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Tolerance"));
        ListFilterCombobox.removeOne("Tolerance");
    }
}

void Form_filter::on_comboBox_filter_contacts_currentTextChanged(const QString &arg1){
    if(comboBox_filter_contacts->currentText()!=""){
        if(ListFilterCombobox.indexOf("Contacts")==-1){
            ListFilterCombobox<<"Contacts";
            ListFilterData.insert( ListFilterCombobox.indexOf("Contacts") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Contacts") , arg1 );
        }
    }
    else if(comboBox_filter_contacts->currentText()=="" && ListFilterCombobox.indexOf("Contacts")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Contacts"));
        ListFilterCombobox.removeOne("Contacts");
    }
}

void Form_filter::on_comboBox_filter_spacing_currentTextChanged(const QString &arg1){
    if(comboBox_filter_spacing->currentText()!=""){
        if(ListFilterCombobox.indexOf("Spacing")==-1){
            ListFilterCombobox<<"Spacing";
            ListFilterData.insert( ListFilterCombobox.indexOf("Spacing") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Spacing") , arg1 );
        }
    }
    else if(comboBox_filter_spacing->currentText()=="" && ListFilterCombobox.indexOf("Spacing")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Spacing"));
        ListFilterCombobox.removeOne("Spacing");
    }
}

void Form_filter::on_comboBox_filter_color_currentTextChanged(const QString &arg1){
    if(comboBox_filter_color->currentText()!=""){
        if(ListFilterCombobox.indexOf("Color")==-1){
            ListFilterCombobox<<"Color";
            ListFilterData.insert( ListFilterCombobox.indexOf("Color") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Color") , arg1 );
        }
    }
    else if(comboBox_filter_color->currentText()=="" && ListFilterCombobox.indexOf("Color")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Color"));
        ListFilterCombobox.removeOne("Color");
    }
}

void Form_filter::on_comboBox_filter_diameter_currentTextChanged(const QString &arg1){
    if(comboBox_filter_diameter->currentText()!=""){
        if(ListFilterCombobox.indexOf("Diameter")==-1){
            ListFilterCombobox<<"Diameter";
            ListFilterData.insert( ListFilterCombobox.indexOf("Diameter") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Diameter") , arg1 );
        }
    }
    else if(comboBox_filter_diameter->currentText()=="" && ListFilterCombobox.indexOf("Diameter")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Diameter"));
        ListFilterCombobox.removeOne("Diameter");
    }
}

void Form_filter::on_comboBox_filter_configuration_currentTextChanged(const QString &arg1){
    if(comboBox_filter_configuration->currentText()!=""){
        if(ListFilterCombobox.indexOf("Configuration")==-1){
            ListFilterCombobox<<"Configuration";
            ListFilterData.insert( ListFilterCombobox.indexOf("Configuration") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Configuration") , arg1 );
        }
    }
    else if(comboBox_filter_configuration->currentText()=="" && ListFilterCombobox.indexOf("Package")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Configuration"));
        ListFilterCombobox.removeOne("Configuration");
    }
}

void Form_filter::on_comboBox_filter_package_currentTextChanged(const QString &arg1){
    if(ui->comboBox_filter_package->currentText()!=""){
        if(ListFilterCombobox.indexOf("Package")==-1){
            ListFilterCombobox<<"Package";
            ListFilterData.insert( ListFilterCombobox.indexOf("Package") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Package") , arg1 );
        }
    }
    else if(ui->comboBox_filter_package->currentText()=="" && ListFilterCombobox.indexOf("Package")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Package"));
        ListFilterCombobox.removeOne("Package");
    }
}

void Form_filter::on_comboBox_filter_mounting_currentTextChanged(const QString &arg1){
    if(ui->comboBox_filter_mounting->currentText()!=""){
        if(ListFilterCombobox.indexOf("Mounting")==-1){
            ListFilterCombobox<<"Mounting";
            ListFilterData.insert( ListFilterCombobox.indexOf("Mounting") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Mounting") , arg1 );
        }
    }
    else if(ui->comboBox_filter_mounting->currentText()=="" && ListFilterCombobox.indexOf("Mounting")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Mounting"));
        ListFilterCombobox.removeOne("Mounting");
    }
}

void Form_filter::on_comboBox_filter_supplier_currentTextChanged(const QString &arg1){
    if(ui->comboBox_filter_supplier->currentText()!=""){
        if(ListFilterCombobox.indexOf("Supplier")==-1){
            ListFilterCombobox<<"Supplier";
            ListFilterData.insert( ListFilterCombobox.indexOf("Supplier") , arg1 );
        }
        else{
            ListFilterData.replace( ListFilterCombobox.indexOf("Supplier") , arg1 );
        }
    }
    else if(ui->comboBox_filter_supplier->currentText()=="" && ListFilterCombobox.indexOf("Supplier")!=-1){
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Supplier"));
        ListFilterCombobox.removeOne("Supplier");
    }
}

void Form_filter::on_comboBox_filter_item_number_currentTextChanged(const QString &arg1){
    if(ui->comboBox_filter_item_number->currentText()!="") // si un element est selectionné
      {
        if(ListFilterCombobox.indexOf("Item_number")==-1)  // si Item_number absent de la liste => on le rajoute
          {
            ListFilterCombobox<<"Item_number";
            ListFilterData.insert(ListFilterCombobox.indexOf("Item_number"),arg1); // et dans la liste des data on ajoute l'élément
          }
        else
          {
            ListFilterData.replace(ListFilterCombobox.indexOf("Item_number"),arg1);  // si deja dans la liste on le remplace
          }
      }
    else if(ui->comboBox_filter_item_number->currentText()=="" && ListFilterCombobox.indexOf("Item_number")!=-1)
    {
        ListFilterData.removeAt(ListFilterCombobox.indexOf("Item_number"));
        ListFilterCombobox.removeOne("Item_number");
    }
}

// **************************************************
// *****         Filter Reset
// **************************************************

void Form_filter::on_pushButton_filter_reset_clicked(){

    clearlists();

    switch(componentToFilter){

    case Choose:
        break;

    case Capacitor:
        fill_capacitor_combobox();
        break;

    case Connector:
        fill_connector_combobox();
        break;

    case Diode:
        fill_diode_combobox();
        break;

    case Fuse:
        fill_fuse_combobox();
        break;

    case Inductor:
        fill_inductor_combobox();
        break;

    case Integrated_Circuit:
        fill_integrated_circuit_combobox();
        break;

    case Led:
        fill_led_combobox();
        break;

    case Quartz:
        fill_quartz_combobox();
        break;

    case Relay:
        fill_relay_combobox();
        break;

    case Resistor:
        fill_resistor_combobox();
        break;

    case Switch:
        fill_switch_combobox();
        break;

    case Transformator:
        fill_transformator_combobox();
        break;

    case Transistor:
        fill_transistor_combobox();
        break;
    }
}

// *******************************************************
// ***** Combobox Filling
// *******************************************************

void Form_filter::FillFilteredComboBox_OneItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox){

    QSqlQuery qry;
    qry.exec(_String.arg(_Item, _Component, ""+ListFilterCombobox[0]+"", ""+ListFilterData[0]+""));
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

void Form_filter::FillFilteredComboBox_TwoItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox){

    QSqlQuery qry;
    qry.exec(_String.arg(_Item, _Component, ""+ListFilterCombobox[0]+"", ""+ListFilterData[0]+"", ""+ListFilterCombobox[1]+"", ""+ListFilterData[1]+"") );
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

void Form_filter::FillFilteredComboBox_ThreeItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox){

    QSqlQuery qry;
    qry.exec(_String.arg(_Item, _Component, ""+ListFilterCombobox[0]+"", ""+ListFilterData[0]+"", ""+ListFilterCombobox[1]+"", ""+ListFilterData[1]+"", ""+ListFilterCombobox[2]+"", ""+ListFilterData[2]+"") );
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

void Form_filter::FillFilteredComboBox_FourItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox){

    QSqlQuery qry;
    qry.exec(_String.arg(_Item, _Component, ""+ListFilterCombobox[0]+"", ""+ListFilterData[0]+"", ""+ListFilterCombobox[1]+"", ""+ListFilterData[1]+"", ""+ListFilterCombobox[2]+"", ""+ListFilterData[2]+"").arg( ""+ListFilterCombobox[3]+"", ""+ListFilterData[3]+"") );
    QSqlQueryModel *Model = new QSqlQueryModel;
    Model->setQuery(qry);
    Combobox->setModel(Model);
}

// *********************************************************************
// ***** Filter Managing => emit notifyRefreshTable(dataToRefresh);
// *********************************************************************

void Form_filter::on_pushButton_filter_activate_filter_clicked()
{
    QString dataToRefresh;
    QString SelectFilteredData_OneItem = " SELECT DISTINCT %1 FROM Parts WHERE Component = '%2' AND (%3 = '%4' OR %3 IS NULL) ORDER BY %1 ";
    QString SelectFilteredData_TwoItem = " SELECT DISTINCT %1 FROM Parts WHERE Component = '%2' AND ( %3 = '%4' AND %5 = '%6' OR %3 IS NULL ) ORDER BY %1 ";
    QString SelectFilteredData_ThreeItem = " SELECT DISTINCT %1 FROM Parts WHERE Component = '%2' AND ( %3 = '%4' AND %5 = '%6' AND %7 = '%8' OR %3 IS NULL ) ORDER BY %1 ";
    QString SelectFilteredData_FourItem = " SELECT DISTINCT %1 FROM Parts WHERE Component = '%2' AND ( %3 = '%4' AND %5 = '%6' AND %7 = '%8' AND %9 = '%10' OR %3 IS NULL ) ORDER BY %1 ";

    if(componentToFilter==Capacitor){

        switch(ListFilterCombobox.length())
        {
        case 1:
            //Si Item number ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Item_number", "Capacitor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Supplier", "Capacitor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Mounting", "Capacitor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Package", "Capacitor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Value", "Capacitor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Voltage", "Capacitor", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Tolerance", "Capacitor", comboBox_filter_tolerance);

            // Data Selection for the table view...
            dataToRefresh="SELECT Parts_id, Value, Quantity, Voltage, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Capacitor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Value";
        break;

        case 2:
            //Si Item number ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
               FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Item_number", "Capacitor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Supplier", "Capacitor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Mounting", "Capacitor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Package", "Capacitor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Value", "Capacitor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Voltage", "Capacitor", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Tolerance", "Capacitor", comboBox_filter_tolerance);

            // Data Selection for the table view...
            dataToRefresh="SELECT Parts_id, Value, Quantity, Voltage, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Capacitor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Value ";
            break;

        case 3:
            //Si l'element ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
               FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Item_number", "Capacitor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Supplier", "Capacitor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Mounting", "Capacitor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Package", "Capacitor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Value", "Capacitor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Voltage", "Capacitor", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Tolerance", "Capacitor", comboBox_filter_tolerance);

            // Data Selection for the table view...
            dataToRefresh="SELECT Parts_id, Value, Quantity, Voltage, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Capacitor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Value ";
            break;

        case 4:
            //Si l'element ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
               FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Item_number", "Capacitor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Supplier", "Capacitor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Mounting", "Capacitor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Package", "Capacitor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Value", "Capacitor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Voltage", "Capacitor", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Tolerance", "Capacitor", comboBox_filter_tolerance);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Voltage, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Capacitor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Value ";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }

    else if(componentToFilter==Connector){

        switch(ListFilterCombobox.length()){

        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Item_number", "Connector", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Supplier", "Connector", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Reference", "Connector", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Contacts")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Contacts", "Connector", comboBox_filter_contacts);

            if(ListFilterCombobox.indexOf("Spacing")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Spacing", "Connector", comboBox_filter_spacing);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number FROM Parts WHERE Component='Connector' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            //Si Item number ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Item_number","Connector",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Supplier","Connector",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Reference","Connector",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Contacts")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Contacts","Connector",comboBox_filter_contacts);

            if(ListFilterCombobox.indexOf("Spacing")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Spacing","Connector",comboBox_filter_spacing);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number FROM Parts WHERE Component='Connector' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            //Si Item number ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Connector",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Connector",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Connector",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Contacts")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Contacts","Connector",comboBox_filter_contacts);

            if(ListFilterCombobox.indexOf("Spacing")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Spacing","Connector",comboBox_filter_spacing);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number FROM Parts WHERE Component='Connector' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            //Si l'element ne fait pas partie de la liste on charge la combo et sinon on n'y touche pas...
            if(ListFilterCombobox.indexOf("Item_number")==-1)
               FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Item_number", "Capacitor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_FourItem(SelectFilteredData_FourItem, "Supplier", "Capacitor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Connector",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Contacts")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Contacts","Connector",comboBox_filter_contacts);

            if(ListFilterCombobox.indexOf("Spacing")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Spacing","Connector",comboBox_filter_spacing);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Contacts, Spacing, Description, Supplier, Item_number FROM Parts WHERE Component='Connector' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }

    else if(componentToFilter==Diode){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Diode",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Diode",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Diode",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Diode",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Diode",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Diode",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Power","Diode",comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Diode",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Diode",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Power, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Diode' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Item_number","Diode",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Supplier","Diode",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Mounting","Diode",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Package","Diode",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Reference","Diode",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Type","Diode",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Power","Diode",comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Voltage","Diode",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Current","Diode",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Power, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Diode' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Diode",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Diode",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Diode",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Diode",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Diode",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Diode",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Power","Diode",comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Voltage","Diode",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Current","Diode",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Power, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Diode' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Diode",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Diode",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Diode",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Diode",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Diode",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Diode",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Power","Diode",comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Voltage","Diode",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Current","Diode",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Power, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Diode' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }

    else if(componentToFilter==Fuse){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Fuse",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Fuse",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Fuse",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Fuse",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Fuse",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Fuse",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Fuse",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Fuse",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Fuse' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Item_number","Fuse",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Supplier","Fuse",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Mounting","Fuse",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Package","Fuse",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Reference","Fuse",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Type","Fuse",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Voltage","Fuse",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Current","Fuse",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Fuse' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Fuse",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Fuse",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Fuse",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Fuse",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Fuse",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Fuse",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Voltage","Fuse",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Current","Fuse",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Fuse' AND  "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Fuse",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Fuse",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Fuse",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Fuse",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Fuse",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Fuse",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Voltage","Fuse",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Current","Fuse",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Fuse' AND  "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }

    else if(componentToFilter==Inductor){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Inductor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Inductor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Inductor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Inductor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Inductor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Inductor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Inductor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Inductor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Inductor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Value";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Inductor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Inductor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Inductor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Inductor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Inductor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Inductor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Inductor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Inductor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Inductor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Value";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Inductor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Inductor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Inductor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Inductor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Inductor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Inductor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Inductor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Inductor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Inductor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Value";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Inductor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Inductor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Inductor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Inductor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Inductor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Inductor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Inductor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Inductor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Inductor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Value";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }

    else if(componentToFilter==Integrated_Circuit){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Integrated Circuit", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Integrated Circuit", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Integrated Circuit", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Integrated Circuit", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Integrated Circuit", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Integrated Circuit", comboBox_filter_type);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Description, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Integrated Circuit' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Item_number","Integrated Circuit", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Supplier","Integrated Circuit", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Mounting","Integrated Circuit", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Package","Integrated Circuit", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Reference","Integrated Circuit", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Type","Integrated Circuit", comboBox_filter_type);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Description, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Integrated Circuit' AND  "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Integrated Circuit", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Integrated Circuit", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Integrated Circuit", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Integrated Circuit", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Integrated Circuit", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Integrated Circuit", comboBox_filter_type);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Description, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Integrated Circuit' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Integrated Circuit", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Integrated Circuit", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Integrated Circuit", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Integrated Circuit", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Integrated Circuit", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Integrated Circuit", comboBox_filter_type);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Description, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Integrated Circuit' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }

    else if(componentToFilter==Led){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Led", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Led", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Led", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Led", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Led", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Color")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Color","Led", comboBox_filter_color);

            if(ListFilterCombobox.indexOf("Diameter")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Diameter","Led", comboBox_filter_diameter);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Color, Diameter, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Led' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Led", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Led", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Led", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Led", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Led", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Color")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Color","Led", comboBox_filter_color);

            if(ListFilterCombobox.indexOf("Diameter")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Diameter","Led", comboBox_filter_diameter);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Color, Diameter, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Led' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Led", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Led", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Led", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Led", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Led", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Color")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Color","Led", comboBox_filter_color);

            if(ListFilterCombobox.indexOf("Diameter")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Diameter","Led", comboBox_filter_diameter);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Color, Diameter, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Led' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Led", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Led", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Led", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Led", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Led", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Color")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Color","Led", comboBox_filter_color);

            if(ListFilterCombobox.indexOf("Diameter")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Diameter","Led", comboBox_filter_diameter);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Color, Diameter, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Led' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }
    else if(componentToFilter==Quartz){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Quartz", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Quartz", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Quartz", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Quartz", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Value","Quartz", comboBox_filter_value);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Quartz' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Value";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Quartz", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Quartz", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Quartz", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Quartz", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Value","Quartz", comboBox_filter_value);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Quartz' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Value";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Quartz", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Quartz", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Quartz", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Quartz", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Value","Quartz", comboBox_filter_value);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Quartz' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Value";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Quartz", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Quartz", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Quartz", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Quartz", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Value","Quartz", comboBox_filter_value);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Quartz' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Value";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }
    else if(componentToFilter==Relay){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Relay", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Relay", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Relay", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Relay", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Relay", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Relay", comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Relay", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Relay", comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Relay' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Relay", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Relay", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Relay", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Relay", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Relay", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Relay", comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Relay", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Relay", comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Relay' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Relay", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Relay", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Relay", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Relay", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Relay", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Relay", comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Relay", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Relay", comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Relay' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Relay", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Relay", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Relay", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Relay", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Relay", comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Relay", comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Relay", comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Relay", comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Relay' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }
    else if(componentToFilter==Resistor){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Item_number", "Resistor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Supplier", "Resistor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Mounting", "Resistor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Package", "Resistor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Value", "Resistor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Power", "Resistor", comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem, "Tolerance", "Resistor", comboBox_filter_tolerance);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Power, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Resistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Value";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Item_number", "Resistor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Supplier", "Resistor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Mounting", "Resistor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Package", "Resistor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Value", "Resistor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Power", "Resistor", comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem, "Tolerance", "Resistor", comboBox_filter_tolerance);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Power, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Resistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Value";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Item_number", "Resistor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Supplier", "Resistor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Mounting", "Resistor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Package", "Resistor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Value", "Resistor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Power", "Resistor", comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Tolerance", "Resistor", comboBox_filter_tolerance);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Power, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Resistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Value";
            break;


        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Item_number", "Resistor", ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Supplier", "Resistor", ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Mounting", "Resistor", ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Package", "Resistor", ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Value")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Value", "Resistor", comboBox_filter_value);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Power", "Resistor", comboBox_filter_power);

            if(ListFilterCombobox.indexOf("Tolerance")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem, "Tolerance", "Resistor", comboBox_filter_tolerance);

            dataToRefresh="SELECT Parts_id, Value, Quantity, Power, Tolerance, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Resistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Value";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }
    else if(componentToFilter==Switch){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Switch",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Switch",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Switch",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Switch",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Switch",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Switch",comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Switch",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Switch",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Switch' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Switch",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Switch",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Switch",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Switch",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Switch",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Switch",comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Switch",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Switch",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Switch' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Switch",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Switch",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Switch",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Switch",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Switch",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Switch",comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Switch",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Switch",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Switch' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Switch",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Switch",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Switch",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Switch",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Switch",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Configuration")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Configuration","Switch",comboBox_filter_configuration);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Switch",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Switch",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Configuration, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Switch' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
                    maxItemMessage();
            break;
        }
    }
    else if(componentToFilter==Transformator){

        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Transformator",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Transformator",ui->comboBox_filter_supplier);

            //if(ListFilterCombobox.indexOf("Mounting")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Transformator",ui->comboBox_filter_mounting);

            //if(ListFilterCombobox.indexOf("Package")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Transformator",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Transformator",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Transformator",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Power","Transformator",comboBox_filter_power);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Voltage, Power, Supplier, Item_number FROM Parts WHERE Component='Transformator' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Transformator",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Transformator",ui->comboBox_filter_supplier);

            //if(ListFilterCombobox.indexOf("Mounting")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Transformator",ui->comboBox_filter_mounting);

            //if(ListFilterCombobox.indexOf("Package")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Transformator",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Transformator",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Transformator",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Power","Transformator",comboBox_filter_power);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Voltage, Power, Supplier, Item_number FROM Parts WHERE Component='Transformator' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Transformator",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Transformator",ui->comboBox_filter_supplier);

            //if(ListFilterCombobox.indexOf("Mounting")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Transformator",ui->comboBox_filter_mounting);

            //if(ListFilterCombobox.indexOf("Package")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Transformator",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Transformator",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Transformator",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Power","Transformator",comboBox_filter_power);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Voltage, Power, Supplier, Item_number FROM Parts WHERE Component='Transformator' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        case 4:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Transformator",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Transformator",ui->comboBox_filter_supplier);

            //if(ListFilterCombobox.indexOf("Mounting")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Transformator",ui->comboBox_filter_mounting);

            //if(ListFilterCombobox.indexOf("Package")==-1)
              //  FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Transformator",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Transformator",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Transformator",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Power")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Power","Transformator",comboBox_filter_power);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Voltage, Power, Supplier, Item_number FROM Parts WHERE Component='Transformator' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' AND "+ListFilterCombobox[3]+"='"+ListFilterData[3]+"' ORDER BY Reference";
            break;

        default:
            maxItemMessage();
            break;
        }
    }
    else if(componentToFilter==Transistor)
    {
        switch(ListFilterCombobox.length()){
        case 1:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Item_number","Transistor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Supplier","Transistor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Mounting","Transistor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Package","Transistor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Reference","Transistor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Type","Transistor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Voltage","Transistor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_OneItem(SelectFilteredData_OneItem,"Current","Transistor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Transistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' ORDER BY Reference";
            break;

        case 2:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Item_number","Transistor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Supplier","Transistor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Mounting","Transistor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Package","Transistor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Reference","Transistor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Type","Transistor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Voltage","Transistor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_TwoItem(SelectFilteredData_TwoItem,"Current","Transistor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Transistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' ORDER BY Reference";
            break;

        case 3:
            if(ListFilterCombobox.indexOf("Item_number")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Item_number","Transistor",ui->comboBox_filter_item_number);

            if(ListFilterCombobox.indexOf("Supplier")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Supplier","Transistor",ui->comboBox_filter_supplier);

            if(ListFilterCombobox.indexOf("Mounting")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Mounting","Transistor",ui->comboBox_filter_mounting);

            if(ListFilterCombobox.indexOf("Package")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Package","Transistor",ui->comboBox_filter_package);

            if(ListFilterCombobox.indexOf("Reference")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Reference","Transistor",comboBox_filter_reference);

            if(ListFilterCombobox.indexOf("Type")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Type","Transistor",comboBox_filter_type);

            if(ListFilterCombobox.indexOf("Voltage")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Voltage","Transistor",comboBox_filter_voltage);

            if(ListFilterCombobox.indexOf("Current")==-1)
                FillFilteredComboBox_ThreeItem(SelectFilteredData_ThreeItem,"Current","Transistor",comboBox_filter_current);

            dataToRefresh="SELECT Parts_id, Reference, Quantity, Type, Voltage, Current, Package, Mounting, Supplier, Item_number FROM Parts WHERE Component='Transistor' AND "+ListFilterCombobox[0]+"='"+ListFilterData[0]+"' AND "+ListFilterCombobox[1]+"='"+ListFilterData[1]+"' AND "+ListFilterCombobox[2]+"='"+ListFilterData[2]+"' ORDER BY Reference";
            break;

        default:
            maxItemMessage();
            break;
        }
    }
    emit notifyRefreshTable(dataToRefresh);
}

void Form_filter::maxItemMessage(){

    QMessageBox::warning(this,tr(" "),tr("To match items selected! Maximun 4 Parameters!!!     "));
}
