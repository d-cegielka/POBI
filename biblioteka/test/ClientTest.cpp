//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include <memory>
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include "model/Client.h"
#include "model/VipClientType.h"
#include "model/PremiumClientType.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "model/ClientException.h"

using namespace std;
using namespace boost::algorithm;

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientFirstNameCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getFirstName(), "Waldemar");
    }

    BOOST_AUTO_TEST_CASE(ClientLastNameCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getLastName(), "Nowak");
    }

    BOOST_AUTO_TEST_CASE(ClientPersonalIDCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getId(), "92875697851");
    }

    BOOST_AUTO_TEST_CASE(ClientAddressesCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(contains(client.clientInfo(),"Warszawska 22"), true);
        BOOST_REQUIRE_EQUAL(contains(client.clientInfo(),"Batorego 55G"), true);
    }

    BOOST_AUTO_TEST_CASE(ClientSetAddressesCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        client.setAddress("Czarna","23A");
        client.setRegistredAddress("Błękitna","50");
        BOOST_REQUIRE_EQUAL(contains(client.clientInfo(),"Czarna 23A"), true);
        BOOST_REQUIRE_EQUAL(contains(client.clientInfo(),"Błękitna 50"), true);
    }

    BOOST_AUTO_TEST_CASE(ClientCheckDefaultDiscountCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(0), 0);
    }

    BOOST_AUTO_TEST_CASE(ClientCheckDefaultVehicleLimitCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getMaxNumOfRentalVehicles(), 1);
    }

    BOOST_AUTO_TEST_CASE(ClientCheckDefaultTypeCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getClientType(),"Typ klienta: Standard");
    }

    BOOST_AUTO_TEST_CASE(ClientPremiumCheckTypeChangeCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        ClientTypePtr type(make_shared<PremiumClientType>());
        client.setClientType(type);
        BOOST_REQUIRE_EQUAL(client.getClientType(),"Typ klienta: Premium");
    }

    BOOST_AUTO_TEST_CASE(ClientPremiumCheckDiscountCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        ClientTypePtr type(make_shared<PremiumClientType>());
        client.setClientType(type);
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(5), 0);
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(100), 10);
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(300), 20);
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(740), 50);
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(1500), 125);
    }

    BOOST_AUTO_TEST_CASE(ClientPremiumCheckDefaultVehicleLimitCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        ClientTypePtr type(make_shared<PremiumClientType>());
        client.setClientType(type);
        BOOST_REQUIRE_EQUAL(client.getMaxNumOfRentalVehicles(), 3);
    }

    BOOST_AUTO_TEST_CASE(ClientVipTypeChangeCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        BOOST_REQUIRE_EQUAL(client.getClientType(),"Typ klienta: Standard");
        ClientTypePtr type(make_shared<VipClientType>());
        client.setClientType(type);
        BOOST_REQUIRE_EQUAL(client.getClientType(),"Typ klienta: VIP");
    }

    BOOST_AUTO_TEST_CASE(ClientVipCheckDiscountCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        ClientTypePtr type(make_shared<VipClientType>());
        client.setClientType(type);
        BOOST_REQUIRE_EQUAL(client.getClientDiscount(100), 19);
    }

    BOOST_AUTO_TEST_CASE(ClientVipCheckDefaultVehicleLimitCase) {
        Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");
        ClientTypePtr type(make_shared<VipClientType>());
        client.setClientType(type);
        BOOST_REQUIRE_EQUAL(client.getMaxNumOfRentalVehicles(), -1);
    }

    BOOST_AUTO_TEST_CASE(ClientNumOfRentsCase) {
        ClientPtr client = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        VehiclePtr vehicle1 = make_shared<Vehicle>("EW 1111", 50);
        VehiclePtr vehicle2 = make_shared<Vehicle>("EW 2222", 70);
        RentPtr rent1 = make_shared<Rent>(nullptr,client,vehicle1);
        RentPtr rent2 = make_shared<Rent>(nullptr,client,vehicle2);
        client->addRent(rent1);
        BOOST_REQUIRE_EQUAL(client->getNumOfClientRents(), 1);
        client->addRent(rent2);
        BOOST_REQUIRE_EQUAL(client->getNumOfClientRents(), 2);
    }

    BOOST_AUTO_TEST_CASE(ClientExceptionCase)
    {
        BOOST_CHECK_NO_THROW(Client client("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G"));
        BOOST_CHECK_THROW(Client client("", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G"), ClientException);
        BOOST_CHECK_THROW(Client client("Waldemar", "", "92875697851", "Warszawska", "22", "Batorego","55G"), ClientException);
        BOOST_CHECK_THROW(Client client("Waldemar", "Nowak", "", "Warszawska", "22", "Batorego","55G"), ClientException);
        BOOST_CHECK_THROW(Client client("Waldemar", "Nowak", "", "Warszawska", "", "Batorego","55G"), ClientException);
        BOOST_CHECK_THROW(Client client("Waldemar", "Nowak", "", "Warszawska", "22", "","55G"), ClientException);
    }

BOOST_AUTO_TEST_SUITE_END();
