// 31/05/2019
#ifndef FORM_FILTER_H
#define FORM_FILTER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QList>
#include <qsqlquerymodel.h>

namespace Ui {
class Form_filter;
}

class Form_filter : public QWidget
{
    Q_OBJECT

public:
    explicit Form_filter(QWidget *parent = nullptr);
    ~Form_filter();

    QList<QString> ListFilterCombobox, ListFilterData;

    // ListFiltreCombobox contient les noms des différentes combobox selectionéés
    // ListFiltreData contient le contenu des différentes combobox qui ont ete selectionnéés

    enum component {Choose=0, Capacitor, Connector, Diode, Inductor, Integrated_Circuit, Led, Quartz, Relay, Resistor, Transistor, Fuse, Switch, Transformator} componentToFilter;

    Ui::Form_filter *ui;
    QLabel *Label_filter_value = new QLabel("Value");
    QLabel *Label_filter_reference = new QLabel("Reference");
    QLabel *Label_filter_voltage =  new QLabel("Voltage");
    QLabel *Label_filter_tolerance = new QLabel("Tolerance");
    QLabel *Label_filter_power = new QLabel("Power");
    QLabel *Label_filter_current = new QLabel("Current");
    QLabel *Label_filter_type = new QLabel("Type");
    QLabel *Label_filter_contacts = new QLabel("Contacts");
    QLabel *Label_filter_spacing = new QLabel("Spacing");
    QLabel *Label_filter_color = new QLabel("Color");
    QLabel *Label_filter_diameter  = new QLabel("Diameter");
    QLabel *Label_filter_configuration = new QLabel("Configuration");

    QComboBox *comboBox_filter_value = new QComboBox;
    QComboBox *comboBox_filter_voltage = new QComboBox;
    QComboBox *comboBox_filter_current = new QComboBox;
    QComboBox *comboBox_filter_tolerance = new QComboBox;
    QComboBox *comboBox_filter_power = new QComboBox;
    QComboBox *comboBox_filter_type = new QComboBox;
    QComboBox *comboBox_filter_reference = new QComboBox;
    QComboBox *comboBox_filter_contacts = new QComboBox;
    QComboBox *comboBox_filter_spacing = new QComboBox;
    QComboBox *comboBox_filter_color = new QComboBox;
    QComboBox *comboBox_filter_diameter = new QComboBox;
    QComboBox *comboBox_filter_configuration = new QComboBox;

    QString SelectData = "SELECT DISTINCT %1 FROM Parts WHERE Component='%2' ORDER BY %1";

    void set_capacitor_filter();
    void set_connector_filter();
    void set_diode_filter();
    void set_fuse_filter();
    void set_inductor_filter();
    void set_integrated_circuit_filter();
    void set_led_filter();
    void set_quartz_filter();
    void set_relay_filter();
    void set_resistor_filter();
    void set_switch_filter();
    void set_transformator_filter();
    void set_transistor_filter();
    void clearlists();

    void FillComboBox(QString _String, QString _Item, QString _Component, QComboBox *Combobox);

    void FillFilteredComboBox_OneItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox);
    void FillFilteredComboBox_TwoItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox);
    void FillFilteredComboBox_ThreeItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox);
    void FillFilteredComboBox_FourItem(QString _String, QString _Item, QString _Component, QComboBox *Combobox);

    void fill_capacitor_combobox();
    void fill_connector_combobox();
    void fill_diode_combobox();
    void fill_fuse_combobox();
    void fill_inductor_combobox();
    void fill_integrated_circuit_combobox();
    void fill_led_combobox();
    void fill_quartz_combobox();
    void fill_relay_combobox();
    void fill_resistor_combobox();
    void fill_switch_combobox();
    void fill_transformator_combobox();
    void fill_transistor_combobox();

    void maxItemMessage();

private slots:

    void on_pushButton_filter_reset_clicked();
    void on_pushButton_filter_activate_filter_clicked();

    void on_comboBox_filter_reference_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_value_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_type_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_power_currentTextChanged(const  QString &arg1);
    void on_comboBox_filter_voltage_currentTextChanged(const  QString &arg1);
    void on_comboBox_filter_current_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_tolerance_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_contacts_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_spacing_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_color_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_diameter_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_configuration_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_package_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_mounting_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_supplier_currentTextChanged(const QString &arg1);
    void on_comboBox_filter_item_number_currentTextChanged(const QString &arg1);

signals:
    void notifyRefreshTable(QString dataToRefresh);
};

#endif // FORM_FILTER_H
