//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include "model/Vehicle.h"
#include "model/Bicycle.h"

using namespace boost::algorithm;

BOOST_AUTO_TEST_SUITE(VehicleSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleTests) {
        Vehicle vehicleTest("WW5698", 180);
        BOOST_REQUIRE_EQUAL(vehicleTest.actualRentalPrice(), 180);
        BOOST_REQUIRE_EQUAL(contains(vehicleTest.vehicleInfo(), "WW5698"), true);
    }

    BOOST_AUTO_TEST_CASE(BicycleTests){
        Bicycle bicycleTest("Rowerek",50);
        BOOST_REQUIRE_EQUAL(bicycleTest.actualRentalPrice(), 180);
    }

BOOST_AUTO_TEST_SUITE_END();
