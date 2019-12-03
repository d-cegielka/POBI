//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#include "model/PremiumClientType.h"

PremiumClientType::PremiumClientType() {}

PremiumClientType::~PremiumClientType() {}

const int PremiumClientType::getNumOfRentalVehicles() const {
    return 3;
}

std::string PremiumClientType::getClientType() const {
    return ClientType::getClientType() + "Premium";
}


