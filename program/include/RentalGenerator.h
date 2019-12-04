//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_RENTALGENERATOR_H
#define POBIPROJECT_RENTALGENERATOR_H

class VehicleRepository;
class ClientRepository;

typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

class RentalGenerator {
private:
    VehicleRepositoryPtr vehicleRepository;
    ClientRepositoryPtr clientRepository;

public:
    RentalGenerator(VehicleRepositoryPtr vehicleRepository, ClientRepositoryPtr clientRepository);

    virtual ~RentalGenerator();
};


#endif //POBIPROJECT_RENTALGENERATOR_H
