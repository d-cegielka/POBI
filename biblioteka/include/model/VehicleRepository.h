//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#ifndef POBIPROJECT_VEHICLEREPOSITORY_H
#define POBIPROJECT_VEHICLEREPOSITORY_H


#include "Vehicle.h"
#include <list>
#include <string>
#include <memory>

typedef std::shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository {
private:
    std::list<VehiclePtr> listOfVehicles;

public:
    VehicleRepository();

    virtual ~VehicleRepository();

    void addVehicle(const VehiclePtr &vehicle);

    void removeVehicle(const VehiclePtr &vehicle);

    VehiclePtr getVehicle(int index) const;

    const std::string &vehicleReport();

};


#endif //POBIPROJECT_VEHICLEREPOSITORY_H
