//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#include "ClientTypes/PremiumClientType.h"

PremiumClientType::PremiumClientType() = default;

PremiumClientType::~PremiumClientType() = default;

const int PremiumClientType::getNumOfRentalVehicles() const {
    return 3;
}

std::string PremiumClientType::getClientType() const {
    return ClientType::getClientType() + "Premium";
}

const double PremiumClientType::getDiscount(double RentPrice) const {
    if(RentPrice > 1000) return 125;
    if(RentPrice > 500) return 50;
    if(RentPrice > 250) return 20;
    if(RentPrice <= 10 ) return 0;
    return 10;
}


