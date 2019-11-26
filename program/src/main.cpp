#include <iostream>
#include <model/Car.h>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/CurrentRentsRepository.h"
#include "model/VehicleRepository.h"
#include "RentalGenerator.h"


using namespace boost::local_time;
using namespace boost::posix_time;
using namespace std;

int main() {
    /*Client k1("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
    Client k2("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
    Vehicle vehicle1("WW5698",180);
    Vehicle vehicle2("PO9258",140);
    CurrentRentsRepository* rentsRepository = new CurrentRentsRepository();
    time_zone_ptr zone(new posix_time_zone("CET"));
    local_date_time *rentalDateTime1 = new local_date_time(local_sec_clock::local_time(zone)-hours(51));
    //local_date_time *rentalDateTime2 = new local_date_time(local_sec_clock::local_time(zone)-hours(258));
    Rent rent1(rentalDateTime1,&k1,&vehicle1,rentsRepository);
    Rent rent2(&k2,&vehicle2,rentsRepository);
    Rent rent3(&k2,&vehicle1,rentsRepository);
    cout<<rent1.rentInfo()<<endl;
    cout<<rent2.rentInfo()<<endl;
    rent1.returnVehicle();
    cout<<rent1.rentInfo()<<endl;*/
    VehicleRepository* v_repository = new VehicleRepository();
    RentalGenerator* rentalGenerator = new RentalGenerator(v_repository);

    return 0;
}