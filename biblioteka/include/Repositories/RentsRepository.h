//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 25.11.2019.
//

#ifndef POBIPROJECT_RENTSREPOSITORY_H
#define POBIPROJECT_RENTSREPOSITORY_H

#include "model/Rent.h"
#include "Repository.h"

typedef std::shared_ptr<Rent> RentPtr;

class RentsRepository : public Repository<Rent> {
public:
    const std::string getClientInfoForRentedVehicle(const VehiclePtr &vehicle) const;

    ClientPtr getClientForRentedVehicle(const VehiclePtr &vehicle) const;

    const std::list<RentPtr> getAllClientRents(const ClientPtr &client) const;

    std::string rentReport();
};


#endif //POBIPROJECT_RENTSREPOSITORY_H
