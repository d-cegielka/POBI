//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_BICYCLE_H
#define POBIPROJECT_BICYCLE_H

#include "model/Vehicle.h"

class Bicycle final : public Vehicle {
public:
    Bicycle(const std::string &id, const int baseRentPrice);

    virtual ~Bicycle();

    std::string vehicleInfo() const override;
};


#endif //POBIPROJECT_BICYCLE_H
