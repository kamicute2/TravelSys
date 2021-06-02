#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <client.h>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    int ReturnValue();
    int ReturnId();
    QString ReturnName();
    QString ReturnPass();
    QString ReturnTypeHousing();
    QString ReturnCountry();
    QString ReturnPrice();
    bool ReturnAllInclusive();
    QString ReturnTour();
    QString ReturnAdditional();

    void SetValue(int typeTour);
    void SetId(int id);
    void SetName(QString name);
    void SetPass(QString pass);
    void SetTypeHousing(QString typeHousing);
    void SetCountry(QString country);
    void SetPrice(QString price);
    void SetAllInclusive(bool allInclusive);
    void SetTour(QString tour);
    void SetAdditional(QString additional);

private slots:
    void on_typeTourBox_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    void hideAll();

    Ui::Form *ui;
};

#endif // FORM_H
