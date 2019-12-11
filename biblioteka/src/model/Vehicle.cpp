//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.11.2019.
//

#include "model/Vehicle.h"
#include "model/VehicleException.h"

using namespace std;

Vehicle::Vehicle(const string &id, const int baseRentPrice) : id(id), baseRentPrice(baseRentPrice){
    if(baseRentPrice <= 0)
        throw VehicleException("Cena bazowa musi być większa od 0!");
    if(id.size() < 3)
        throw VehicleException("ID pojazdu musi mieć conajmniej 3 znaki!");
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

