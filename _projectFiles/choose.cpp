#include "choose.h"
#include "ui_choose.h"
#include "QtMath"

#include "bazadanych.h"
Choose::Choose(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
    oblicz();
    oblicz_wysokosc();
    ui->wlewek_prostokat_button->setStyleSheet("border-color:#023303;background-color:#347535;");
    ui->pret_kwadrat->setStyleSheet("border-color:#023303;background-color:#347535;");
}

Choose::~Choose()
{
    delete ui;
}

void Choose::on_wlewek_kolo_button_clicked()
{
    ui->wlewek_type->setText("Koło");
    ui->wlewek_promien->setEnabled(1);
    ui->wlewek_kolo_button->setStyleSheet("border-color:#023303;background-color:#347535;");
    ui->wlewek_prostokat_button->setStyleSheet("background-color:none;");
    ui->wlewek_a->setDisabled(1);
    oblicz();
}

void Choose::on_wlewek_prostokat_button_clicked()
{
    ui->wlewek_type->setText("Kwadrat");
    ui->wlewek_promien->setDisabled(1);
    ui->wlewek_kolo_button->setStyleSheet("background-color:none;");
    ui->wlewek_prostokat_button->setStyleSheet("border-color:#023303;background-color:#347535;");
    ui->wlewek_a->setEnabled(1);
    oblicz();
}

void Choose::on_wlewek_zmienObjetosc_clicked()
{
    if(ui->wlewek_objetosc->isEnabled())
        ui->wlewek_objetosc->setDisabled(1);
    else
        ui->wlewek_objetosc->setEnabled(1);
    oblicz();
}
//Update final score when value is changed
void Choose::on_wlewek_srednica_valueChanged(const QString &arg1){oblicz();}
void Choose::on_wlewek_wysokosc_valueChanged(const QString &arg1){oblicz();}
void Choose::on_wlewek_promien_valueChanged(const QString &arg1){oblicz();}
void Choose::on_wlewek_a_valueChanged(const QString &arg1){oblicz();}
void Choose::on_wlewek_objetosc_valueChanged(const QString &arg1){oblicz();}

void Choose::oblicz()
{
    double wymiarPromien = ui->wlewek_promien->value();
    double wymiarA = ui->wlewek_a->value();
    double srednica = ui->wlewek_srednica->value();
    double wysokosc = ui->wlewek_wysokosc->value();
    double odpad = ui->wlewek_objetosc->value();
    double wlewekObjetosc = (M_PI * qPow(srednica,2))*wysokosc/4;
    double pretV = wlewekObjetosc - odpad;
    double wynik;
    QString przekroj = ui->wlewek_type->text();
    if(przekroj=="Koło")
    {
        wynik = (4*pretV)/(M_PI*qPow(wymiarPromien,2));
    }
    else
    {
        wynik= pretV/(qPow(wymiarA,2));
    }
    if(wynik>0)
    {
        ui->wlewek_wynik->setValue(wynik);
        ui->wlewek_wynik->setStyleSheet("border-color:#023303;background-color:#347535;");
        ui->wlewek_wynik->setSuffix(" mm");
    }
    else
    {
        ui->wlewek_wynik->setValue(0);
        ui->wlewek_wynik->setStyleSheet("border-color:#3a0501;background-color:#99140a;");
        ui->wlewek_wynik->setSuffix(" BŁĄD");
    }
}
//------------------------------------------------------------------------------------------
void Choose::on_pret_kolo_clicked()
{
    ui->pret_type->setText("Koło");
    ui->pret_promien->setEnabled(1);
    ui->pret_kolo->setStyleSheet("border-color:#023303;background-color:#347535;");
    ui->pret_kwadrat->setStyleSheet("background-color:none;");
    ui->pret_a->setDisabled(1);
    oblicz_wysokosc();
}

void Choose::on_pret_kwadrat_clicked()
{
    ui->pret_type->setText("Kwadrat");
    ui->pret_promien->setDisabled(1);
    ui->pret_kolo->setStyleSheet("background-color:none;");
    ui->pret_kwadrat->setStyleSheet("border-color:#023303;background-color:#347535;");
    ui->pret_a->setEnabled(1);
    oblicz_wysokosc();
}

void Choose::on_pret_zmienObjetosc_clicked()
{
    if(ui->pret_objetosc->isEnabled())
        ui->pret_objetosc->setDisabled(1);
    else
        ui->pret_objetosc->setEnabled(1);
    oblicz_wysokosc();
}

