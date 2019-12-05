//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_RENTALGENERATOR_H
#define POBIPROJECT_RENTALGENERATOR_H

class VehicleRepository;
class ClientRepository;
class RentsRepository;

typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<RentsRepository> CurrentRentsRepositoryPtr;

class RentalGenerator {
private:
    VehicleRepositoryPtr vehicleRepository;
    ClientRepositoryPtr clientRepository;
    CurrentRentsRepositoryPtr currentRents;
    CurrentRentsRepositoryPtr archiveRents;

public:
    RentalGenerator(VehicleRepositoryPtr vehicleRepository, ClientRepositoryPtr clientRepository, CurrentRentsRepositoryPtr currentRents, CurrentRentsRepositoryPtr archiveRents );

    virtual ~RentalGenerator();
};


#endif //POBIPROJECT_RENTALGENERATOR_H
