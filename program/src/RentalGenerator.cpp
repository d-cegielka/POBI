//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#include <model/Car.h>
#include <model/Mope.h>
#include <model/Bicycle.h>
#include <model/VehicleRepository.h>
#include "RentalGenerator.h"
#include <iostream>

RentalGenerator::RentalGenerator(VehicleRepository *vehicleRepository) : vehicleRepository(vehicleRepository) {

    Car car1("CA1111",110,1000,'A');
    Car car2("CA2222",120,1300,'E');
    Car car3("CA3333",130,1500,'C');
    Car car4("CA4444",140,2000,'B');

    Mope mope1("MO1111",60,1050);
    Mope mope2("MO2222",80,1450);
    Mope mope3("MO3333",220,1600);
    Mope mope4("MO4444",340,1200);

    Bicycle bicycle1("BC1111",20);
    Bicycle bicycle2("BC1111",45);

    vehicleRepository->addVehicle(&car1);
    vehicleRepository->addVehicle(&car2);
    vehicleRepository->addVehicle(&car3);
    vehicleRepository->addVehicle(&car4);

    vehicleRepository->addVehicle(&mope1);
    vehicleRepository->addVehicle(&mope2);
    vehicleRepository->addVehicle(&mope3);
    vehicleRepository->addVehicle(&mope4);

    vehicleRepository->addVehicle(&bicycle1);
    vehicleRepository->addVehicle(&bicycle2);

    std::cout<<vehicleRepository->vehicleReport();
}

RentalGenerator::~RentalGenerator() {

}
