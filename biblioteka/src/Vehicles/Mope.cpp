//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include "Vehicles/Mope.h"

using namespace std;

Mope::Mope(const string &id, const int baseRentPrice, const int engineDisplacement)
            : MotorVehicle(id, baseRentPrice, engineDisplacement) {}

Mope::~Mope() = default;

string Mope::vehicleInfo() const {
    string infoVehicle;
    infoVehicle.append("Typ: Motorower\n").append(MotorVehicle::vehicleInfo());
    return infoVehicle;
}
