//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#ifndef POBIPROJECT_RENTSMANAGER_H
#define POBIPROJECT_RENTSMANAGER_H

#include "RentsRepository.h"
#include "VehicleRepository.h"
#include "ClientRepository.h"

typedef std::shared_ptr<RentsRepository> CurrentRentsRepositoryPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

class RentsManager {
private:
    CurrentRentsRepositoryPtr currentRents;
    CurrentRentsRepositoryPtr archiveRents;
    VehicleRepositoryPtr vehicles;
    ClientRepositoryPtr clients;
public:
    RentsManager(const CurrentRentsRepositoryPtr &currentRents, const CurrentRentsRepositoryPtr &archiveRents,
                 const VehicleRepositoryPtr &vehicles, const ClientRepositoryPtr &clients);

    virtual ~RentsManager();

    void rentVehicle(const ClientPtr &client, const VehiclePtr &vehicle, const local_date_timePtr &rentDate);

    void returnVehicle(const VehiclePtr &vehicle);

    void changeClientType(const ClientPtr &client);

    const double checkClientRentBallance(const ClientPtr &client) const;

    const std::list<RentPtr> getAllClientRents(const ClientPtr &client) const;

};


#endif //POBIPROJECT_RENTSMANAGER_H
