//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 10.12.2019.
//

#include "model/VehicleManager.h"
#include "model/VehicleManagerException.h"
#include "model/VehicleRepository.h"

VehicleManager::VehicleManager(const VehicleRepositoryPtr &vehicles) : vehicles(vehicles) {}

VehicleManager::~VehicleManager() = default;

void VehicleManager::addVehicle(const VehiclePtr &vehicle) {
    if (vehicles->find(vehicle) != nullptr)
        throw VehicleManagerException(VehicleManagerException::exceptionVehicleExist);
    vehicles->create(vehicle);
}

void VehicleManager::removeVehicle(const VehiclePtr &vehicle) {
    if (vehicles->find(vehicle) == nullptr)
        throw VehicleManagerException(VehicleManagerException::exceptionVehicleNotExist);
    vehicles->remove(vehicle);
}

VehiclePtr VehicleManager::operator()(const std::string& ID) {
    return VehiclePtr(vehicles->find(ID));
}