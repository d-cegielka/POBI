//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 11.11.2019.
//
#include <boost/test/unit_test.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/algorithm/string.hpp>
#include <model/Rent.h>
#include <model/Vehicle.h>
#include <model/Client.h>
#include <Repositories/RentsRepository.h>

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::algorithm;
using namespace std;

time_zone_ptr zone(new posix_time_zone("CET"));
shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));

BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentDurationTestBeforeReturn) {
        ClientPtr client = make_shared<Client>("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        VehiclePtr vehicle = make_shared<Vehicle>("WW5698", 180);
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle);
        BOOST_CHECK_EQUAL(rent->rentDuration(), 0.0);
    }

    BOOST_AUTO_TEST_CASE(ClientRentTestBeforeReturn) {
        ClientPtr client = make_shared<Client>("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        VehiclePtr vehicle = make_shared<Vehicle>("WW5698", 180);
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle);
        client->addRent(rent);
        BOOST_CHECK_EQUAL(contains(client->clientRentsInfo(), "92875697851"), true);
    }

    BOOST_AUTO_TEST_CASE( RentDurationTestAfterReturn ) {
        ClientPtr client = make_shared<Client>("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        VehiclePtr vehicle = make_shared<Vehicle>("WW5698", 180);
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle);
        rent->returnVehicle();
        BOOST_CHECK_EQUAL(rent->rentDuration(), 5.0);
    }

    BOOST_AUTO_TEST_CASE( ClientRentTestAfterReturn ) {
        ClientPtr client = make_shared<Client>("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        VehiclePtr vehicle = make_shared<Vehicle>("WW5698", 180);
        RentPtr rent = make_shared<Rent>(rentalDateTime,client,vehicle);
        rent->returnVehicle();
        BOOST_CHECK_EQUAL(contains(client->clientRentsInfo(), "Klient nie ma wypożyczonych pojazdów."), true);
    }

BOOST_AUTO_TEST_SUITE_END()

