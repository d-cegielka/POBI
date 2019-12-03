//
// Created by student on 09.11.2019.
//

#include "model/Rent.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "model/Vehicle.h"
#include "model/Client.h"
#include "model/CurrentRentsRepository.h"

using namespace std;
using namespace boost::uuids;
using namespace boost::local_time;
using namespace boost::posix_time;


Rent::Rent(ClientPtr client, VehiclePtr vehicle, CurrentRentsRepositoryPtr currentRentsRepository) : client(client), vehicle(vehicle), uuid(random_generator()()), currentRentsRepository(currentRentsRepository) {
    time_zone_ptr zone(new posix_time_zone("CET+1"));
    rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone));
    if(vehicle->isAvailability()) {
        currentRentsRepository->createRent(static_cast<RentPtr>(this));
        vehicle->setIsAvailability(false);
        this->client->addRent(static_cast<RentPtr>(this));
    }
}

Rent::Rent(local_date_timePtr rentalDateTime, ClientPtr client, VehiclePtr vehicle, CurrentRentsRepositoryPtr currentRentsRepository) : rentalDateTime(
        rentalDateTime), client(client), vehicle(vehicle), uuid(random_generator()()), currentRentsRepository(currentRentsRepository) {
    if(vehicle->isAvailability()) {
        currentRentsRepository->createRent(static_cast<RentPtr>(this));
        vehicle->setIsAvailability(false);
        this->client->addRent(static_cast<RentPtr>(this));
    }
}

Rent::~Rent() = default;
    /*delete rentalDateTime;
    if(returnDateTime != nullptr)
        delete returnDateTime;*/


int Rent::rentDuration() const {
    if(returnDateTime) {
        local_time_period duration(*rentalDateTime, *returnDateTime);
        if (duration.length().hours() % 24 == 0) return duration.length().hours() /24;
        else return (duration.length().hours() /24) + 1;
    }
    else return 0;

}

double Rent::rentPrice() const{
    return this->vehicle->actualRentalPrice() * this->rentDuration();
}

string Rent::rentClientInfo() const{
    return this->client->clientInfo();
}

string Rent::rentVehicleInfo() const{
    return this->vehicle->vehicleInfo();
}

string Rent::rentInfo() const{
    string info;
    if(returnDateTime != nullptr){
        info = "\nData zwrotu: " + returnDateTime->to_string() +
                "\nKoszt wypożyczenia: " + to_string(rentPrice());
    }
    return "ID wypożyczenia: " + to_string(uuid) +
            "\nData wypożyczenia: " + rentalDateTime->to_string() +
            "\nIlość dni wypożyczenia: " + to_string(rentDuration()) +
            info + "\nWypożyczony pojazd\n" + rentVehicleInfo() +
            "\nOsoba wypożyczająca\n" + rentClientInfo();
}

void Rent::returnVehicle() {
    time_zone_ptr zone(new posix_time_zone("CET"));
    returnDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone));
    this->client->removeRent(static_cast<RentPtr>(this));
    this->vehicle->setIsAvailability(true);
    this->currentRentsRepository->removeRent(static_cast<RentPtr>(this));
}

VehiclePtr Rent::getVehicle() const {
    return vehicle;
}

