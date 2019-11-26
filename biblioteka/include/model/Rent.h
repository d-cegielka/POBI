//
// Created by student on 09.11.2019.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H

#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <string>

class CurrentRentsRepository;
class Vehicle;
class Client;

class Rent {
private:
    boost::uuids::uuid uuid;
    boost::local_time::local_date_time* rentalDateTime;
    boost::local_time::local_date_time* returnDateTime = nullptr;
    Client* client;
    Vehicle* vehicle;
    CurrentRentsRepository* currentRentsRepository;

public:
    Rent(Client *client, Vehicle *vehicle, CurrentRentsRepository *currentRentsRepository);
    Rent(boost::local_time::local_date_time *rentalDateTime, Client *client, Vehicle *vehicle, CurrentRentsRepository *currentRentsRepository);


    virtual ~Rent();

    int rentDuration();
    double rentPrice();
    std::string rentClientInfo();
    std::string rentVehicleInfo();
    std::string rentInfo();
    void returnVehicle();

    Vehicle *getVehicle() const;
};


#endif //POBIPROJECT_RENT_H
