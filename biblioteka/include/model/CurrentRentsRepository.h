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

    bool createRent(RentPtr rentToAdd);

    bool removeRent(RentPtr rentToRemove);

    std::string getClientForRentedVehicle(VehiclePtr vehicle);

    std::string rentReport();


};


#endif //POBIPROJECT_CURRENTRENTSREPOSITORY_H
