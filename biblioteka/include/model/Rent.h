//
// Created by student on 09.11.2019.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H

#include "Vehicle.h"
#include "Client.h"
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <string>

class Rent {
private:
    boost::uuids::uuid uuid;
    boost::local_time::local_date_time* rentalDateTime;
    boost::local_time::local_date_time* returnDateTime = nullptr;
    Client* client;
    Vehicle* vehicle;

public:
    Rent(Client *client, Vehicle *vehicle);
    Rent(boost::local_time::local_date_time *rentalDateTime, Client *client, Vehicle *vehicle);

    virtual ~Rent();

    int rentDuration();
    int rentPrice();
    string rentClientInfo();
    string rentVehicleInfo();
    string rentInfo();
};


#endif //POBIPROJECT_RENT_H
