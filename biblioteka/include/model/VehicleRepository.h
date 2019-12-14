//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H


#include "Vehicle.h"
#include "Repository.h"
#include <string>

typedef std::shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository : public Repository<VehiclePtr> {
public:
    VehiclePtr getVehicle(int index) const;

    std::string vehicleReport();
};


#endif //POBIPROJECT_VEHICLEREPOSITORY_H
