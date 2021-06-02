#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QTableWidgetItem>
#include <QStandardItemModel>






class Client
{
public:
    virtual ~Client();
    int id;
    QString name;
    QString pass;
    int typeTour;
    QString typeHousing;
    QString country;
    QString price;
    bool allInclusive;

    int getId(){ return id; }
    QString getName(){ return name; }
    QString getPass(){ return pass; }
    QString getTypeHousing(){ return typeHousing; }
    int getTypeTour(){ return typeTour; }
    QString getCountry(){ return country; }
    QString getPrice(){ return price; }
    bool getAllInclusive(){ return allInclusive; }

    virtual QString getTour() = 0;
    virtual QString getAdditional() = 0;
protected:
    Client();
    Client(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour,
           QString enter_typeHousing, QString enter_country, QString enter_price, bool enter_allInclusive);
};

class StandartClient:virtual public Client
{
public:

    QString tour;

    QString getTour(){ return tour; }
    QString getAdditional(){ return "--------"; }
    StandartClient();
    StandartClient(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour, QString enter_typeHousing,
                    QString enter_country, QString enter_price, bool enter_allInclusive, QString enter_tour);
};

class VIPClient:virtual public Client
{
public:
    QString additional;

    QString getTour(){ return "--------"; }
    QString getAdditional(){ return additional; }
    VIPClient();
    VIPClient(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour, QString enter_typeHousing,
              QString enter_country, QString enter_price, bool allInclusive, QString enter_additional);

};

class CompromiseClient:virtual public Client
{
public:
    QString tour;
    QString additional;

    QString getTour(){ return tour; }
    QString getAdditional(){ return additional; }
    CompromiseClient();
    CompromiseClient(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour, QString enter_typeHousing,
                     QString enter_country, QString enter_price, bool enter_allInclusive, QString enter_tour, QString enter_additional);
};

#endif // CLIENT_H
