//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include "model/Client.h"
#include "model/VipClientType.h"
#include <memory>

using namespace std;
using namespace boost::algorithm;

shared_ptr<Client> client = make_shared<Client>("Waldemar", "Nowak", "92875697851", "Warszawska", "22", "Batorego","55G");

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientTestData) {
        BOOST_REQUIRE_EQUAL(client->getMaxNumOfRentalVehicles(),1);
        BOOST_REQUIRE_EQUAL(client->getClientType(),"Typ klienta: Standard");
        client->setClientType (make_shared <VipClientType>());
        BOOST_REQUIRE_EQUAL(client->getClientType(),"Typ klienta: VIP");
    }

BOOST_AUTO_TEST_SUITE_END();
