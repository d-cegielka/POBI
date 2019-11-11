//
// Created by student on 09.11.2019.
//

#include "model/Rent.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace boost::uuids;
using namespace boost::local_time;
using namespace boost::posix_time;


Rent::Rent(Client *client, Vehicle *vehicle) : client(client), vehicle(vehicle),uuid(random_generator()()) {
    time_zone_ptr zone(new posix_time_zone("CET"));
    rentalDateTime = new local_date_time(local_sec_clock::local_time(zone));
    this->client->addRent(this);
}

Rent::Rent(boost::local_time::local_date_time *rentalDateTime, Client *client, Vehicle *vehicle) : rentalDateTime(
        rentalDateTime), client(client), vehicle(vehicle), uuid(random_generator()()) {
    this->client->addRent(this);
}

Rent::~Rent() {
    delete rentalDateTime;
    if(returnDateTime != nullptr)
        delete returnDateTime;
}

int Rent::rentDuration() {
    if(returnDateTime != nullptr) {
        local_time_period duration(*rentalDateTime, *returnDateTime);
        if (duration.length().hours() % 24 == 0) return duration.length().hours() /24;
        else return (duration.length().hours() /24) + 1;
    }
    else return 0;

}

int Rent::rentPrice() {
    return this->vehicle->getBaseRentPrice() * this->rentDuration();
}

string Rent::rentClientInfo() {
    return this->client->clientInfo();
}

string Rent::rentVehicleInfo() {
    return this->vehicle->vehicleInfo();
}

string Rent::rentInfo() {
    string info;
    if(returnDateTime != nullptr){
        info = "\nData zwrotu: " + returnDateTime->to_string() +
                "\nKoszt wypożyczenia" + to_string(rentPrice());
    }
    return "ID wypożyczenia: " + to_string(uuid) +
            "\nData wypożyczenia: " + rentalDateTime->to_string() +
            "\nIlość dni wypożyczenia: " + to_string(rentDuration()) +
            info + "\nWypożyczony pojazd\n" + rentVehicleInfo() +
            "\nOsoba wypożyczająca\n" + rentClientInfo();
}

void Rent::returnVehicle() {
    time_zone_ptr zone(new posix_time_zone("CET"));
    returnDateTime = new local_date_time(local_sec_clock::local_time(zone));
    this->client->removeRent(this);
}

