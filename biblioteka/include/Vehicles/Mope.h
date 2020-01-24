//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_MOPE_H
#define POBIPROJECT_MOPE_H

#include "MotorVehicle.h"

class Mope final : public MotorVehicle{
public:
    Mope(const std::string &id, const int baseRentPrice, const int engineDisplacement);

    virtual ~Mope();

    std::string vehicleInfo() const override;
};


#endif //POBIPROJECT_MOPE_H
