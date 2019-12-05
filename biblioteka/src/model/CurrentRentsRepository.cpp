//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/CurrentRentsRepository.h"
#include "model/Vehicle.h"
using namespace std;

CurrentRentsRepository::CurrentRentsRepository() = default;

CurrentRentsRepository::~CurrentRentsRepository() = default;

const bool CurrentRentsRepository::createRent(const RentPtr &rentToAdd) {
    for(auto rent:rentsRepository)
        if(rent == rentToAdd)
            return false;

    rentsRepository.push_back(rentToAdd);
    return true;
}

const bool CurrentRentsRepository::removeRent(const RentPtr &rentToRemove) {
    for(auto rent:rentsRepository)
    {
        if(rent == rentToRemove)
        {
            rentsRepository.remove(rentToRemove);
            return true;
        }
    }
    return false;
}

const std::string CurrentRentsRepository::getClientInfoForRentedVehicle(const VehiclePtr &vehicle) const {
    if(vehicle->isAvailability()) return "Pojazd nie jest wypożyczony, brak informacji o kliencie!";

    for(auto rent:rentsRepository){
        if(rent->getVehicle() == vehicle)
            return rent->rentClientInfo();
    }
}


ClientPtr CurrentRentsRepository::getClientForRentedVehicle(const VehiclePtr &vehicle) const {
    if(vehicle->isAvailability()) return nullptr;

    for(auto rent:rentsRepository){
        if(rent->getVehicle() == vehicle)
            return rent->getClient();
    }
}

std::string CurrentRentsRepository::rentReport() {
    string rentInfo;
    if(rentsRepository.size() != 0){
        for(auto rent:rentsRepository)
            rentInfo.append(rent->rentInfo());

        return rentInfo;
    } else return "Brak wypożyczeń!";
}


