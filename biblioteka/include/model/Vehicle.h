//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.11.2019.
//

#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
private:
    const string id;
    const int baseRentPrice;
public:
    Vehicle(const string &id, const int baseRentPrice);
    virtual ~Vehicle();
    string vehicleInfo();

};


#endif //POBIPROJECT_VEHICLE_H
