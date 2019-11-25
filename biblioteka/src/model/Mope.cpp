//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/Mope.h"

Mope::Mope(const std::string &id, const int baseRentPrice, const int engineDisplacement)
            : MotorVehicle(id, baseRentPrice, engineDisplacement) {}

Mope::~Mope() {}

std::string Mope::vehicleInfo() const {
    return "Typ: Motorower\n" + MotorVehicle::vehicleInfo();
}
