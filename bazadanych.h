#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include <QtSql>
#include <QObject>
#include <QWidget>
#include <QFile>
class BazaDanych
{
private:
    QString dbType,pathToDbFile,status;
    QSqlDatabase mydb;
public:
    BazaDanych(QString,QString);
    ~BazaDanych();
    void startDb();
    QString getStatus();
    QSqlQueryModel * getData(QString);
    void deleteRow(int);
    void changeData(QString,QString,QString);
    bool userExist(QString,QString);
    void addElement(QString, QString, QString, QString, QString, QString, QString);
};

#endif // BAZADANYCH_H
