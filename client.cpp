#include "client.h"

//Client

Client::~Client()
{

}

Client::Client()
{
    id = NULL;
    name = "Иванов Иван Иванович";
    pass = "0000 000000";
    typeTour = -1;
    typeHousing = "None";
    country = "None";
    price = "None";
    allInclusive = "None";
}
Client::Client(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour,
               QString enter_typeHousing, QString enter_country, QString enter_price, bool enter_allInclusive)
{
    id = enter_id;
    name = enter_name;
    pass = enter_pass;
    typeTour = enter_typeTour;
    typeHousing = enter_typeHousing;
    country = enter_country;
    price = enter_price;
    allInclusive = enter_allInclusive;
}

//StandartClient

StandartClient::StandartClient()
{
    id = NULL;
    name = "Иванов Иван Иванович";
    pass = "0000 000000";
    typeHousing = "None";
    typeTour = 0;
    country = "None";
    price = "None";
    allInclusive = "None";
    tour = "None";
}
StandartClient::StandartClient(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour, QString enter_typeHousing,
                               QString enter_country, QString enter_price, bool enter_allInclusive, QString enter_tour):
    Client(enter_id, enter_name, enter_pass, enter_typeTour, enter_typeHousing, enter_country, enter_price, enter_allInclusive),
    tour(enter_tour)
{};

//VIPClient

VIPClient::VIPClient()
{
    id = NULL;
    name = "Иванов Иван Иванович";
    pass = "0000 000000";
    typeHousing = "None";
    typeTour = 1;
    country = "None";
    price = "None";
    allInclusive = "None";
    additional = "None";
}
VIPClient::VIPClient(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour, QString enter_typeHousing,
                     QString enter_country, QString enter_price, bool enter_allInclusive, QString enter_additional):
Client(enter_id, enter_name, enter_pass, enter_typeTour, enter_typeHousing, enter_country, enter_price, enter_allInclusive),
additional(enter_additional)
{}

//CompromiseClient

CompromiseClient::CompromiseClient()
{
    id = NULL;
    name = "Иванов Иван Иванович";
    pass = "0000 000000";
    typeHousing = "None";
    typeTour = 2;
    country = "None";
    price = "None";
    allInclusive = "None";
    tour = "None";
    additional = "None";
}

CompromiseClient::CompromiseClient(int enter_id, QString enter_name, QString enter_pass, int enter_typeTour, QString enter_typeHousing,
                                   QString enter_country, QString enter_price, bool enter_allInclusive, QString enter_tour, QString enter_additional):
Client(enter_id, enter_name, enter_pass, enter_typeTour, enter_typeHousing, enter_country, enter_price, enter_allInclusive),
tour(enter_tour), additional(enter_additional)
{}