void Choose::oblicz_wysokosc()
{
    double wymiarPromien = ui->pret_promien->value();
    double wymiarA = ui->pret_a->value();
    double srednica = ui->pret_srednica->value();
    double wysokosc = ui->pret_wysokosc->value();
    double odpad = ui->pret_objetosc->value();
    double wlewekObjetosc = (M_PI * qPow(srednica,2))*wysokosc/4;
    double wynik,wlewekV, h;
    QString przekroj = ui->pret_type->text();
    if(przekroj=="Koło")
    {
        wynik = (M_PI* qPow(wymiarPromien,2)*wysokosc)/4;
    }
    else
    {
        wynik= qPow(wymiarA,2)*wysokosc;
    }

    wlewekV = wynik+odpad;
    h = (4*wlewekV)/(M_PI*qPow(srednica,2));


    if(ui->pret_a->value()==0.0 || ui->pret_promien->value()==0.0 || ui->pret_srednica->value()==0.0 || ui->pret_wysokosc->value()==0.0 )
    {
        ui->pret_wynik->setValue(0);
        ui->pret_wynik->setStyleSheet("border-color:#3a0501;background-color:#99140a;");
        ui->pret_wynik->setSuffix(" BŁĄD");
    }
    else
    {
        ui->pret_wynik->setValue(h);
        ui->pret_wynik->setStyleSheet("border-color:#023303;background-color:#347535;");
        ui->pret_wynik->setSuffix(" mm");
    }
}
//Update final score when value is changed
void Choose::on_pret_promien_valueChanged(const QString &arg1){oblicz_wysokosc();}
void Choose::on_pret_a_valueChanged(const QString &arg1){oblicz_wysokosc();}
void Choose::on_pret_srednica_valueChanged(const QString &arg1){oblicz_wysokosc();}
void Choose::on_pret_wysokosc_valueChanged(const QString &arg1){oblicz_wysokosc();}
void Choose::on_pret_objetosc_valueChanged(const QString &arg1){oblicz_wysokosc();}

void Choose::on_zapisz_dlugosc_clicked()
{
    if(db_placeholder()!="")
    {
        BazaDanych* baza = new BazaDanych("QSQLITE", db_placeholder());
        double wymiarPromien = ui->wlewek_promien->value();
        double wymiarA = ui->wlewek_a->value();
        double srednica = ui->wlewek_srednica->value();
        double wysokosc = ui->wlewek_wysokosc->value();
        double odpad = ui->wlewek_objetosc->value();
        QString przekroj = ui->wlewek_type->text();

        if(przekroj=="Koło")
        {
            baza->addElement(QString::number(srednica)+" mm",
                             QString::number(wysokosc)+" mm",
                             QString::number(ui->wlewek_wynik->value())+" mm",
                             QString::number(odpad)+ " mm^3",
                             "KOŁO",
                             QString::number(wymiarPromien)+" mm","-");

            QMessageBox::information(this, tr("Spredsheet"), tr("Successfully saved to the database!"));
        }
        else
        {
            baza->addElement(QString::number(srednica)+" mm",
                             QString::number(wysokosc)+" mm",
                             QString::number(ui->wlewek_wynik->value())+" mm",
                             QString::number(odpad) +" mm^3",
                             "KWADRAT",
                             "-",QString::number(wymiarA)+" mm");

            QMessageBox::information(this, tr("Spredsheet"), tr("Successfully saved to the database!"));
        }
    }
    else
    {
        QMessageBox::information(this, tr("Spredsheet"), tr("Configure the path to the database!"));
    }
}

void Choose::on_zapisz_wysokosc_clicked()
{
    if(db_placeholder()!="")
    {
        BazaDanych* baza = new BazaDanych("QSQLITE", db_placeholder());
        double wymiarPromien = ui->pret_promien->value();
        double wymiarA = ui->pret_a->value();
        double srednica = ui->pret_srednica->value();
        double dlugosc = ui->pret_wysokosc->value();
        double odpad = ui->pret_objetosc->value();
        QString przekroj = ui->pret_type->text();

        if(przekroj=="Koło")
        {
            baza->addElement(QString::number(srednica)+" mm",
                             QString::number(ui->pret_wynik->value())+" mm",
                             QString::number(dlugosc)+" mm",
                             QString::number(odpad)+ " mm^3",
                             "KOŁO",
                             QString::number(wymiarPromien)+" mm","-");

            QMessageBox::information(this, tr("Spredsheet"), tr("Successfully saved to the database!"));
        }
        else
        {
            baza->addElement(QString::number(srednica)+" mm",
                             QString::number(ui->pret_wynik->value())+" mm",
                             QString::number(dlugosc)+" mm",
                             QString::number(odpad) +" mm^3",
                             "KWADRAT",
                             "-",QString::number(wymiarA)+" mm");

            QMessageBox::information(this, tr("Spredsheet"), tr("Successfully saved to the database!"));
        }
    }
    else
    {
        QMessageBox::information(this, tr("Spredsheet"), tr("Configure the path to the database!"));
    }
}

QString Choose::db_placeholder()
{
    QFile file;
    file.setFileName("con_string.txt");
    QString placeholder;
    if (file.open((QIODevice::ReadOnly)))
    {
        QTextStream in(&file);
        placeholder = in.readLine();
    }
    return placeholder;
    file.close();
}
