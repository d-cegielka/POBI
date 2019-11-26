//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H


#include "Vehicle.h"
#include <list>
#include <string>

class VehicleRepository {
private:
    std::list<Vehicle*> listOfVehicles;

public:
    VehicleRepository();

    virtual ~VehicleRepository();

    bool addVehicle(Vehicle* vehicle);

    bool removeVehicle(Vehicle* vehicle);

    Vehicle* getVehicle(int index) const;

    std::string vehicleReport();

};


#endif //POBIPROJECT_VEHICLEREPOSITORY_H
