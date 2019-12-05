//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#include <iostream>
#include "model/Client.h"
#include "model/Rent.h"
#include "model/StandardClientType.h"
#include "model/ClientException.h"

using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId,
               const string &registredAddress_street,  const string &registredAddress_number,
               const string &address_street, const string &address_number) :
               firstName(firstName),
               lastName(lastName),
               personalID(personalId),
               address(new Address(address_street,address_number)),
               registredAddress(new Address(registredAddress_street,registredAddress_number)),
               clientType(new StandardClientType()) {
    if(firstName == "")
        throw ClientException("Imię jest wymagane!");
    if(lastName == "")
        throw ClientException("Nazwisko jest wymagane!");
    if(personalId == "")
        throw ClientException("PESEL jest wymagany!");
}

Client::~Client() {}

const string Client::clientInfo() const {
    string infoClient;
    infoClient.append("Imie i nazwisko: ").append(firstName).append(" ").append(lastName)
            .append("\nPESEL: ").append(personalID).append("\nAdres zameldowania: ")
            .append(registredAddress->getStreet()).append(" ").append(registredAddress->getNumber())
            .append("\nAdres zamieszkania: ").append(address->getStreet()).append(" ").append(
                    address->getNumber()).append("\n").append(getClientType()).append("\n");
    return infoClient;
}

const string &Client::getFirstName() const {
    return firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

const string &Client::getPersonalId() const {
    return personalID;
}

void Client::setAddress(const string &street, const string &number) {
    address->setStreet(street);
    address->setNumber(number);
}

void Client::setRegistredAddress(const string &street, const string &number) {
    registredAddress->setStreet(street);
    registredAddress->setNumber(number);
}

void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}

const string Client::getClientType() const {
    return clientType->getClientType();
}

const int Client::getMaxNumOfRentalVehicles() const {
    return clientType->getNumOfRentalVehicles();
}

const double Client::getClientDiscount(double RentPrice) const {
    return clientType->getDiscount(RentPrice);
}


void Client::addRent(const RentPtr &rent) {
    if(find(rents.begin(),rents.end(),rent) == rents.end())
        rents.push_back(rent);
}

void Client::removeRent(const RentPtr &rent) {
    if(find(rents.begin(),rents.end(),rent) != rents.end())
        rents.remove(rent);
}


const string Client::clientRentsInfo() const {
    string info;
    info.append("\nWypożyczenia: \n");
    if(rents.size() !=0) {
        for(auto rent:rents) info.append(rent->rentInfo()).append("\n");
    }
    else info.append("Klient nie ma wypożyczonych pojazdów.");

    return info;
}

const int Client::getNumOfClientRents() const {
    return rents.size();
}

const list<RentPtr> &Client::getRentsList() const {
    return rents;
}

