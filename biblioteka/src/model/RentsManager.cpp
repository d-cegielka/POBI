//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/RentsManager.h"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;

RentsManager::RentsManager(const CurrentRentsRepositoryPtr &currentRents, const CurrentRentsRepositoryPtr &archiveRents,
                           const VehicleRepositoryPtr &vehicles, const ClientRepositoryPtr &clients) : currentRents(
        currentRents), archiveRents(archiveRents), vehicles(vehicles), clients(clients) {}

RentsManager::~RentsManager() {


}

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
