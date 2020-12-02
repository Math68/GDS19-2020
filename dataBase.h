// 31/05/2019
#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class DataBase : public QObject
{
    Q_OBJECT

public:
    QSqlDatabase Gds_DataBase ;

    bool OpenConnection();
    void CloseConnection();

public:
    explicit DataBase(QObject *parent = nullptr);
};

#endif // DATABASE_H
