//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.01.2020.
//

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include <Vehicles/Bicycle.h>
#include <Managers/VehicleManager.h>
#include <Repositories/VehicleRepository.h>
#include <Exceptions/VehicleManagerException.h>

using namespace std;
typedef shared_ptr<VehicleManager> VehicleManagerPtr;

BOOST_AUTO_TEST_SUITE(VehicleManagerSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleManagerAddVehicleTestCase) {
        VehicleRepositoryPtr vehicleRepo = make_shared<VehicleRepository>();
        VehicleManagerPtr vehicleManager = make_shared<VehicleManager>(vehicleRepo);

        VehiclePtr vehicle1 = make_shared<Bicycle>("BI 1234",30);
        vehicleManager->addVehicle(vehicle1);
        BOOST_REQUIRE_EQUAL(vehicleManager->operator()(vehicle1->getId()), vehicle1);

    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRemoveVehicleTestCase) {
        VehicleRepositoryPtr vehicleRepo = make_shared<VehicleRepository>();
        VehicleManagerPtr vehicleManager = make_shared<VehicleManager>(vehicleRepo);

        VehiclePtr vehicle1 = make_shared<Bicycle>("BI 1234",30);
        vehicleManager->addVehicle(vehicle1);
        BOOST_REQUIRE_EQUAL(vehicleManager->operator()(vehicle1->getId()), vehicle1);
        vehicleManager->removeVehicle(vehicle1);
        BOOST_REQUIRE_EQUAL(vehicleManager->operator()(vehicle1->getId()), nullptr);

    }

    BOOST_AUTO_TEST_CASE(VehicleManagerExceptionTestCase) {
        VehicleRepositoryPtr vehicleRepo = make_shared<VehicleRepository>();
        VehicleManagerPtr vehicleManager = make_shared<VehicleManager>(vehicleRepo);

        VehiclePtr vehicle1 = make_shared<Bicycle>("BI 1234",30);
        BOOST_CHECK_THROW(vehicleManager->removeVehicle(vehicle1),VehicleManagerException);
        BOOST_CHECK_NO_THROW( vehicleManager->addVehicle(vehicle1));
        BOOST_CHECK_THROW(vehicleManager->addVehicle(vehicle1),VehicleManagerException);
        BOOST_CHECK_NO_THROW(vehicleManager->removeVehicle(vehicle1));
    }

BOOST_AUTO_TEST_SUITE_END();