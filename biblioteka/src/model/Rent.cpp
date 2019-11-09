//
// Created by student on 09.11.2019.
//

#include "model/Rent.h"
#include <boost/uuid/uuid_generators.hpp>

using namespace boost::uuids;
using namespace boost::local_time;
using namespace boost::posix_time;


Rent::Rent(Client *client, Vehicle *vehicle) : client(client), vehicle(vehicle),uuid(random_generator()()) {
    time_zone_ptr zone(new posix_time_zone("CET"));
    rentalDateTime = new local_date_time(local_sec_clock::local_time(zone));
}

Rent::Rent(boost::local_time::local_date_time *rentalDateTime, Client *client, Vehicle *vehicle) : rentalDateTime(
        rentalDateTime), client(client), vehicle(vehicle), uuid(random_generator()()) {}

Rent::~Rent() {
    delete rentalDateTime;
    if(returnDateTime != nullptr)
        delete returnDateTime;
}

