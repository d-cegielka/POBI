//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/Bicycle.h"

Bicycle::Bicycle(const std::string &id, const int baseRentPrice) : Vehicle(id, baseRentPrice) {}

Bicycle::~Bicycle() {}

std::string Bicycle::vehicleInfo() const {
    return "Typ: Rower\n" + Vehicle::vehicleInfo();
}
