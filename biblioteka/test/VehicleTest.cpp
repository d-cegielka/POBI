//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 25.11.2019.
//

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include "model/Car.h"
#include "model/Vehicle.h"
#include "model/Bicycle.h"
#include "model/Mope.h"
#include "model/VehicleException.h"

using namespace boost::algorithm;

BOOST_AUTO_TEST_SUITE(VehicleSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleIdTestCase) {
        Vehicle vehicleTest("WW5698", 180);
        BOOST_REQUIRE_EQUAL(contains(vehicleTest.vehicleInfo(), "WW5698"), true);
    }

    BOOST_AUTO_TEST_CASE(VehicleRentalPriceTestCase) {
        Vehicle vehicleTest("WW5698", 180);
        BOOST_REQUIRE_EQUAL(vehicleTest.actualRentalPrice(), 180);
    }

    BOOST_AUTO_TEST_CASE(BicycleIdTestCase){
        Bicycle bicycleTest("Rowerek",50);
        BOOST_REQUIRE_EQUAL(contains(bicycleTest.vehicleInfo(), "Rowerek"), true);
    }

    BOOST_AUTO_TEST_CASE(BicycleRentalPriceTestCase){
        Bicycle bicycleTest("Rowerek",50);
        BOOST_REQUIRE_EQUAL(bicycleTest.actualRentalPrice(), 50);
    }

    BOOST_AUTO_TEST_CASE(CarIdTestCase){
        Car carTest("WK5981",1000,1000,'B');
        BOOST_REQUIRE_EQUAL(contains(carTest.vehicleInfo(), "WK5981"), true);
    }

    BOOST_AUTO_TEST_CASE(CarRentalPriceTestCase){
        Car carTest("WK5981",1000,1000,'B');
        BOOST_REQUIRE_EQUAL(carTest.actualRentalPrice(), 1100.0);
    }

    BOOST_AUTO_TEST_CASE(CarSegmentMultpilierTestCase){
        Car carTest("WK5981",1000,1000,'B');
        BOOST_REQUIRE_EQUAL(carTest.getSegmentMultiplier(), 1.1);
    }

    BOOST_AUTO_TEST_CASE(CarMultpilierTestCase){
        Car carTest("WK5981",1000,1000,'B');
        BOOST_REQUIRE_EQUAL(carTest.getMultiplier(), 1.0);
    }

    BOOST_AUTO_TEST_CASE(MopeIdTestCase){
        Mope mopeTest("KGHJ",1000,1500);
        BOOST_REQUIRE_EQUAL(contains(mopeTest.vehicleInfo(), "KGHJ"), true);
    }

    BOOST_AUTO_TEST_CASE(MopeRentalPriceTestCase){
        Mope mopeTest("KGHJ",1000,1500);
        BOOST_REQUIRE_EQUAL(mopeTest.actualRentalPrice(), 1250.0);
    }

    BOOST_AUTO_TEST_CASE(MopeMultiplierTestCase){
        Mope mopeTest("KGHJ",1000,1500);
        BOOST_REQUIRE_EQUAL(mopeTest.getMultiplier(), 1.25);
    }

    BOOST_AUTO_TEST_CASE(VehicleExceptionsTestCase){
        BOOST_CHECK_THROW(Vehicle vehicle("D2",50), VehicleException);
        BOOST_CHECK_THROW(Vehicle vehicle("D3342",-50), VehicleException);
        BOOST_CHECK_NO_THROW(Vehicle vehicle("D3342",550));
        BOOST_CHECK_THROW(MotorVehicle motorVehicle("DCXSF56",250,0), VehicleException);
    }

    BOOST_AUTO_TEST_CASE(MotorVehicleExceptionTestCase){
        BOOST_CHECK_THROW(MotorVehicle motorVehicle("DCXSF56",250,0), VehicleException);
        BOOST_CHECK_THROW(MotorVehicle motorVehicle("DCXSF56",250,-250), VehicleException);
        BOOST_CHECK_NO_THROW(MotorVehicle motorVehicle("DCXSF56",250,1500));
    }

    BOOST_AUTO_TEST_CASE(CarExceptionTestCase){
        BOOST_CHECK_THROW(Car car("XSDSFG",450,1799,'G'), VehicleException);
        BOOST_CHECK_NO_THROW(Car car("XSDSFG",450,1799,'A'));
    }

BOOST_AUTO_TEST_SUITE_END();
