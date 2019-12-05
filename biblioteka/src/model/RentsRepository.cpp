//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/RentsRepository.h"
#include "model/Vehicle.h"
using namespace std;

RentsRepository::RentsRepository() = default;

RentsRepository::~RentsRepository() = default;

void RentsRepository::createRent(const RentPtr &rentToAdd) {
    for(auto rent:rentsRepository)
        if(rent == rentToAdd)
        break;

    rentsRepository.push_back(rentToAdd);
}

void RentsRepository::removeRent(const RentPtr &rentToRemove) {
    for(auto rent:rentsRepository){
        if(rent == rentToRemove){
            rentsRepository.remove(rentToRemove);
            break;
        }
    }
}

const std::string RentsRepository::getClientInfoForRentedVehicle(const VehiclePtr &vehicle) const {
    for(auto rent:rentsRepository){
        if(rent->getVehicle() == vehicle)
            return rent->rentClientInfo();
    }
    return "Pojazd nie jest wypożyczony, brak informacji o kliencie!";
}


ClientPtr RentsRepository::getClientForRentedVehicle(const VehiclePtr &vehicle) const {
    for(auto rent:rentsRepository){
        if(rent->getVehicle() == vehicle)
            return rent->getClient();
    }
    return nullptr;
}

std::string RentsRepository::rentReport() {
    string rentInfo;
    if(rentsRepository.size() != 0){
        for(auto rent:rentsRepository)
            rentInfo.append(rent->rentInfo());

        return rentInfo;
    } else return "Brak wypożyczeń!";
}

const list<RentPtr> RentsRepository::getAllClientRents(const ClientPtr &client) const {
    list<RentPtr> rents;
    for(const auto rent:rentsRepository){
        if(rent->getClient() == client)
            rents.push_back(rent);
    }
    return rents;
}
