//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#ifndef POBIPROJECT_STANDARDCLIENTTYPE_H
#define POBIPROJECT_STANDARDCLIENTTYPE_H

#include "ClientType.h"

class StandardClientType final : public ClientType {
public:
    StandardClientType();

    virtual ~StandardClientType();

    const int getNumOfRentalVehicles() const override;

    std::string getClientType() const override;
};


#endif //POBIPROJECT_STANDARDCLIENTTYPE_H
