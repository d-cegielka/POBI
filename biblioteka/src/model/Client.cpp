//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#include <iostream>
#include "model/Client.h"
#include "model/Rent.h"

using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId,
               const string &registredAddress_street,  const string &registredAddress_number,
               const string &address_street, const string &address_number) :
               firstName(firstName),
               lastName(lastName),
               personalID(personalId) {
    registredAddress = new Address(registredAddress_street,registredAddress_number);
    address = new Address(address_street,address_number);
}

Client::~Client() {
    delete registredAddress;
    delete address;
}

string Client::clientInfo() {
        return "Imie i nazwisko: " + firstName + " " + lastName +
        "\nPESEL: " + personalID +
        "\nAdres zameldowania: " + registredAddress->getStreet() + " " + registredAddress->getNumber() +
        "\nAdres zamieszkania: " + address->getStreet() + " " + address->getNumber();
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

void Client::setAddress(string street, string number) {
    address->setStreet(street);
    address->setNumber(number);
}

void Client::setRegistredAddress(string street, string number) {
    registredAddress->setStreet(street);
    registredAddress->setNumber(number);
}

bool Client::addRent(Rent *rent) {
    if(find(rents.begin(),rents.end(),rent) == rents.end())
    {
        rents.push_back(rent);
        return true;
    }
    else return false;
}

bool Client::removeRent(Rent *rent) {
    if(find(rents.begin(),rents.end(),rent) != rents.end())
    {
        rents.remove(rent);
        return true;
    }
    else return false;
}


string Client::clientRentsInfo() {
    string info;
    info = "Klient: \n" + clientInfo() + "\nWypożyczenia: \n";
    if(rents.size() !=0) {
        for(auto rent:rents) info += rent->rentInfo() + "\n";
    }
    else info += "Klient nie ma wypożyczonych pojazdów.";

    return info;
}
