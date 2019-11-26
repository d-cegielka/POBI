//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_RENTALGENERATOR_H
#define POBIPROJECT_RENTALGENERATOR_H

class VehicleRepository;

class RentalGenerator {
private:
    VehicleRepository* vehicleRepository;

public:
    RentalGenerator(VehicleRepository *vehicleRepository);

    virtual ~RentalGenerator();
};


#endif //POBIPROJECT_RENTALGENERATOR_H
