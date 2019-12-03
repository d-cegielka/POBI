//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#include <model/Car.h>
#include <model/Mope.h>
#include <model/Bicycle.h>
#include <model/VehicleRepository.h>
#include "RentalGenerator.h"
#include <iostream>
#include <memory>

using namespace std;

typedef shared_ptr<Car> CarPtr;
typedef shared_ptr<Mope> MopePtr;
typedef shared_ptr<Bicycle> BicyclePtr;

RentalGenerator::RentalGenerator(VehicleRepositoryPtr vehicleRepository) : vehicleRepository(vehicleRepository) {

    CarPtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
    CarPtr car2 = make_shared<Car>("CA2222", 120, 1300, 'E');
    CarPtr car3 = make_shared<Car>("CA3333", 130, 1500, 'C');
    CarPtr car4 = make_shared<Car>("CA4444", 140, 2000, 'B');

    MopePtr mope1 = make_shared<Mope>("MO1111", 60, 1050);
    MopePtr mope2 = make_shared<Mope>("MO2222", 80, 1450);
    MopePtr mope3 = make_shared<Mope>("MO3333", 220, 1600);
    MopePtr mope4 = make_shared<Mope>("MO4444", 340, 1200);

    BicyclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
    BicyclePtr bicycle2 = make_shared<Bicycle>("BC1111", 45);

    vehicleRepository->addVehicle(car1);
    vehicleRepository->addVehicle(car2);
    vehicleRepository->addVehicle(car3);
    vehicleRepository->addVehicle(car4);

    vehicleRepository->addVehicle(mope1);
    vehicleRepository->addVehicle(mope2);
    vehicleRepository->addVehicle(mope3);
    vehicleRepository->addVehicle(mope4);

    vehicleRepository->addVehicle(bicycle1);
    vehicleRepository->addVehicle(bicycle2);

    std::cout<<vehicleRepository->vehicleReport();
}

RentalGenerator::~RentalGenerator() {

}
