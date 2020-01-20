//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 10.12.2019.
//

#ifndef POBIPROJECT_VEHICLEMANAGER_H
#define POBIPROJECT_VEHICLEMANAGER_H

#include <memory>

class Vehicle;
class VehicleRepository;

typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;

class VehicleManager {
private:
    VehicleRepositoryPtr  vehicles;
public:
    VehicleManager(const VehicleRepositoryPtr &vehicles);

    virtual ~VehicleManager();

    void addVehicle(const VehiclePtr &vehicle);

    void removeVehicle(const VehiclePtr &vehicle);

    VehiclePtr operator()(const std::string& ID);
};


#endif //POBIPROJECT_VEHICLEMANAGER_H
