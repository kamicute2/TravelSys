#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    if(filePath == "")
    {
        isShow = false;
        ui->addButton->hide();
        ui->changeButton->hide();
        ui->deleteButton->hide();
        ui->tableView->hide();
        ui->findLineEdit->hide();
        ui->findComboBox->hide();
        ui->findButton->hide();
        ui->label_3->hide();

    }
    else
    {
        isShow = true;
        showMain();
    }

}


void MainWindow::showMain()
{
    ui->addButton->show();
    ui->changeButton->show();
    ui->deleteButton->show();
    ui->tableView->show();
    ui->findLineEdit->show();
    ui->findComboBox->show();
    ui->findButton->show();
    ui->label_3->show();
    ui->groupBox->hide();
}

//---------------Работа с таблицей---------------------

void MainWindow::drawTable()
{
    if(!ui->tableView->model()){
        model = new QStandardItemModel( 0, 10, this );
        ui->tableView->setModel(model);
        ui->tableView->verticalHeader()->hide();
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model->setHeaderData(0, Qt::Horizontal, "ID");
        ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        model->setHeaderData(1, Qt::Horizontal, "ФИО");
        ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
        model->setHeaderData(2, Qt::Horizontal, "Паспортные данные");
        ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
        model->setHeaderData(3, Qt::Horizontal, "Тип тура");
        ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
        model->setHeaderData(4, Qt::Horizontal, "Туроператор");
        ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
        model->setHeaderData(5, Qt::Horizontal, "Страна");
        ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
        model->setHeaderData(6, Qt::Horizontal, "Тип жилья");
        ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
        model->setHeaderData(7, Qt::Horizontal, "Всё включено");
        ui->tableView->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
        model->setHeaderData(8, Qt::Horizontal, "Цена");
        ui->tableView->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
        model->setHeaderData(9, Qt::Horizontal, "Дополнительно");
        ui->tableView->horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);
        for(int i = 0; i < list.length(); i++){
            SetRow(list[i], i);
        }
    }
    else{
        model->setRowCount(0);
        for(int i = 0; i < list.length(); i++){
            SetRow(list[i], i);
        }
    }

}

void MainWindow::SetRow(Client* client, int i)
{
    model->setRowCount(model->rowCount()+1);
    QModelIndex index = model->index(i,0);
    model->setData(index, client->getId());
    index = model->index(i,1);
    model->setData(index, client->getName());
    index = model->index(i,2);
    model->setData(index, client->getPass());
    index = model->index(i,3);
    if(client->getTypeTour() == 1)
        model->setData(index, "Пакетный");
    else if(client->getTypeTour() == 2)
        model->setData(index, "Заказной");
    else if(client->getTypeTour() == 3)
        model->setData(index, "Компромисс");
    index = model->index(i,4);
    model->setData(index, client->getTour());
    index = model->index(i,5);
    model->setData(index, client->getCountry());
    index = model->index(i,6);
    model->setData(index, client->getTypeHousing());
    index = model->index(i,7);
    if(client->getAllInclusive())
        model->setData(index, "Да");
    else
        model->setData(index, "Нет");
    index = model->index(i,8);
    model->setData(index, client->getPrice());
    index = model->index(i,9);
    model->setData(index, client->getAdditional());
}


MainWindow::~MainWindow()
{
    delete ui;
}

//---------------Основные кнопки---------------------

