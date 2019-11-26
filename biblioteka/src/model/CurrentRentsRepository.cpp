//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/CurrentRentsRepository.h"
#include "model/Vehicle.h"
using namespace std;

CurrentRentsRepository::CurrentRentsRepository() {}

CurrentRentsRepository::~CurrentRentsRepository() {}

bool CurrentRentsRepository::createRent(Rent *rentToAdd) {
    for(auto *rent:rentsRepository)
        if(rent == rentToAdd)
            return false;

    rentsRepository.push_back(rentToAdd);
    return true;
}

bool CurrentRentsRepository::removeRent(Rent *rentToRemove) {
    for(auto *rent:rentsRepository)
    {
        if(rent == rentToRemove)
        {
            rentsRepository.remove(rentToRemove);
            return true;
        }
    }
    return false;
}

string CurrentRentsRepository::getClientForRentedVehicle(Vehicle *vehicle) {
    if(vehicle->isAvailability()) return "Pojazd nie jest wypożyczony, brak informacji o kliencie!";

    for(auto *rent:rentsRepository){
        if(rent->getVehicle() == vehicle)
            return rent->rentClientInfo();
    }
}

std::string CurrentRentsRepository::rentReport() {
    string rentInfo;
    if(rentsRepository.size() != 0){
        for(auto rent:rentsRepository)
            return rentInfo += rent->rentInfo();
    }else return "Brak wypożyczeń!";
}
