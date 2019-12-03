//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#ifndef POBIPROJECT_CLIENTTYPE_H
#define POBIPROJECT_CLIENTTYPE_H

#include <string>

class ClientType {
public:
    ClientType();

    virtual const int getNumOfRentalVehicles() const;

    virtual ~ClientType();

    virtual std::string getClientType() const;

};


#endif //POBIPROJECT_CLIENTTYPE_H
