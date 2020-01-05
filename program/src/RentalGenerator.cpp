//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#include <model/Car.h>
#include <model/Mope.h>
#include <model/Bicycle.h>
#include <model/ClientRepository.h>
#include <model/VehicleRepository.h>
#include <model/RentsManager.h>
#include <model/ClientManager.h>
#include <model/VehicleManager.h>
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
typedef shared_ptr<ClientManager> ClientManagerPtr;
typedef shared_ptr<VehicleManager> VehicleManagerPtr;

RentalGenerator::RentalGenerator(VehicleRepositoryPtr vehicleRepository, ClientRepositoryPtr clientRepository, RentsRepositoryPtr archiveRent, RentsRepositoryPtr currentRent) :
                                vehicleRepository(vehicleRepository), clientRepository(clientRepository), archiveRents(archiveRent), currentRents(currentRent) {

    RentsManagerPtr rentsManager = make_shared<RentsManager>(currentRent, archiveRent, vehicleRepository, clientRepository);
    ClientManagerPtr clientManager = make_shared<ClientManager>(clientRepository);
    VehicleManagerPtr vehicleManager = make_shared<VehicleManager>(vehicleRepository);

    ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
    ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
    ClientPtr client3 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");

    clientManager->addClient(client1);
    clientManager->addClient(client2);
    clientManager->addClient(client3);
    clientManager->addClient(client1);

    CarPtr car1 = make_shared<Car>("CA1111", 110, 1000, 'A');
    CarPtr car2 = make_shared<Car>("CA2222", 1000, 1300, 'E');
    CarPtr car3 = make_shared<Car>("CA3333", 130, 1500, 'C');
    CarPtr car4 = make_shared<Car>("CA4444", 140, 2000, 'B');

    MopePtr mope1 = make_shared<Mope>("MO1111", 60, 1050);
    MopePtr mope2 = make_shared<Mope>("MO2222", 80, 1450);
    MopePtr mope3 = make_shared<Mope>("MO3333", 220, 1600);
    MopePtr mope4 = make_shared<Mope>("MO4444", 340, 1200);

    BicyclePtr bicycle1 = make_shared<Bicycle>("BC1111", 20);
    BicyclePtr bicycle2 = make_shared<Bicycle>("BC2222", 45);

    vehicleManager->addVehicle(car1);
    vehicleManager->addVehicle(car2);
    vehicleManager->addVehicle(car3);
    vehicleManager->addVehicle(car4);

    vehicleManager->addVehicle(mope1);
    vehicleManager->addVehicle(mope2);
    vehicleManager->addVehicle(mope3);
    vehicleManager->addVehicle(mope4);

    vehicleManager->addVehicle(bicycle1);
    vehicleManager->addVehicle(bicycle2);
    vehicleManager->addVehicle(bicycle2);

    time_zone_ptr zone(new posix_time_zone("CET"));
    local_date_timePtr rentTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(23));
    rentsManager->rentVehicle(client1, car2, rentTime);
    cout<<client1->clientInfo()<<endl;
    cout<<client1->clientRentsInfo();
    rentsManager->returnVehicle(car2);
    cout<<client1->clientInfo()<<endl;
    cout<<client1->clientRentsInfo()<<endl;
    cout<<rentsManager->checkClientRentBallance(client1)<<endl;

    rentsManager->rentVehicle(client1, car2, rentTime);
    //rentsManager->rentVehicle(client1, car2, rentTime);
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
