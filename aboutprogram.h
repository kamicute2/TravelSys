#ifndef ABOUTPROGRAM_H
#define ABOUTPROGRAM_H

#include <QLabel>
#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>

class AboutProgram: public QDialog
{
    Q_OBJECT
private:
    QLabel* programDescripton;

    QLabel* githubLink;

    QLabel* licenceLabel;

    QBoxLayout* boxLayout;

    QPushButton* closeButton;

public:
    AboutProgram(QWidget *parent = nullptr);
};

#endif // ABOUTPROGRAM_H
