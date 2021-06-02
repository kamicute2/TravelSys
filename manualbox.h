#ifndef MANUALBOX_H
#define MANUALBOX_H

#include <QDialog>

namespace Ui {
class ManualBox;
}

class ManualBox : public QDialog
{
    Q_OBJECT

public:
    explicit ManualBox(QWidget *parent = nullptr);
    ~ManualBox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ManualBox *ui;
};

#endif // MANUALBOX_H
