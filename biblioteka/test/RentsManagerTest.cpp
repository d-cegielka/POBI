//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 07.01.2020.
//

#include <boost/test/unit_test.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/algorithm/string.hpp>
#include <model/RentsManager.h>
#include <model/Bicycle.h>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
typedef shared_ptr<RentsManager> RentsManagerPtr;

BOOST_AUTO_TEST_SUITE(RentsManagerSuiteCorrect)

BOOST_AUTO_TEST_CASE(RentsManagerCreateRentVehicleTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehicleRepositoryPtr vehicleRepo = make_shared<VehicleRepository>();
        ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();
        RentsRepositoryPtr currentRent = make_shared<RentsRepository>();
        RentsRepositoryPtr archiveRents = make_shared<RentsRepository>();

        RentsManagerPtr rentsManager = make_shared<RentsManager>(currentRent, archiveRents, vehicleRepo, clientRepo);
        VehiclePtr vehicle1 = make_shared<Bicycle>("BI 1234",30);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");

        rentsManager->rentVehicle(client1,vehicle1,rentalDateTime);
        BOOST_REQUIRE_EQUAL(client1->getRentsList().size(),1);
        BOOST_REQUIRE_EQUAL(rentsManager->checkClientRentBallance(client1),0);

}

    BOOST_AUTO_TEST_CASE(RentsManagerReturnVehicleTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehicleRepositoryPtr vehicleRepo = make_shared<VehicleRepository>();
        ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();
        RentsRepositoryPtr currentRent = make_shared<RentsRepository>();
        RentsRepositoryPtr archiveRents = make_shared<RentsRepository>();

        RentsManagerPtr rentsManager = make_shared<RentsManager>(currentRent, archiveRents, vehicleRepo, clientRepo);
        VehiclePtr vehicle1 = make_shared<Bicycle>("BI 1234",30);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");

        rentsManager->rentVehicle(client1,vehicle1,rentalDateTime);
        rentsManager->returnVehicle(vehicle1);
        BOOST_REQUIRE_EQUAL(rentsManager->getAllClientRents(client1).size(),1);
        BOOST_REQUIRE_EQUAL(rentsManager->checkClientRentBallance(client1),150);

    }

    BOOST_AUTO_TEST_CASE(RentsManagerChangeClientTypeTestCase) {
        time_zone_ptr zone(new posix_time_zone("CET+1"));
        shared_ptr<local_date_time> rentalDateTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(120));
        VehicleRepositoryPtr vehicleRepo = make_shared<VehicleRepository>();
        ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();
        RentsRepositoryPtr currentRent = make_shared<RentsRepository>();
        RentsRepositoryPtr archiveRents = make_shared<RentsRepository>();

        RentsManagerPtr rentsManager = make_shared<RentsManager>(currentRent, archiveRents, vehicleRepo, clientRepo);
        VehiclePtr vehicle1 = make_shared<Bicycle>("BI 1234",500);
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");

        rentsManager->rentVehicle(client1,vehicle1,rentalDateTime);
        BOOST_REQUIRE_EQUAL(client1->getClientType(),"Typ klienta: Standard");
        BOOST_REQUIRE_EQUAL(rentsManager->checkClientRentBallance(client1) >= 2500,false);
        rentsManager->returnVehicle(vehicle1);
        BOOST_REQUIRE_EQUAL(client1->getClientType(),"Typ klienta: Premium");
        BOOST_REQUIRE_EQUAL(rentsManager->checkClientRentBallance(client1) >= 2500,true);

    }

BOOST_AUTO_TEST_SUITE_END();