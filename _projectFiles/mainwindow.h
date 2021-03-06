#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>

#include "database.h"
#include "choose.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_closeButton_clicked();
    void on_addDatabase_clicked();
    void on_actionWy_wietl_baz_danych_triggered();
    void on_pushButton_2_clicked();
public slots:
    void showMainWindow();
private:
    Ui::MainWindow *ui;
    void setConnectionString(QString);
    void db_placeholder();
    QString dbPath;
    database *db;
    Choose *choose;
};

#endif // MAINWINDOW_H
