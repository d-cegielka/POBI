//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_CAR_H
#define POBIPROJECT_CAR_H


#include "MotorVehicle.h"

class Car final : public MotorVehicle {
private:
    char segment;
public:
    Car(const std::string &id, const int baseRentPrice, const int engineDisplacement, char segment);

    virtual ~Car();

    double getSegmentMultiplier() const;

    double actualRentalPrice() const override;

    std::string vehicleInfo() const override;
};


#endif //POBIPROJECT_CAR_H
