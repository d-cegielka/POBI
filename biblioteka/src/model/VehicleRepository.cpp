//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

//#include <algorithm>
#include <algorithm>
#include "model/VehicleRepository.h"
#include "model/Vehicle.h"

using namespace std;

VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {

}

Vehicle * VehicleRepository::getVehicle(int index) const {
   if(index >=0 && index < listOfVehicles.size())
       return *next(listOfVehicles.begin(),index);

   return nullptr;
}

bool VehicleRepository::addVehicle(Vehicle *vehicle) {
    if(find(listOfVehicles.begin(),listOfVehicles.end(),vehicle) == listOfVehicles.end())
    {
        listOfVehicles.push_back(vehicle);
        return true;
    }
    else return false;
}

bool VehicleRepository::removeVehicle(Vehicle *vehicle) {
    if(find(listOfVehicles.begin(),listOfVehicles.end(),vehicle) != listOfVehicles.end())
    {
        listOfVehicles.remove(vehicle);
        return true;
    }
    else return false;
}

std::string VehicleRepository::vehicleReport() {
    string raport;
    if (listOfVehicles.size() != 0) {
        for(auto *vehicle:listOfVehicles)
            raport += vehicle->vehicleInfo() + "\n";
    } 
    else return "Brak pojazdów!";
}
