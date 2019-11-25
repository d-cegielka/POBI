//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const std::string &id, const int baseRentPrice, const int engineDisplacement)
: Vehicle(id, baseRentPrice), engineDisplacement(engineDisplacement) {}

MotorVehicle::~MotorVehicle() {}

double MotorVehicle::getMultiplier() const {
    if(engineDisplacement < 1000) return 1.0;
    else if( engineDisplacement > 2000) return 1.5;
    double displacement = engineDisplacement;
    return (displacement / 2000) + 0.5;
}

double MotorVehicle::actualRentalPrice() const {
    return Vehicle::actualRentalPrice() * getMultiplier();
}

std::string MotorVehicle::vehicleInfo() const {
    return "Pojemność silnika: "+ std::to_string(engineDisplacement) + "\n" + Vehicle::vehicleInfo();
}

