//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_CURRENTRENTSREPOSITORY_H
#define POBIPROJECT_CURRENTRENTSREPOSITORY_H

#include <string>
#include <list>
#include "Rent.h"

class CurrentRentsRepository {
private:
    std::list<Rent *> rentsRepository;

public:
    CurrentRentsRepository();

    virtual ~CurrentRentsRepository();

    bool createRent(Rent * rentToAdd);

    bool removeRent(Rent * rentToRemove);

    std::string getClientForRentedVehicle(Vehicle *vehicle);

    std::string rentReport();


};


#endif //POBIPROJECT_CURRENTRENTSREPOSITORY_H
