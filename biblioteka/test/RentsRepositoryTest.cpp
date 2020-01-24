//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 07.01.2020.
//


#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <Repositories/VehicleRepository.h>
#include <Repositories/ClientRepository.h>
#include <Vehicles/Car.h>
#include <Vehicles/Bicycle.h>
#include <Repositories/RentsRepository.h>

using namespace std;
using namespace boost::algorithm;
using namespace boost::local_time;
using namespace boost::posix_time;
typedef std::shared_ptr<RentsRepository> RentsRepositoryPtr;

BOOST_AUTO_TEST_SUITE(RentsRepositorySuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentsRepositoryClientInfoForRentedVehicleTestCase) {
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(nullptr,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);
        string report = currentRentsRepo->getClientInfoForRentedVehicle(car1);

        BOOST_REQUIRE_EQUAL(contains(report, "PESEL: 92875697851"), true);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryClientInfoForRentedVehicleAfterRemoveTestCase) {
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(nullptr,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);
        currentRentsRepo->remove(rent);
        string report = currentRentsRepo->getClientInfoForRentedVehicle(car1);

        BOOST_REQUIRE_EQUAL(contains(report, "Pojazd nie jest wypożyczony, brak informacji o kliencie!"), true);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryGetClientForRentedVehicleTestCase) {
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(nullptr,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);

        BOOST_REQUIRE_EQUAL(currentRentsRepo->getClientForRentedVehicle(car1), client1);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryGetClientForRentedVehicleAfterRemoveTestCase) {
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(nullptr,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);
        currentRentsRepo->remove(rent);

        BOOST_REQUIRE_EQUAL(currentRentsRepo->getClientForRentedVehicle(car1), nullptr);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryRaportTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(rentalDateTime,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);
        string report = currentRentsRepo->rentReport();

        BOOST_REQUIRE_EQUAL(contains(report, "Numer rejestracyjny: CA1111"), true);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryReportAfterRemoveTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(rentalDateTime,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);
        currentRentsRepo->remove(rent);
        string report = currentRentsRepo->rentReport();

        BOOST_REQUIRE_EQUAL(contains(report, "Brak wypożyczeń!"), true);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryAllClientRentsTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(rentalDateTime,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);

        BOOST_REQUIRE_EQUAL(currentRentsRepo->getAllClientRents(client1).size(), 1);

    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryAllClientRentsAfterRemoveTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        RentPtr rent = make_shared<Rent>(rentalDateTime,client1,car1);
        RentsRepositoryPtr currentRentsRepo = make_shared<RentsRepository>();

        currentRentsRepo->create(rent);
        currentRentsRepo->remove(rent);

        BOOST_REQUIRE_EQUAL(currentRentsRepo->getAllClientRents(client1).size(), 0);

    }


BOOST_AUTO_TEST_SUITE_END();