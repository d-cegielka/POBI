//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_RENTALGENERATOR_H
#define POBIPROJECT_RENTALGENERATOR_H

class VehicleRepository;

typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;

class RentalGenerator {
private:
    VehicleRepositoryPtr vehicleRepository;

public:
    RentalGenerator(VehicleRepositoryPtr vehicleRepository);

    virtual ~RentalGenerator();
};


#endif //POBIPROJECT_RENTALGENERATOR_H
