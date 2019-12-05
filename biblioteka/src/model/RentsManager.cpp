//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/RentsManager.h"
#include "model/PremiumClientType.h"
#include "model/VipClientType.h"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;

RentsManager::RentsManager(const CurrentRentsRepositoryPtr &currentRents, const CurrentRentsRepositoryPtr &archiveRents,
                           const VehicleRepositoryPtr &vehicles, const ClientRepositoryPtr &clients) : currentRents(
        currentRents), archiveRents(archiveRents), vehicles(vehicles), clients(clients) {}

RentsManager::~RentsManager() {}

void RentsManager::rentVehicle(const ClientPtr &client, const VehiclePtr &vehicle, const local_date_timePtr &rentDate) {
    local_date_timePtr finalRentDate;
    if(rentDate == nullptr)
    {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        finalRentDate = make_shared<local_date_time>(local_sec_clock::local_time(zone));
    } else finalRentDate = rentDate;

    if(client->getNumOfClientRents() < client->getMaxNumOfRentalVehicles() && vehicle->isAvailability())
    {
        RentPtr rent = make_shared<Rent>(finalRentDate, client, vehicle);
        currentRents->createRent(rent);
        client->addRent(rent);
        vehicle->setIsAvailability(false);
    }
}

void RentsManager::returnVehicle(const VehiclePtr &vehicle) {
    ClientPtr client = currentRents->getClientForRentedVehicle(vehicle);
    if(client != nullptr){
        for(auto rent:client->getRentsList()) {
            if(rent->getVehicle() == vehicle) {
                client->removeRent(rent);
                rent->returnVehicle();
                vehicle->setIsAvailability(true);
                currentRents->removeRent(rent);
                archiveRents->createRent(rent);
                changeClientType(client);
                break;
            }
        }
    }
}

void RentsManager::changeClientType(const ClientPtr &client) {
    if(checkClientRentBallance(client) >= 2500) {
        clients->changeClientType(client,make_shared<PremiumClientType>());
    }
    if(checkClientRentBallance(client) >= 6000) {
        clients->changeClientType(client,make_shared<VipClientType>());
    }
}

const double RentsManager::checkClientRentBallance(const ClientPtr &client) const{
    list<RentPtr> rents = getAllClientRents(client);
    double balance = 0.0;
    for(auto rent:rents) {
        balance += rent->getRentPrice();
    }
    return balance;
}

const list<RentPtr> RentsManager::getAllClientRents(const ClientPtr &client) const {
    return archiveRents->getAllClientRents(client);
}

