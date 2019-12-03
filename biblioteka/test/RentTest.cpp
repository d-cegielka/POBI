//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 11.11.2019.
//
#include <boost/test/unit_test.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/algorithm/string.hpp>
#include "model/Rent.h"
#include "model/Vehicle.h"
#include "model/Client.h"
#include "model/CurrentRentsRepository.h"

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::algorithm;
using namespace std;

//typedef shared_ptr<local_date_time> local_date_timePtr;

shared_ptr<Client> client = make_shared<Client>("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
shared_ptr<Vehicle> vehicle = make_shared<Vehicle>("WW5698", 180);
time_zone_ptr zone(new posix_time_zone("CET"));
shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));

BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE( RentDurationTestBeforeReturn ) {
        CurrentRentsRepositoryPtr currentRentsRepository = make_shared<CurrentRentsRepository>();
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle,currentRentsRepository);
        BOOST_CHECK_EQUAL(rent->rentDuration(), 0.0);
    }

    BOOST_AUTO_TEST_CASE( ClientRentTestBeforeReturn ) {
        CurrentRentsRepositoryPtr currentRentsRepository = make_shared<CurrentRentsRepository>();
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle,currentRentsRepository);
        BOOST_CHECK_EQUAL(client->addRent(rent), false);
    }

    BOOST_AUTO_TEST_CASE( RentDurationTestAfterReturn ) {
        CurrentRentsRepositoryPtr currentRentsRepository = make_shared<CurrentRentsRepository>();
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle,currentRentsRepository);
        rent->returnVehicle();
        BOOST_CHECK_EQUAL(rent->rentDuration(), 5.0);
    }

    BOOST_AUTO_TEST_CASE( ClientRentTestAfterReturn ) {
        CurrentRentsRepositoryPtr currentRentsRepository = make_shared<CurrentRentsRepository>();
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle,currentRentsRepository);
        rent->returnVehicle();
        BOOST_CHECK_EQUAL(client->addRent(rent), true);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryTest){
        CurrentRentsRepositoryPtr currentRentsRepository = make_shared<CurrentRentsRepository>();
        ClientPtr client2 = make_shared<Client>("Hubert","Lis","92112563112", "Warszawska", "20","Batorego","44");
        VehiclePtr vehicle2 = make_shared<Vehicle>("WD5463",200);
        RentPtr rent = make_shared<Rent>(client,vehicle,currentRentsRepository);
        BOOST_CHECK_EQUAL(vehicle->isAvailability(),false);
        BOOST_CHECK_EQUAL(contains(currentRentsRepository->getClientForRentedVehicle(vehicle),"92112563112"), true);
        BOOST_CHECK_EQUAL(contains(currentRentsRepository->rentReport(),"WD5463"), true);
        rent->returnVehicle();
        BOOST_CHECK_EQUAL(vehicle->isAvailability(), true);
        BOOST_CHECK_EQUAL(contains(currentRentsRepository->getClientForRentedVehicle(vehicle),"92112563112"), false);
        BOOST_CHECK_EQUAL(contains(currentRentsRepository->rentReport(),"WD5463"), false);
    }
BOOST_AUTO_TEST_SUITE_END()

