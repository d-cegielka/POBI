//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.11.2019.
//

#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H

#include <string>

class Vehicle {
private:
    const std::string id;
    const int baseRentPrice;
public:
    Vehicle(const std::string &id, const int baseRentPrice);
    virtual ~Vehicle();
    std::string vehicleInfo();

    const int getBaseRentPrice() const;

};


#endif //POBIPROJECT_VEHICLE_H
