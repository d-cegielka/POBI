//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#include <model/Car.h>
#include <model/Mope.h>
#include <model/Bicycle.h>
#include <model/ClientRepository.h>
#include <model/VehicleRepository.h>
#include <model/RentsManager.h>
#include "RentalGenerator.h"
#include <iostream>
#include <memory>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;

typedef shared_ptr<Car> CarPtr;
typedef shared_ptr<Mope> MopePtr;
typedef shared_ptr<Bicycle> BicyclePtr;
typedef shared_ptr<RentsManager> RentsManagerPtr;

RentalGenerator::RentalGenerator(VehicleRepositoryPtr vehicleRepository, ClientRepositoryPtr clientRepository, CurrentRentsRepositoryPtr archiveRent, CurrentRentsRepositoryPtr currentRent) :
                                vehicleRepository(vehicleRepository), clientRepository(clientRepository), archiveRents(archiveRent), currentRents(currentRent) {

    RentsManagerPtr rentsManager = make_shared<RentsManager>(currentRent, archiveRent, vehicleRepository, clientRepository);

    ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
    ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");

    clientRepository->createClient(client1);
    clientRepository->createClient(client2);

    CarPtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
    CarPtr car2 = make_shared<Car>("CA2222", 6000, 1300, 'E');
    CarPtr car3 = make_shared<Car>("CA3333", 130, 1500, 'C');
    CarPtr car4 = make_shared<Car>("CA4444", 140, 2000, 'B');

    MopePtr mope1 = make_shared<Mope>("MO1111", 60, 1050);
    MopePtr mope2 = make_shared<Mope>("MO2222", 80, 1450);
    MopePtr mope3 = make_shared<Mope>("MO3333", 220, 1600);
    MopePtr mope4 = make_shared<Mope>("MO4444", 340, 1200);

    BicyclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
    BicyclePtr bicycle2 = make_shared<Bicycle>("BC2222", 45);

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

    time_zone_ptr zone(new posix_time_zone("CET"));
    local_date_timePtr rentTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(23));
    rentsManager->rentVehicle(client1, car2, rentTime);
    cout<<client1->clientInfo()<<endl;
    cout<<client1->clientRentsInfo();
    rentsManager->returnVehicle(car2);
    cout<<client1->clientRentsInfo()<<endl;
    cout<<client1->clientInfo()<<endl;
    cout<<rentsManager->checkClientRentBallance(client1)<<endl;

    rentsManager->rentVehicle(client1, car2, rentTime);
    rentsManager->returnVehicle(car2);
    cout<<client1->clientRentsInfo()<<endl;
    cout<<client1->clientInfo()<<endl;
    cout<<rentsManager->checkClientRentBallance(client1)<<endl;
    //std::cout<<vehicleRepository->vehicleReport();
}

RentalGenerator::~RentalGenerator() {}
