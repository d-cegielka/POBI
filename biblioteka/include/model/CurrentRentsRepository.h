//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_CURRENTRENTSREPOSITORY_H
#define POBIPROJECT_CURRENTRENTSREPOSITORY_H

#include <string>
#include <list>
#include "Rent.h"

typedef std::shared_ptr <Rent> RentPtr;

class CurrentRentsRepository {
private:
    std::list<RentPtr> rentsRepository;

public:
    CurrentRentsRepository();

    virtual ~CurrentRentsRepository();

    const bool createRent(const RentPtr &rentToAdd);

    const bool removeRent(const RentPtr &rentToRemove);

    const std::string getClientInfoForRentedVehicle(const VehiclePtr &vehicle) const;

    ClientPtr getClientForRentedVehicle(const VehiclePtr &vehicle) const;

    std::string rentReport();


};


#endif //POBIPROJECT_CURRENTRENTSREPOSITORY_H
