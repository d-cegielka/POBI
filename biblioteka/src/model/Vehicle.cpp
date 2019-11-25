//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.11.2019.
//

#include "model/Vehicle.h"

using namespace std;

Vehicle::Vehicle(const string &id, const int baseRentPrice) : id(id), baseRentPrice(baseRentPrice) {}

Vehicle::~Vehicle() {}

std::string Vehicle::vehicleInfo() const {
    return "Numer rejestracyjny: " + id +
    "\nCena wypożyczenia: " + to_string(baseRentPrice);
}

double Vehicle::actualRentalPrice() const {
    return baseRentPrice;
}
