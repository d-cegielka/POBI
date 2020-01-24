//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include "Vehicles/Car.h"
#include "Exceptions/VehicleException.h"

using namespace std;

Car::Car(const string &id, const int baseRentPrice, const int engineDisplacement, char segment)
        : MotorVehicle(id, baseRentPrice, engineDisplacement), segment(segment) {
    if(segment != 'A' && segment != 'B' && segment != 'C' && segment != 'D' && segment != 'E')
        throw VehicleException(VehicleException::exceptionCarSegment);
}

Car::~Car() = default;

double Car::actualRentalPrice() const {
    return MotorVehicle::actualRentalPrice() * getSegmentMultiplier();
}

string Car::vehicleInfo() const{
    string infoVehicle;
    infoVehicle.append("Typ: Samochód\nSegment: ").append(string(1, segment))
            .append("\n").append(MotorVehicle::vehicleInfo());
    return infoVehicle;
}

double Car::getSegmentMultiplier() const {
    switch (segment) {
        case 'A':
            return 1.0;
        case 'B':
            return 1.1;
        case 'C':
            return 1.2;
        case 'D':
            return 1.3;
        case 'E':
            return 1.5;
        default:
            break;
    }
}