void MainWindow::on_addButton_clicked()
{
    Form form;
    form.setModal(true);
    if(form.exec())
    {
        int index = form.ReturnValue();
        if (index == 1)
        {
            list.add_back(new StandartClient(form.ReturnId(),
                                             form.ReturnName(),
                                             form.ReturnPass(),
                                             1,
                                             form.ReturnTypeHousing(),
                                             form.ReturnCountry(),
                                             form.ReturnPrice(),
                                             form.ReturnAllInclusive(),
                                             form.ReturnTour()));
            drawTable();
        }
        else if (index == 2)
        {
            list.add_back(new VIPClient(form.ReturnId(),
                                             form.ReturnName(),
                                             form.ReturnPass(),
                                             2,
                                             form.ReturnTypeHousing(),
                                             form.ReturnCountry(),
                                             form.ReturnPrice(),
                                             form.ReturnAllInclusive(),
                                             form.ReturnAdditional()));
            drawTable();
        }
        else if (index == 3)
        {
            list.add_back(new CompromiseClient(form.ReturnId(),
                                             form.ReturnName(),
                                             form.ReturnPass(),
                                             3,
                                             form.ReturnTypeHousing(),
                                             form.ReturnCountry(),
                                             form.ReturnPrice(),
                                             form.ReturnAllInclusive(),
                                             form.ReturnTour(),
                                             form.ReturnAdditional()));
            drawTable();
        }
        isModified = true;
    }
}

void MainWindow::on_changeButton_clicked()
{
    QModelIndexList selectedRowsIndexesList = ui->tableView->selectionModel()->selectedRows();
    if(!selectedRowsIndexesList.isEmpty())
    {
        int i = selectedRowsIndexesList[0].row();
        Form form;
        switch (list[i]->getTypeTour())
        {
            case 1:
            {
                form.SetValue(1);
                form.SetId(list[i]->getId());
                form.SetName(list[i]->getName());
                form.SetPass(list[i]->getPass());
                form.SetTypeHousing(list[i]->getTypeHousing());
                form.SetCountry(list[i]->getCountry());
                form.SetPrice(list[i]->getPrice());
                form.SetAllInclusive(list[i]->getAllInclusive());
                form.SetTour(list[i]->getTour());
                break;
            }
            case 2:
            {
                form.SetValue(2);
                form.SetId(list[i]->getId());
                form.SetName(list[i]->getName());
                form.SetPass(list[i]->getPass());
                form.SetTypeHousing(list[i]->getTypeHousing());
                form.SetCountry(list[i]->getCountry());
                form.SetPrice(list[i]->getPrice());
                form.SetAllInclusive(list[i]->getAllInclusive());
                form.SetAdditional(list[i]->getAdditional());
                break;
            }
            case 3:
            {
                form.SetValue(3);
                form.SetId(list[i]->getId());
                form.SetName(list[i]->getName());
                form.SetPass(list[i]->getPass());
                form.SetTypeHousing(list[i]->getTypeHousing());
                form.SetCountry(list[i]->getCountry());
                form.SetPrice(list[i]->getPrice());
                form.SetAllInclusive(list[i]->getAllInclusive());
                form.SetTour(list[i]->getTour());
                form.SetAdditional(list[i]->getAdditional());
                break;
            }
        }
        form.setModal(true);
        if(form.exec())
        {
            int index = form.ReturnValue();
            if (index == 1)
            {
                list.EDIT(i, new StandartClient(form.ReturnId(),
                                                 form.ReturnName(),
                                                 form.ReturnPass(),
                                                 1,
                                                 form.ReturnTypeHousing(),
                                                 form.ReturnCountry(),
                                                 form.ReturnPrice(),
                                                 form.ReturnAllInclusive(),
                                                 form.ReturnTour()));
                drawTable();
            }
            else if (index == 2)
            {
                list.EDIT(i, new VIPClient(form.ReturnId(),
                                                 form.ReturnName(),
                                                 form.ReturnPass(),
                                                 2,
                                                 form.ReturnTypeHousing(),
                                                 form.ReturnCountry(),
                                                 form.ReturnPrice(),
                                                 form.ReturnAllInclusive(),
                                                 form.ReturnAdditional()));
                drawTable();
            }
            else if (index == 3)
            {
                list.EDIT(i, new CompromiseClient(form.ReturnId(),
                                                 form.ReturnName(),
                                                 form.ReturnPass(),
                                                 3,
                                                 form.ReturnTypeHousing(),
                                                 form.ReturnCountry(),
                                                 form.ReturnPrice(),
                                                 form.ReturnAllInclusive(),
                                                 form.ReturnTour(),
                                                 form.ReturnAdditional()));
                drawTable();
            }

        }
    }
    else
        QMessageBox::warning(this, "Строка не выбрана","Выберете строку! \n",QMessageBox::Ok, QMessageBox::Ok);
}

