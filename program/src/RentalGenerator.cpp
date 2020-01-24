//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 26.11.2019.
//

#include <Vehicles/Car.h>
#include <Vehicles/Mope.h>
#include <Vehicles/Bicycle.h>
#include <Repositories/ClientRepository.h>
#include <Repositories/VehicleRepository.h>
#include <Repositories/RentsRepository.h>
#include <Managers/RentsManager.h>
#include <Managers/ClientManager.h>
#include <Managers/VehicleManager.h>
#include "RentalGenerator.h"
#include <iostream>
#include <memory>
#include <Exceptions/ClientException.h>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;

typedef shared_ptr<Car> CarPtr;
typedef shared_ptr<Mope> MopePtr;
typedef shared_ptr<Bicycle> BicyclePtr;
typedef shared_ptr<RentsManager> RentsManagerPtr;
typedef shared_ptr<ClientManager> ClientManagerPtr;
typedef shared_ptr<VehicleManager> VehicleManagerPtr;

RentalGenerator::RentalGenerator() : vehicleRepository(make_shared<VehicleRepository>()), clientRepository(make_shared<ClientRepository>()),
                archiveRents(make_shared<RentsRepository>()), currentRents(make_shared<RentsRepository>()) {

    RentsManagerPtr rentsManager = make_shared<RentsManager>(currentRents, archiveRents, vehicleRepository, clientRepository);
    ClientManagerPtr clientManager = make_shared<ClientManager>(clientRepository);
    VehicleManagerPtr vehicleManager = make_shared<VehicleManager>(vehicleRepository);
    try {
        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        ClientPtr client2 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");

        clientManager->addClient(client1);
        clientManager->addClient(client2);

        CarPtr car1 = make_shared<Car>("CA1111", 110, 1200, 'A');
        CarPtr car2 = make_shared<Car>("CA2222", 1400, 4200, 'E');
        CarPtr car3 = make_shared<Car>("CA3333", 160, 1700, 'C');
        CarPtr car4 = make_shared<Car>("CA4444", 145, 1500, 'B');

        MopePtr mope1 = make_shared<Mope>("MO1111", 45, 50);
        MopePtr mope2 = make_shared<Mope>("MO2222", 70, 250);
        MopePtr mope3 = make_shared<Mope>("MO3333", 90, 750);
        MopePtr mope4 = make_shared<Mope>("MO4444", 160, 1100);

        BicyclePtr bicycle1 = make_shared<Bicycle>("BC1111", 10);
        BicyclePtr bicycle2 = make_shared<Bicycle>("BC2222", 18);

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

        time_zone_ptr zone(new posix_time_zone("CET+1"));
        local_date_timePtr rentTime = make_shared<local_date_time>(local_sec_clock::local_time(zone)-hours(48));
        rentsManager->rentVehicle(client1, car2, rentTime);
        cout<<client1->clientInfo();
        cout<<client1->clientRentsInfo();
        rentsManager->returnVehicle(car2);
        cout<<client1->clientInfo();
        cout<<"Obrót klienta: "<<rentsManager->checkClientRentBallance(client1)<<endl;

        rentsManager->rentVehicle(client1, car1, rentTime);
        cout<<client1->clientRentsInfo();
        rentsManager->returnVehicle(car1);
        cout<<client1->clientRentsInfo()<<endl;
        cout<<"Obrót klienta: "<<rentsManager->checkClientRentBallance(client1)<<endl<<endl;
        rentsManager->rentVehicle(client1, car3, rentTime);
        cout<<client1->clientRentsInfo();
        rentsManager->returnVehicle(car3);
        cout<<client1->clientRentsInfo()<<endl;
        cout<<"Obrót klienta: "<<rentsManager->checkClientRentBallance(client1)<<endl<<endl;

        cout<<"Raport wypozyczeń archiwalnych:\n"<<archiveRents->rentReport();

        cout<<"Raport pojazdow:\n"<<vehicleRepository->vehicleReport();
    }
    catch (logic_error ce) {
        cout << "Przechwycono wyjatek/i: " << ce.what() << endl;
    }
}

RentalGenerator::~RentalGenerator() {}
