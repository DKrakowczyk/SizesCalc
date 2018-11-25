#include "database.h"
#include "ui_database.h"

database::database(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
    setDbPath();
    bazaDanych = new BazaDanych("QSQLITE",dbPath);
    ui->label_dbStatus->setText(bazaDanych->getStatus());
    this->refresh();
}

database::~database()
{
    delete bazaDanych;
    delete ui;
}

void database::on_closeButton_clicked()
{
    emit closeWindow();
    this->close();
}

void database::refresh(){
ui->tableView->setModel(bazaDanych->getData("select * from users"));
}

void database::setDbPath(){
    QFile file;
    file.setFileName("con_string.txt");

    if(file.open((QIODevice::ReadOnly)))
    {
        QTextStream in(&file);
        QString con_str = in.readLine();
        if(con_str != "")
        {
            dbPath = con_str;
        }
    }

}

