//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#ifndef POBIPROJECT_PREMIUMCLIENTTYPE_H
#define POBIPROJECT_PREMIUMCLIENTTYPE_H


#include "ClientType.h"

class PremiumClientType final : public ClientType {
public:
    PremiumClientType();

    const int getNumOfRentalVehicles() const override;

    virtual ~PremiumClientType();

    std::string getClientType() const override;

    const int getDiscount(int RentPrice) const override;

};


#endif //POBIPROJECT_PREMIUMCLIENTTYPE_H
