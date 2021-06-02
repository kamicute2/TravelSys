#include "form.h"
#include "ui_form.h"
#include "QMessageBox"

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    hideAll();
    ui->radioButton->setChecked(true);
    ui->idLineEdit->setValidator(new QIntValidator(0, 99999));
    ui->priceLineEdit->setValidator(new QIntValidator(0, 99999999));
    QRegularExpression expr(R"([0-9]{4}\s[0-9]{6})");
    ui->passLineEdit->setValidator(new QRegularExpressionValidator(expr));
}

Form::~Form()
{
    delete ui;
}

//---------------Получение значений полей---------------------

int Form::ReturnValue()
{
    switch (ui->typeTourBox->currentIndex())
    {
        case 1:
        {
            return 1;
        }
        case 2:
        {
            return 2;
        }
        case 3:
        {
            return 3;
        }
        default:
        {
            return 0;
        }
    }

}

int Form::ReturnId()
{
    return ui->idLineEdit->text().toInt();
}

QString Form::ReturnName()
{
    return ui->nameLineEdit->text();
}

QString Form::ReturnPass()
{
    return ui->passLineEdit->text();
}

QString Form::ReturnTypeHousing()
{
    if(ui->typeTourBox->currentIndex() == 1)
        return ui->typeHousingLabel_2->text();
    else if (ui->typeTourBox->currentIndex() == 2 || ui->typeTourBox->currentIndex() == 3)
        return ui->typeHousingLineEdit->text();
    else
        return 0;
}

QString Form::ReturnCountry()
{
    if(ui->typeTourBox->currentIndex() == 1)
        return ui->countryBox->currentText();
    else if (ui->typeTourBox->currentIndex() == 2 || ui->typeTourBox->currentIndex() == 3)
        return ui->countryLineEdit->text();
    else
        return 0;
}

QString Form::ReturnPrice()
{
    return ui->priceLineEdit->text();
}

bool Form::ReturnAllInclusive()
{
    if(ui->radioButton->isChecked())
        return true;
    else if(ui->radioButton_2->isChecked())
        return false;
    else
        return NULL;
}

QString Form::ReturnTour()
{
    return ui->tourBox->currentText();
}

QString Form::ReturnAdditional()
{
    if (ui->additionalTextEdit->toPlainText() != "")
        return ui->additionalTextEdit->toPlainText();
    else
        return "--------";
}

//---------------Установка значений полей---------------------

void Form::SetValue(int typeTour)
{
    switch (typeTour)
    {
        case 1:
        {
            ui->typeTourBox->setCurrentIndex(1);
            break;
        }
        case 2:
        {
            ui->typeTourBox->setCurrentIndex(2);
            break;
        }
        case 3:
        {
            ui->typeTourBox->setCurrentIndex(3);
            break;
        }
    }
}

void Form::SetId(int id)
{
    ui->idLineEdit->setText(QString::number(id));
}

void Form::SetName(QString name)
{
    ui->nameLineEdit->setText(name);
}

void Form::SetPass(QString pass)
{
    ui->passLineEdit->setText(pass);
}

void Form::SetTypeHousing(QString typeHousing)
{
    ui->typeHousingLineEdit->setText(typeHousing);
}

void Form::SetCountry(QString country)
{
    if(ui->typeTourBox->currentIndex()==1)
    {
        ui->countryBox->setCurrentText(country);
    }
    else
    {
        ui->countryLineEdit->setText(country);
    }
}

void Form::SetPrice(QString price)
{
    ui->priceLineEdit->setText(price);
}

void Form::SetAllInclusive(bool allInclusive)
{
    if (allInclusive)
        ui->radioButton->setChecked(true);
    else
        ui->radioButton_2->setChecked(true);
}

void Form::SetTour(QString tour)
{
    ui->tourBox->setCurrentText(tour);
}

void Form::SetAdditional(QString additional)
{
    if (additional != "--------")
        ui->additionalTextEdit->setText(additional);
}

//---------------Методы для скрытия ненужного и открытия нужного---------------------

