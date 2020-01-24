//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#ifndef POBIPROJECT_PREMIUMCLIENTTYPE_H
#define POBIPROJECT_PREMIUMCLIENTTYPE_H

#include "model/ClientType.h"

class PremiumClientType final : public ClientType {
public:
    PremiumClientType();

    virtual ~PremiumClientType();

    const int getNumOfRentalVehicles() const override;

    std::string getClientType() const override;

    const double getDiscount(double RentPrice) const override;
};


#endif //POBIPROJECT_PREMIUMCLIENTTYPE_H
