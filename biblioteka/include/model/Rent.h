//
// Created by student on 09.11.2019.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H

#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <string>

class CurrentRentsRepository;
class Vehicle;
class Client;

typedef std::shared_ptr <Client> ClientPtr;
typedef std::shared_ptr <Vehicle> VehiclePtr;
typedef std::shared_ptr <boost::local_time::local_date_time> local_date_timePtr;

class Rent {
private:
    boost::uuids::uuid uuid;
    local_date_timePtr rentalDateTime;
    local_date_timePtr returnDateTime;
    ClientPtr client;
    VehiclePtr vehicle;

public:
    Rent(local_date_timePtr rentalDateTime, ClientPtr client, VehiclePtr vehicle);

    virtual ~Rent();

    int rentDuration() const;
    double rentPrice() const;
    std::string rentClientInfo() const;
    std::string rentVehicleInfo() const;
    std::string rentInfo() const;
    void returnVehicle();

    VehiclePtr getVehicle() const;
};


#endif //POBIPROJECT_RENT_H
