//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

//#include <algorithm>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <model/Rent.h>
#include "model/VehicleRepository.h"
#include "model/Vehicle.h"

using namespace std;

bool operator ==(const VehiclePtr & vehicle1, const VehiclePtr & vehicle2) {
    return (vehicle1->getId() == vehicle2->getId());
}

VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {}

VehiclePtr VehicleRepository::getVehicle(int index) const {
   if(index >=0 && index < listOfVehicles.size())
       return *next(listOfVehicles.begin(),index);

   return nullptr;
}

void VehicleRepository::addVehicle(const VehiclePtr &vehicle) {
        listOfVehicles.push_back(vehicle);
}

void VehicleRepository::removeVehicle(const VehiclePtr &vehicle) {
        listOfVehicles.remove(vehicle);
}

const std::string VehicleRepository::vehicleReport() {
    string raport="";
    if (listOfVehicles.size() == 0)
        return "Brak pojazdów!";

    else {
        for(auto vehicle:listOfVehicles)
            raport += vehicle->vehicleInfo() + "\n\n";

        return raport;
    }
}

const bool VehicleRepository::findVehicle(const VehiclePtr &vehicle) const {
    if (find(listOfVehicles.begin(), listOfVehicles.end(), vehicle) != listOfVehicles.end())
        return true;

    return false;

}
