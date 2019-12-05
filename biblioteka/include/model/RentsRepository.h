//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_RENTSREPOSITORY_H
#define POBIPROJECT_RENTSREPOSITORY_H

#include <string>
#include <list>
#include "Rent.h"

typedef std::shared_ptr <Rent> RentPtr;

class RentsRepository {
private:
    std::list<RentPtr> rentsRepository;

public:
    RentsRepository();

    virtual ~RentsRepository();

    void createRent(const RentPtr &rentToAdd);

    void removeRent(const RentPtr &rentToRemove);

    const std::string getClientInfoForRentedVehicle(const VehiclePtr &vehicle) const;

    ClientPtr getClientForRentedVehicle(const VehiclePtr &vehicle) const;

    const std::list<RentPtr> getAllClientRents(const ClientPtr &client) const;

    std::string rentReport();


};


#endif //POBIPROJECT_RENTSREPOSITORY_H
