#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>

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


    void on_wlewek_oblicz_button_clicked();

private:
    Ui::Choose *ui;
};

#endif // CHOOSE_H
