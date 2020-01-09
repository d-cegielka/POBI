//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#include "model/Client.h"
#include "model/Rent.h"
#include "model/StandardClientType.h"
#include "model/ClientException.h"
#include "model/Address.h"

using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId,
               const string &registredAddress_street,  const string &registredAddress_number,
               const string &address_street, const string &address_number) :
               firstName(firstName),
               lastName(lastName),
               personalID(personalId),
               address(make_unique<Address>(address_street,address_number)),
               registredAddress(make_unique<Address>(registredAddress_street,registredAddress_number)),
               clientType(make_shared<StandardClientType>()) {
    if(firstName.empty())
        throw ClientException(ClientException::exceptionClientFirstName);
    if(lastName.empty())
        throw ClientException(ClientException::exceptionClientLastName);
    if(personalId.empty())
        throw ClientException(ClientException::exceptionClientPersonalId);
    if(registredAddress_street.empty() or registredAddress_number.empty())
        throw ClientException(ClientException::exceptionClientRegistredAddress);
    if(address_street.empty() or address_number.empty())
        throw ClientException(ClientException::exceptionClientAddress);
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

const string &Client::getId() const {
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
        for(auto rent:rents)
            info.append(rent->rentInfo()).append("\n");
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

bool Client::operator==(const Client &client) const {
    return personalID == client.personalID;
}