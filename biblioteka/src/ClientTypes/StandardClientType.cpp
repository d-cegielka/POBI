//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#include "ClientTypes/StandardClientType.h"

StandardClientType::StandardClientType() = default;

StandardClientType::~StandardClientType() = default;

const int StandardClientType::getNumOfRentalVehicles() const {
    return 1;
}

std::string StandardClientType::getClientType() const {
    return ClientType::getClientType() + "Standard";
}

const double StandardClientType::getDiscount(double RentPrice) const {
    return 0;
}


