//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#ifndef POBIPROJECT_RENTSMANAGER_H
#define POBIPROJECT_RENTSMANAGER_H

#include "CurrentRentsRepository.h"
#include "VehicleRepository.h"
#include "ClientRepository.h"

typedef std::shared_ptr<CurrentRentsRepository> CurrentRentsRepositoryPtr;
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


};


#endif //POBIPROJECT_RENTSMANAGER_H
