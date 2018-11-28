#include "choose.h"
#include "ui_choose.h"
#include "QtMath"
Choose::Choose(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
}

Choose::~Choose()
{
    delete ui;
}

void Choose::on_wlewek_kolo_button_clicked()
{
    ui->wlewek_type->setText("Koło");
    ui->wlewek_promien->setEnabled(1);
    ui->wlewek_a->setDisabled(1);

}

void Choose::on_wlewek_prostokat_button_clicked()
{
    ui->wlewek_type->setText("Prostokąt");
    ui->wlewek_promien->setDisabled(1);
    ui->wlewek_a->setEnabled(1);

}

void Choose::on_wlewek_zmienObjetosc_clicked()
{
    ui->wlewek_objetosc->setEnabled(1);
}

void Choose::on_wlewek_oblicz_button_clicked()
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
    if(przekroj=="Koło"){
        wynik = (4*pretV)/(M_PI*qPow(wymiarPromien,2));
    }
    else{
        wynik= pretV/(qPow(wymiarA,2));
    }
    if(wynik>0){
        ui->wlewek_wynik->setText(QString::number(wynik)+" mm");
    }
    else
    {
        ui->wlewek_wynik->setText("Nieprawidłowe dane");
    }
}
