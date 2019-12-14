//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#include "model/VehicleRepository.h"

using namespace std;

VehiclePtr VehicleRepository::getVehicle(int index) const {
   if(index >=0 && index < listElements.size())
       return *next(listElements.begin(),index);

   return nullptr;
}

std::string VehicleRepository::vehicleReport() {
    string raport;
    if (listElements.size() == 0)
        return "Brak pojazdów!";

    else {
        for(auto vehicle:listElements)
            raport.append(vehicle->vehicleInfo()).append("\n\n");

        return raport;
    }
}