void MainWindow::on_deleteButton_clicked()
{

    QModelIndexList selectedRowsIndexesList = ui->tableView->selectionModel()->selectedRows();
    if(!selectedRowsIndexesList.isEmpty())
    {
        int i = selectedRowsIndexesList[0].row();
        int ret = QMessageBox::question(this, "Удалить","Удалить элемент\n\nВы действительно хотите удалить элемент?",QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
        switch(ret){
        case QMessageBox::Ok:{
            list.DEL(i);
            drawTable();
            break;
        }
        case QMessageBox::Cancel:
          break;
        }
    }
    else
        QMessageBox::warning(this, "Строка не выбрана","Выберете строку! \n",QMessageBox::Ok, QMessageBox::Ok);
}

//-------------------ПУНКТЫ МЕНЮ--------------------------//

void MainWindow::on_make_triggered()
{
    QFile file;
    QString fileName = QFileDialog::getSaveFileName(this, "Создать файл", QDir::homePath(), "Data files (*.dat)");
    if(fileName.length() == 0){
        return;
    }
    filePath = fileName;
    file.setFileName(fileName);
    file.open(QIODevice::ReadWrite);
    file.close();
    if(list.length() != 0){
        list.delAllList();
    }
    drawTable();
    isModified = false;
    if(!isShow)
        showMain();
}

void MainWindow::on_open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), "Data files (*.dat)");
    if(fileName.length() == 0){
        return;
    }
    if(filePath == fileName){
        return;
    }
    filePath = fileName;
    if(list.length() != 0){
        list.delAllList();
    }

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);

    QDataStream stream(&file);
    int length;
    stream>>length;

    for(int i = 0; i < length; i++){
        int type;
        stream>>type;
        try{
            if(type == 1){
                int id;
                QString name;
                QString pass;
                QString typeHousing;
                QString country;
                QString price;
                bool allInclusive;
                QString tour;
                stream>>id>>name>>pass>>
                        tour>>country>>
                        typeHousing>>allInclusive>>
                        price;

                Client* item = new StandartClient(id, name, pass, type, typeHousing, country, price, allInclusive, tour);
                list.add_back(item);
            }
            else if(type == 2){
                int id;
                QString name;
                QString pass;
                QString typeHousing;
                QString country;
                QString price;
                bool allInclusive;
                QString additional;
                stream>>id>>name>>pass>>
                        country>>
                        typeHousing>>allInclusive>>
                        price>>additional;
                Client* item = new VIPClient(id, name, pass, type, typeHousing, country, price, allInclusive, additional);
                list.add_back(item);
            }
            else if(type == 3){
                int id;
                QString name;
                QString pass;
                QString typeHousing;
                QString country;
                QString price;
                bool allInclusive;
                QString tour;
                QString additional;
                stream>>id>>name>>pass>>
                        tour>>country>>
                        typeHousing>>allInclusive>>
                        price>>additional;
                Client* item = new CompromiseClient(id, name, pass, type, typeHousing, country, price, allInclusive, tour, additional);
                list.add_back(item);
            }
            qDebug()<<"On end: "<<stream.atEnd();
        }
        catch(QString str){
            qDebug()<<str<<" error";
        }

    }
    file.close();
    drawTable();
    isModified = false;
    if(!isShow)
        showMain();
}

void MainWindow::on_save_triggered()
{
    if(filePath == ""){
        on_saveAs_triggered();
        return;
    }

    QFile file(filePath);
    file.open(QIODevice::ReadWrite);
    writeToFile(file);
    file.close();
}

