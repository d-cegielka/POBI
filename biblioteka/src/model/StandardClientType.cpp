//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#include "model/StandardClientType.h"

StandardClientType::StandardClientType() {}

StandardClientType::~StandardClientType() {}

const int StandardClientType::getNumOfRentalVehicles() const {
    return 1;
}

std::string StandardClientType::getClientType() const {
    return ClientType::getClientType() + "Standard";
}

const int StandardClientType::getDiscount(int RentPrice) const {
    return 0;
}


