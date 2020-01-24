//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "Managers/RentsManager.h"
#include "ClientTypes/PremiumClientType.h"
#include "ClientTypes/VipClientType.h"
#include "Exceptions/RentsManagerException.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "Repositories/RentsRepository.h"
#include "Repositories/ClientRepository.h"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;

RentsManager::RentsManager(const RentsRepositoryPtr &currentRents, const RentsRepositoryPtr &archiveRents,
                           const VehicleRepositoryPtr &vehicles, const ClientRepositoryPtr &clients) : currentRents(
        currentRents), archiveRents(archiveRents), vehicles(vehicles), clients(clients) {}

RentsManager::~RentsManager() = default;

void RentsManager::rentVehicle(const ClientPtr &client, const VehiclePtr &vehicle, const local_date_timePtr &rentDate) {
    if(client == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionClientNullPtr);
    if(vehicle == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionVehicleNullPtr);

    local_date_timePtr correctRentDate;
    time_zone_ptr zone(new posix_time_zone("CET+1"));
    local_date_timePtr actualDate = make_shared<local_date_time>(local_sec_clock::local_time(zone));

    if(rentDate == nullptr)
        correctRentDate = actualDate;
    else if(*rentDate > *actualDate)
        throw RentsManagerException(RentsManagerException::exceptionIncorrectRentalDate);
    else
        correctRentDate = make_shared<local_date_time>(rentDate->utc_time(),zone);

    if(currentRents->getClientForRentedVehicle(vehicle) != nullptr)
        throw RentsManagerException(RentsManagerException::exceptionVehicleNotAvailable);
    if (client->getNumOfClientRents() == client->getMaxNumOfRentalVehicles())
        throw RentsManagerException(RentsManagerException::exceptionClientReachLimitOfRentedVehicles);

    RentPtr rent = make_shared<Rent>(correctRentDate, client, vehicle);
    currentRents->create(rent);
    client->addRent(rent);
}

void RentsManager::returnVehicle(const VehiclePtr &vehicle) {
    if(vehicle == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionVehicleNullPtr);

    ClientPtr client = currentRents->getClientForRentedVehicle(vehicle);
    if(client == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionVehicleAvailable);

    for(auto rent:client->getRentsList()) {
        if(rent->getVehicle() == vehicle) {
            client->removeRent(rent);
            rent->returnVehicle();
            currentRents->remove(rent);
            archiveRents->create(rent);
            changeClientType(client);
            break;
        }
    }
}

void RentsManager::changeClientType(const ClientPtr &client) {
    if(client == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionClientNullPtr);

    if(checkClientRentBallance(client) >= 2500)
        clients->changeClientType(client,make_shared<PremiumClientType>());

    if(checkClientRentBallance(client) >= 6000)
        clients->changeClientType(client,make_shared<VipClientType>());
}

const double RentsManager::checkClientRentBallance(const ClientPtr &client) const{
    if(client == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionClientNullPtr);

    list<RentPtr> rents = getAllClientRents(client);
    double balance = 0.0;
    for(auto rent:rents)
        balance += rent->getRentPrice();

    return balance;
}

const list<RentPtr> RentsManager::getAllClientRents(const ClientPtr &client) const {
    if(client == nullptr)
        throw RentsManagerException(RentsManagerException::exceptionClientNullPtr);

    return archiveRents->getAllClientRents(client);
}

