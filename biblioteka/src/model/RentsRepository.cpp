//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/RentsRepository.h"
#include "model/Vehicle.h"

using namespace std;

const std::string RentsRepository::getClientInfoForRentedVehicle(const VehiclePtr &vehicle) const {
    for(auto rent:listElements){
        if(rent->getVehicle() == vehicle)
            return rent->rentClientInfo();
    }
    return "Pojazd nie jest wypożyczony, brak informacji o kliencie!";
}


ClientPtr RentsRepository::getClientForRentedVehicle(const VehiclePtr &vehicle) const {
    for(auto rent:listElements){
        if(rent->getVehicle() == vehicle)
            return rent->getClient();
    }
    return nullptr;
}

std::string RentsRepository::rentReport() {
    string rentInfo;
    if(listElements.size() != 0){
        for(auto rent:listElements)
            rentInfo.append(rent->rentInfo());

        return rentInfo;
    } else return "Brak wypożyczeń!";
}

const list<RentPtr> RentsRepository::getAllClientRents(const ClientPtr &client) const {
    list<RentPtr> rents;
    for(auto rent:listElements){
        if(rent->getClient() == client)
            rents.push_back(rent);
    }
    return rents;
}
