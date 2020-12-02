// 15/07/2019
// Git commit on 27/10/19
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


// Last Update 23/02/19: DataBase connection update
// Update from 06/03/19: Refresch Table view & Filter after that a component has been saved.
// Update from 09/03/19: For store table, combobox are filled with elements from Parts.
// Update from 02/04/19: Capacitor Fiter completed, posibility to filtre up to 3 parameters.
// Update from 04/04/19: Rest Filter completed, call function set_combobox
// Update from 25/05/2019: SelectData String arguments corrected (%1 and %2)
// Update from
// Update from 25/11/19: Added Picture at component connector
// padate form 21/12/19: Search Item number combobox will refresched, and if no component is choosen, no message will be displayed
// Update from 09/09/20: Fuse part added
