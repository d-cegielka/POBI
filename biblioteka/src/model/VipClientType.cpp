//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#include "model/VipClientType.h"

VipClientType::VipClientType() {}

VipClientType::~VipClientType() {}

const int VipClientType::getNumOfRentalVehicles() const {
    return -1;
}

std::string VipClientType::getClientType() const {
    return ClientType::getClientType() + "VIP";
}

const int VipClientType::getDiscount(int RentPrice) const {
    return 0.19 * RentPrice;
}


