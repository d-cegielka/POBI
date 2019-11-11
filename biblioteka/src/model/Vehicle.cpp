//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.11.2019.
//

#include "model/Vehicle.h"


Vehicle::Vehicle(const string &id, const int baseRentPrice) : id(id), baseRentPrice(baseRentPrice) {}

Vehicle::~Vehicle() {}

string Vehicle::vehicleInfo() {
    return "Numer rejestracyjny: " + id +
    "\nCena wypożyczenia: " + to_string(baseRentPrice);
}

const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}
