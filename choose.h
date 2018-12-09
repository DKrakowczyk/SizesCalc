#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include <QMessageBox>
namespace Ui {
class Choose;
}

class Choose : public QWidget
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = nullptr);
    ~Choose();

private slots:
    void on_wlewek_kolo_button_clicked();
    void on_wlewek_prostokat_button_clicked();
    void on_wlewek_zmienObjetosc_clicked();
    void on_wlewek_srednica_valueChanged(const QString &arg1);
    void on_wlewek_wysokosc_valueChanged(const QString &arg1);
    void on_wlewek_promien_valueChanged(const QString &arg1);
    void on_wlewek_a_valueChanged(const QString &arg1);
    void on_wlewek_objetosc_valueChanged(const QString &arg1);
    void on_pret_kolo_clicked();
    void on_pret_kwadrat_clicked();
    void on_pret_zmienObjetosc_clicked();
    void on_pret_promien_valueChanged(const QString &arg1);
    void on_pret_a_valueChanged(const QString &arg1);
    void on_pret_srednica_valueChanged(const QString &arg1);
    void on_pret_wysokosc_valueChanged(const QString &arg1);
    void on_pret_objetosc_valueChanged(const QString &arg1);
    void on_zapisz_dlugosc_clicked();
    void on_zapisz_wysokosc_clicked();

private:
    Ui::Choose *ui;
    void oblicz();
    void oblicz_wysokosc();
    QString db_placeholder();
};

#endif // CHOOSE_H