void MainWindow::on_saveAs_triggered()
{
    QFile file;
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить как...", QDir::homePath(), "Data files (*.dat)");
    if(fileName.length() == 0){
        return;
    }
    filePath = fileName;
    file.setFileName(fileName);
    file.open(QIODevice::ReadWrite);
    writeToFile(file);
    file.close();
}

void MainWindow::writeToFile(QFile &file){
    QDataStream stream(&file);
    stream<<list.length();
    if(list.length() == 0){
        return;
    }
    for(int i = 0; i< list.length() ; i++){
        int id = list[i]->getTypeTour();
        if(id == 1){
            stream<<1
            <<list[i]->getId()
            <<list[i]->getName()
            <<list[i]->getPass()
            <<list[i]->getTour()
            <<list[i]->getCountry()
            <<list[i]->getTypeHousing()
            <<list[i]->getAllInclusive()
            <<list[i]->getPrice();

        }
        else if(id == 2){
            stream<<2
            <<list[i]->getId()
            <<list[i]->getName()
            <<list[i]->getPass()
            <<list[i]->getCountry()
            <<list[i]->getTypeHousing()
            <<list[i]->getAllInclusive()
            <<list[i]->getPrice()
            <<list[i]->getAdditional();
        }
        else if(id == 3){
            stream<<3
            <<list[i]->getId()
            <<list[i]->getName()
            <<list[i]->getPass()
            <<list[i]->getTour()
            <<list[i]->getCountry()
            <<list[i]->getTypeHousing()
            <<list[i]->getAllInclusive()
            <<list[i]->getPrice()
            <<list[i]->getAdditional();
        }
    }
    isModified = false;
}

void MainWindow::on_exit_triggered()
{
    if(isModified){
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, "Text editor",
                                   "Сохранить изменения?",
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
        {
            on_save_triggered();
        }
        if (ret == QMessageBox::Cancel)
        {
            return;
        }

    }
    this->close();
}

void MainWindow::on_aboutProgramm_triggered()
{
    AboutProgram* window = new AboutProgram(this);
    window->exec();
}

void MainWindow::on_guide_triggered()
{
    ManualBox* window = new ManualBox(this);
    window->exec();
}

//---------------Тут кнопки главного меню---------------------

void MainWindow::on_pushButton_clicked()
{
    on_make_triggered();
}

void MainWindow::on_pushButton_2_clicked()
{
    on_open_triggered();
}

//---------------Поиск и всё, что с ним связано---------------------


bool MainWindow::findRow(QString str, QString strList)
{
    bool equal = true;
    int i = 0;
    while (equal && i !=str.length() && i!=strList.length())
    {
        if (str[i] != strList[i])
        {
            equal = false;
        }
        i++;
    }
    if (equal)
        return true;
    else
        return false;
}


void MainWindow::on_findLineEdit_returnPressed()
{
    on_findButton_clicked();
}

void MainWindow::on_findButton_clicked()
{
    QString str = ui->findLineEdit->text();
    if (str == "")
        return;
    else
    {
        model->setRowCount(0);
        int index = ui->findComboBox->currentIndex();
        int count = 0;
        switch (index)
        {
            case 0:
            {
                for(int i = 0; i < list.length(); i++)
                    if (findRow(str, QString::number(list[i]->getId())))
                    {
                        SetRow(list[i], count);
                        count++;
                    }

                break;
            }
            case 1:
            {
                for(int i = 0; i < list.length(); i++)
                    if (findRow(str, list[i]->getName()))
                    {

                        SetRow(list[i], count);
                        count++;
                    }
                break;
            }
            case 2:
            {
                for(int i = 0; i < list.length(); i++)
                    if (findRow(str, list[i]->getPass()))
                    {
                        SetRow(list[i], count);
                        count++;
                    }
                break;
            }
        }


    }
}

void MainWindow::on_findLineEdit_textChanged(const QString &arg1)
{
    if (arg1 == "")
        drawTable();
}


void MainWindow::on_findComboBox_currentIndexChanged(int index)
{
    ui->findLineEdit->setText("");
    drawTable();
}
