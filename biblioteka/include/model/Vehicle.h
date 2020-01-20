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
    Vehicle(const std::string &id, int baseRentPrice);

    virtual ~Vehicle();

    virtual std::string vehicleInfo() const;

    virtual double actualRentalPrice() const;

    virtual const std::string &getId() const;

    bool operator==(const Vehicle &vehicle) const;

    bool operator==(const std::string &vehicleId) const;
};


#endif //POBIPROJECT_VEHICLE_H
