#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include "bazadanych.h"
namespace Ui {
class database;
}

class database : public QWidget
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = nullptr);
    ~database();
signals:
    void closeWindow();
private slots:
    void on_closeButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::database *ui;
    void setDbPath();
    QString dbPath;
    BazaDanych * bazaDanych;
    void refresh();
};

#endif // DATABASE_H
