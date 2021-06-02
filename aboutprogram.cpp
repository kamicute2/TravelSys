#include "aboutprogram.h"

AboutProgram::AboutProgram(QWidget *parent) : QDialog(parent, Qt::WindowTitleHint)
{
    programDescripton = new QLabel("Информационно-поисковая система \"Туристическое агентство\"\n"
                                   "Программа предназначена для сохранения и управления данными о клиентах туристического агентства");

    githubLink = new QLabel("<a href='https://github.com/kamicute2/TravelSys'>GitHub link</a>");
    githubLink->setOpenExternalLinks(true);
    licenceLabel = new QLabel("Электронная почта: <a href=\"belcev.76@mail.ru\">belcev.76@mail.ru</a><br>"
                              "Разработчик: Бельцев Ярослав Владимирович<br>"
                              "Приложение свободно для копирования и использования");

    licenceLabel->setOpenExternalLinks(true);

    boxLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    closeButton = new QPushButton("Закрыть");
    connect(closeButton, SIGNAL(clicked()), SLOT(accept()));

    boxLayout->insertWidget(0, programDescripton);
    boxLayout->insertWidget(1, githubLink);
    boxLayout->insertWidget(2, licenceLabel);
    boxLayout->insertWidget(3, closeButton);
    setLayout(boxLayout);
}
