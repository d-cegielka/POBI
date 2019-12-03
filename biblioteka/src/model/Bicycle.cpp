//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/Bicycle.h"

using namespace std;

Bicycle::Bicycle(const string &id, const int baseRentPrice) : Vehicle(id, baseRentPrice) {}

Bicycle::~Bicycle() {}

string Bicycle::vehicleInfo() const {
    string infoVehicle;
    infoVehicle.append("Typ: Rower\n").append(Vehicle::vehicleInfo());
    return infoVehicle;
}
