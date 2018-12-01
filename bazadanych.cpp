#include "bazadanych.h"

BazaDanych::BazaDanych(QString type,QString path):dbType(type),pathToDbFile(path)
{
startDb();
}

void BazaDanych::startDb(){
    mydb = QSqlDatabase::addDatabase(dbType);
    mydb.setDatabaseName(pathToDbFile);
    if(!mydb.open()){
       status = "błąd połączenia z bazą danych...";
    } else{
       status = "Połączono z bazą danych!  |  Podwójne klinięcie w rekord kasuje element z bazy";
    }
}

QString BazaDanych::getStatus(){
    return status;
}

QSqlQueryModel * BazaDanych::getData(QString q){
        QSqlQueryModel *  model = new QSqlQueryModel();
        QSqlQuery * query = new QSqlQuery(mydb);
        query->prepare(q);
        query->exec();
        model->setQuery(*query);
        return model;
}

void BazaDanych::deleteRow(int row){
    QSqlQuery * query = new QSqlQuery(mydb);
    query->prepare("delete from wyniki where ID = :id");
    query->bindValue(":id", row);
    query->exec();
}

void BazaDanych::addElement(QString srednica, QString wysokosc, QString dlugosc, QString odpad, QString przekroj, QString promien, QString bok)
{
    QSqlQuery * query = new QSqlQuery(mydb);
    query->prepare("INSERT INTO wyniki(srednica_wlewka,wysokosc_wlewka, dlugosc_preta, V_odpadu, przekroj_preta, promien_preta, bok_preta) VALUES(:srednica,:wysokosc,:dlugosc,:odpad,:przekroj,:promien,:bok)");

    query->bindValue(":srednica", srednica);
    query->bindValue(":wysokosc", wysokosc);
    query->bindValue(":dlugosc", dlugosc);
    query->bindValue(":odpad", odpad);
    query->bindValue(":przekroj", przekroj);
    query->bindValue(":promien", promien);
    query->bindValue(":bok", bok);
    query->exec();
}

BazaDanych::~BazaDanych(){
    mydb.close();
}

