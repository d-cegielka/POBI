//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.11.2019.
//

#include "model/Vehicle.h"
#include "model/VehicleException.h"

using namespace std;

Vehicle::Vehicle(const string &id, const int baseRentPrice) : id(id), baseRentPrice(baseRentPrice){
    if(id.size() < 3)
        throw VehicleException(VehicleException::exceptionVehicleId);

    if(baseRentPrice <= 0)
        throw VehicleException(VehicleException::exceptionVehicleBaseRentPrice);
}

Vehicle::~Vehicle() {}

std::string Vehicle::vehicleInfo() const {
    string infoVehicle;
    infoVehicle.append("Numer rejestracyjny: ").append(id)
    .append("\nCena wypożyczenia: ").append(to_string(baseRentPrice));
    return infoVehicle;
}

double Vehicle::actualRentalPrice() const {
    return baseRentPrice;
}

const string &Vehicle::getId() const {
    return id;
}

bool Vehicle::operator==(const Vehicle &vehicle) const {
    return id == vehicle.id;
}

bool Vehicle::operator==(const std::string &vehicleId) const {
    return id == vehicleId;
}

