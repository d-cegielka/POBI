//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 03.12.2019.
//

#ifndef POBIPROJECT_CLIENTTYPE_H
#define POBIPROJECT_CLIENTTYPE_H

#include <string>

class ClientType {
public:
    ClientType();

    virtual ~ClientType();

    virtual const int getNumOfRentalVehicles() const;

    virtual std::string setConnector(int type) {return 0;};

    virtual std::string getClientType() const;

    virtual const double getDiscount(double RentPrice) const;

};


#endif //POBIPROJECT_CLIENTTYPE_H
