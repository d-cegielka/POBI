//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H

#include "Vehicle.h"
#include "Repository.h"

typedef std::shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository : public Repository<Vehicle> {
public:
    VehiclePtr getVehicle(int index) const;

    const std::string vehicleReport() const;
};


#endif //POBIPROJECT_VEHICLEREPOSITORY_H
