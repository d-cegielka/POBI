//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 10.12.2019.
//

#include "model/VehicleManager.h"

VehicleManager::VehicleManager(const VehicleRepositoryPtr &vehicles) : vehicles(vehicles) {}

VehicleManager::~VehicleManager() {}

void VehicleManager::addVehicle(const VehiclePtr &vehicle) {
    if (!vehicles->findVehicle(vehicle))
        vehicles->addVehicle(vehicle);
}

void VehicleManager::removeVehicle(const VehiclePtr &vehicle) {
    if (vehicles->findVehicle(vehicle))
        vehicles->removeVehicle(vehicle);
}
