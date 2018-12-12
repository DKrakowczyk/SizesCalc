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

void database::refresh()
{
    ui->tableView->setModel(bazaDanych->getData("select id, srednica_wlewka,wysokosc_wlewka, dlugosc_preta, V_odpadu, przekroj_preta, promien_preta, bok_preta from wyniki"));
    ui->tableView->hideColumn(0);
}

void database::setDbPath()
{
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


void database::on_tableView_doubleClicked(const QModelIndex &index)
{
    int ind = index.row()+1;

    QString id = index.siblingAtColumn(0).data().toString();
    bazaDanych->deleteRow(id.toInt());
    QMessageBox::information(this, tr("Komunikat bazy danych"),tr("Element with id %1 has been successfully removed!").arg(ind));
    this->refresh();
    this->repaint();
}
