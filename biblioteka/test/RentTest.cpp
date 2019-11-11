//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 11.11.2019.
//
#include <boost/test/unit_test.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include "model/Rent.h"

using namespace boost::local_time;
using namespace boost::posix_time;

BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE( RentDurationTestBeforeReturn ) {
        Client *client = new Client("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        Vehicle *vehicle= new Vehicle("WW5698",180);
        time_zone_ptr zone(new posix_time_zone("CET"));
        local_date_time *rentalDateTime = new local_date_time(local_sec_clock::local_time(zone)-hours(120));
        Rent *rent = new Rent(rentalDateTime,client,vehicle);
        BOOST_CHECK_EQUAL(rent->rentDuration(), 0.0);
        delete client, vehicle, rentalDateTime, rent;
    }

    BOOST_AUTO_TEST_CASE( ClientRentTestBeforeReturn ) {
        Client *client = new Client("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        Vehicle *vehicle= new Vehicle("WW5698",180);
        time_zone_ptr zone(new posix_time_zone("CET"));
        local_date_time *rentalDateTime = new local_date_time(local_sec_clock::local_time(zone)-hours(120));
        Rent *rent = new Rent(rentalDateTime,client,vehicle);
        BOOST_CHECK_EQUAL(client->addRent(rent), false);
        delete client, vehicle, rentalDateTime, rent;
    }

BOOST_AUTO_TEST_SUITE_END()

