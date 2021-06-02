#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include "client.h"
#include "List.h"
#include "aboutprogram.h"
#include "manualbox.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_changeButton_clicked();

    void on_deleteButton_clicked();

    void on_make_triggered();

    void on_open_triggered();

    void on_save_triggered();

    void on_saveAs_triggered();

    void on_exit_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_findLineEdit_returnPressed();

    void on_findButton_clicked();

    void on_findLineEdit_textChanged(const QString &arg1);

    void on_findComboBox_currentIndexChanged(int index);

    void on_aboutProgramm_triggered();

    void on_guide_triggered();

private:
    void drawTable();
    void SetRow(Client* client, int i);
    void writeToFile(QFile &file);
    void showMain();
    bool findRow(QString str, QString strList);

    QTableWidget* table;
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QString filePath;
    List <Client*> list;
    bool isModified;
    bool isShow;
};
#endif // MAINWINDOW_H
