//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_MOTORVEHICLE_H
#define POBIPROJECT_MOTORVEHICLE_H

#include "model/Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    const int engineDisplacement;
public:
    MotorVehicle(const std::string &id, const int baseRentPrice, const int engineDisplacement);

    virtual ~MotorVehicle();

    double getMultiplier() const;

    virtual double actualRentalPrice() const override;

    virtual std::string vehicleInfo() const override;
};


#endif //POBIPROJECT_MOTORVEHICLE_H
