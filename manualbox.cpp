#include "manualbox.h"
#include "ui_manualbox.h"

ManualBox::ManualBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualBox)
{
    this->showMaximized();
    ui->setupUi(this);
}

ManualBox::~ManualBox()
{
    delete ui;
}

void ManualBox::on_pushButton_clicked()
{
    accept();
}
