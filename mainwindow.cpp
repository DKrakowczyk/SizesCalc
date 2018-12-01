#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db_placeholder();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::setConnectionString(QString str)
{
    QFile file;
    file.setFileName("con_string.txt");

    if (file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Komunikat serwera"), tr("Pomyślnie zapisano ścieżkę bazy danych"));
        QTextStream stream(&file);
        stream << str;
    }
    file.close();
}

void MainWindow::db_placeholder()
{
    QFile file;
    file.setFileName("con_string.txt");

    if (file.open((QIODevice::ReadOnly))) {
        QTextStream in(&file);
        QString placeholder = in.readLine();

        if (placeholder != "") {
            ui->dbPath->setText(placeholder);
        }
        else {
            ui->dbPath->setText("Wybierz bazę danych...");
        }
    }
    file.close();
}

void MainWindow::on_addDatabase_clicked()
{
    dbPath = QFileDialog::getOpenFileName(
        this,
        tr("Wybierz Bazę danych"),
        "../",
        "Pliki Bazy SQLITE (*.db)");

    ui->dbPath->setText(dbPath);
    setConnectionString(dbPath);
}

void MainWindow::on_actionWy_wietl_baz_danych_triggered()
{
    db = new database(this);
    connect(db, SIGNAL(closeWindow()), this, SLOT(showMainWindow()));
    ui->centralWidget->hide();
    db->show();
}
void MainWindow::showMainWindow()
{
    ui->centralWidget->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    choose = new Choose(this);
    choose->show();
}
