// 31/05/2019
#include "dataBase.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{
}

bool DataBase::OpenConnection()
{
    Gds_DataBase = QSqlDatabase::addDatabase("QSQLITE");
    Gds_DataBase.setDatabaseName("M:/DataBase/SQLiteStudio/Gds.db");

    if(!Gds_DataBase.open())
        return false;
    else
        return true;
}

void DataBase::CloseConnection()
{
    Gds_DataBase.close();
    Gds_DataBase.removeDatabase(QSqlDatabase::defaultConnection);
}
