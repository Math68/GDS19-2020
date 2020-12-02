// 31/05/2019
#ifndef DIALOG_STORE_WINDOWS_H
#define DIALOG_STORE_WINDOWS_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>

enum Components{Capacitor=0, Connector, Diode, Inductor, IntegratedCircuit, Led, Quartz, Relay, Resistor, Transistor, Fuse, Switch, Transformator};

static Components SelectedComponent;

namespace Ui {
class Dialog_store_windows;
}

class Dialog_store_windows : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog_store_windows(QWidget *parent = nullptr);
    ~Dialog_store_windows();

    void set_capacitor_store_window();
    void set_connector_store_window();
    void set_diode_store_window();
    void set_fuse_store_window();
    void set_inductor_store_window();
    void set_integrated_circuit_store_window();
    void set_led_store_window();
    void set_quartz_store_window();
    void set_relay_store_window();
    void set_resistor_store_window();
    void set_switch_store_window();
    void set_transformator_store_window();
    void set_transistor_store_window();

    void save_capacitor();
    void save_connector();
    void save_diode();
    void save_fuse();
    void save_inductor();
    void save_integrated_circuit();
    void save_led();
    void save_quartz();
    void save_relay();
    void save_resistor();
    void save_switch();
    void save_transformator();
    void save_transistor();

    void FillComboBox(QString _String, QString _Item, QString _Component, QComboBox *Combobox);
    void FillComboBoxOneItem(QString _String, QString _Item, QComboBox *Combobox);

public slots:
    void on_pushButton_store_save_clicked();
    void on_pushButton_store_cancel_clicked();

signals:
    void notify_component_has_been_saved(QString _NewItemNumber);

private:
    Ui::Dialog_store_windows *ui;

    QLabel *Label_store_power = new QLabel("Power");
    QLabel *Label_store_tolerance = new QLabel("Tolerance");
    QLabel *Label_store_voltage = new QLabel("Voltage");
    QLabel *Label_store_type = new QLabel("Type");
    QLabel *Label_store_current = new QLabel("Current");
    QLabel *Label_store_reference = new QLabel("Reference");
    QLabel *Label_store_description = new QLabel("Description");
    QLabel *Label_store_spacing = new QLabel("Spacing");
    QLabel *Label_store_contacts = new QLabel("Contacts");
    QLabel *Label_store_color = new QLabel("Color");
    QLabel *Label_store_configuration = new QLabel("Configuration");
    QLabel *Label_store_diameter = new QLabel("Diameter");

    QLineEdit *Lineedit_store_description;

    QComboBox *ComboBox_store_spacing;
    QComboBox *ComboBox_store_contacts;

    QComboBox *Combobox_store_power;
    QComboBox *Combobox_store_tolerance;
    QComboBox *Combobox_store_voltage;
    QComboBox *ComboBox_store_type;
    QComboBox *Combobox_store_current;
    QComboBox *Combobox_store_color;
    QComboBox *Combobox_store_diameter;
    QComboBox *Combobox_store_configuration;

    // "SELECT DISTINCT Voltage FROM Parts WHERE Component='Capacitor' ORDER BY Voltage"
    //QString SelectData="SELECT DISTINCT %1 FROM parts WHERE %2 != 'NULL' ORDER BY %1";
    QString SelectData="SELECT DISTINCT %1 FROM parts WHERE Component = '%2' ORDER BY %1";
    //SELECT DISTINCT Mounting FROM parts ORDER BY Mounting");
    QString SelectPartsData="SELECT DISTINCT %1 FROM parts ORDER BY %1";
};

#endif // DIALOG_STORE_WINDOWS_H
