//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.01.2020.
//

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include <model/VehicleRepository.h>
#include <model/Car.h>
#include <model/Bicycle.h>
#include <model/Mope.h>

using namespace std;
using namespace boost::algorithm;

BOOST_AUTO_TEST_SUITE(VehicleRepositorySuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryReportTestCase) {
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr car2 = make_shared<Car>("CA2222", 1000, 1300, 'E');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        VehiclePtr bicycle2 = make_shared<Bicycle>("BC2222", 45);
        VehiclePtr mope1 = make_shared<Mope>("MO1111", 60, 1050);
        VehiclePtr mope2 = make_shared<Mope>("MO2222", 80, 1450);

        VehicleRepository repository;
        repository.create(car1);
        repository.create(car2);
        repository.create(bicycle1);
        repository.create(bicycle2);
        repository.create(mope1);
        repository.create(mope2);

        string report = repository.vehicleReport();

        BOOST_REQUIRE_EQUAL(contains(report, "CA1111"), true);
        BOOST_REQUIRE_EQUAL(contains(report, "BC2222"), true);
        BOOST_REQUIRE_EQUAL(contains(report, "MO2222"), true);
        BOOST_REQUIRE_EQUAL(contains(report, "Cena wypożyczenia: 60"), true);
        BOOST_REQUIRE_EQUAL(contains(report, "Cena wypożyczenia: 1000"), true);
        BOOST_REQUIRE_EQUAL(contains(report, "Segment: E"), true);
        BOOST_REQUIRE_EQUAL(contains(report, "Pojemność silnika: 1450"), true);

    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetAllTestCase) {
        VehiclePtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
        VehiclePtr car2 = make_shared<Car>("CA2222", 1000, 1300, 'E');
        VehiclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
        VehiclePtr bicycle2 = make_shared<Bicycle>("BC2222", 45);
        VehiclePtr mope1 = make_shared<Mope>("MO1111", 60, 1050);
        VehiclePtr mope2 = make_shared<Mope>("MO2222", 80, 1450);

        VehicleRepository repository;
        repository.create(car1);
        repository.create(car2);
        repository.create(bicycle1);
        repository.create(bicycle2);
        repository.create(mope1);
        repository.create(mope2);

        list<VehiclePtr> vehicleList1;
        vehicleList1.push_back(car1);
        vehicleList1.push_back(car2);
        vehicleList1.push_back(bicycle1);
        vehicleList1.push_back(bicycle2);
        vehicleList1.push_back(mope1);
        vehicleList1.push_back(mope2);

        bool result = true;
        for(auto vehicle:vehicleList1){
            if(vehicle != repository.find(vehicle))
                result = false;
        }

        BOOST_REQUIRE_EQUAL(result, true);
    }


BOOST_AUTO_TEST_SUITE_END();