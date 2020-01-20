//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#ifndef POBIPROJECT_RENTSMANAGER_H
#define POBIPROJECT_RENTSMANAGER_H

#include <memory>
#include <list>
#include <boost/date_time/local_time/local_time.hpp>

class RentsRepository;
class ClientRepository;
class VehicleRepository;
class Rent;
class Client;
class Vehicle;

typedef std::shared_ptr<RentsRepository> RentsRepositoryPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<boost::local_time::local_date_time> local_date_timePtr;

class RentsManager {
private:
    RentsRepositoryPtr currentRents;
    RentsRepositoryPtr archiveRents;
    VehicleRepositoryPtr vehicles;
    ClientRepositoryPtr clients;
public:
    RentsManager(const RentsRepositoryPtr &currentRents, const RentsRepositoryPtr &archiveRents,
                 const VehicleRepositoryPtr &vehicles, const ClientRepositoryPtr &clients);

    virtual ~RentsManager();

    void rentVehicle(const ClientPtr &client, const VehiclePtr &vehicle, const local_date_timePtr &rentDate);

    void returnVehicle(const VehiclePtr &vehicle);

    void changeClientType(const ClientPtr &client);

    const double checkClientRentBallance(const ClientPtr &client) const;

    const std::list<RentPtr> getAllClientRents(const ClientPtr &client) const;
};


#endif //POBIPROJECT_RENTSMANAGER_H