void Form::on_typeTourBox_currentIndexChanged(int index)
{
    switch (index)
    {
        case 0:
        {
            hideAll();
            break;
        }
        case 1:
        {
            hideAll();
            ui->idLabel->show();
            ui->idLineEdit->show();
            ui->nameLabel->show();
            ui->nameLineEdit->show();
            ui->passLabel->show();
            ui->passLineEdit->show();
            ui->countryLabel->show();
            ui->countryBox->show();
            ui->tourLabel->show();
            ui->tourBox->show();
            ui->typeHousingLabel->show();
            ui->typeHousingLabel_2->show();
            ui->allInclusiveLabel->show();
            ui->radioButton->show();
            ui->radioButton_2->show();
            ui->priceLabel->show();
            ui->priceLineEdit->show();
            break;
        }
        case 2:
        {
            hideAll();
            ui->idLabel->show();
            ui->idLineEdit->show();
            ui->nameLabel->show();
            ui->nameLineEdit->show();
            ui->passLabel->show();
            ui->passLineEdit->show();
            ui->countryLabel->show();
            ui->countryLineEdit->show();
            ui->typeHousingLabel->show();
            ui->typeHousingLineEdit->show();
            ui->allInclusiveLabel->show();
            ui->radioButton->show();
            ui->radioButton_2->show();
            ui->priceLabel->show();
            ui->priceLineEdit->show();
            ui->additionalLabel->show();
            ui->additionalTextEdit->show();
            break;
        }
        case 3:
        {
            hideAll();
            ui->idLabel->show();
            ui->idLineEdit->show();
            ui->nameLabel->show();
            ui->nameLineEdit->show();
            ui->passLabel->show();
            ui->passLineEdit->show();
            ui->countryLabel->show();
            ui->countryLineEdit->show();
            ui->tourLabel->show();
            ui->tourBox->show();
            ui->typeHousingLabel->show();
            ui->typeHousingLineEdit->show();
            ui->allInclusiveLabel->show();
            ui->radioButton->show();
            ui->radioButton_2->show();
            ui->priceLabel->show();
            ui->priceLineEdit->show();
            ui->additionalLabel->show();
            ui->additionalTextEdit->show();
            break;
        }
    }
}

void Form::hideAll()
{
    ui->idLabel->hide();
    ui->idLineEdit->hide();
    ui->nameLabel->hide();
    ui->nameLineEdit->hide();
    ui->passLabel->hide();
    ui->passLineEdit->hide();
    ui->countryLabel->hide();
    ui->countryBox->hide();
    ui->countryLineEdit->hide();
    ui->tourLabel->hide();
    ui->tourBox->hide();
    ui->typeHousingLabel->hide();
    ui->typeHousingLabel_2->hide();
    ui->typeHousingLineEdit->hide();
    ui->allInclusiveLabel->hide();
    ui->radioButton->hide();
    ui->radioButton_2->hide();
    ui->priceLabel->hide();
    ui->priceLineEdit->hide();
    ui->additionalLabel->hide();
    ui->additionalTextEdit->hide();
}

//---------------Кнопки boxbutton---------------------

void Form::on_buttonBox_accepted()
{
    int index = ui->typeTourBox->currentIndex();
    switch (index)
    {
        case 0:
        {
            reject();
            break;
        }
        case 1:
        {
            if (ui->idLineEdit->text() == "" || ui->passLineEdit->text() == "" || ui->nameLineEdit->text() == ""
                    || ui->countryBox->currentIndex() == 0 || ui->tourBox->currentIndex() == 0 || ui->priceLineEdit->text() == "")
                QMessageBox::warning(this, "Пустые поля","Заполните все поля! \n",QMessageBox::Ok, QMessageBox::Ok);
            else if(ui->passLineEdit->text().length() != 11)
                QMessageBox::warning(this, "Неверное значение","Неверное значение паспорта! \n",QMessageBox::Ok, QMessageBox::Ok);
            else
                accept();
            break;
        }
        case 2:
        {
            if (ui->idLineEdit->text() == "" || ui->passLineEdit->text() == "" || ui->nameLineEdit->text() == ""
                    || ui->countryLineEdit->text() == "" || ui->typeHousingLineEdit->text() == "" || ui->priceLineEdit->text() == "")
                QMessageBox::warning(this, "Пустые поля","Заполните все поля! \n",QMessageBox::Ok, QMessageBox::Ok);
            else if(ui->passLineEdit->text().length() != 11)
                QMessageBox::warning(this, "Неверное значение","Неверное значение паспорта! \n",QMessageBox::Ok, QMessageBox::Ok);
            else
                accept();
            break;
        }
        case 3:
        {
            if (ui->idLineEdit->text() == "" || ui->passLineEdit->text() == "" || ui->nameLineEdit->text() == "" || ui->tourBox->currentIndex() == 0
                    || ui->countryLineEdit->text() == "" || ui->typeHousingLineEdit->text() == "" || ui->priceLineEdit->text() == "")
                QMessageBox::warning(this, "Пустые поля","Заполните все поля! \n",QMessageBox::Ok, QMessageBox::Ok);
            else if(ui->passLineEdit->text().length() != 11)
                QMessageBox::warning(this, "Неверное значение","Неверное значение паспорта! \n",QMessageBox::Ok, QMessageBox::Ok);
            else
                accept();
            break;
        }
    }
}

void Form::on_buttonBox_rejected()
{
    reject();
}
