//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>
#include <list>
#include <memory>
#include "Address.h"
#include "ClientType.h"

class Rent;

typedef std::unique_ptr<Address> AddressPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;

class Client {
private:
    const std::string firstName;
    const std::string lastName;
    const std::string personalID;
    AddressPtr address;
    AddressPtr registredAddress;
    ClientTypePtr clientType;
    std::list<RentPtr> rents;
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,const std::string &registredAddress_street,
           const std::string &registredAddress_number, const std::string &address_street, const std::string &address_number);
    virtual ~Client();
    const std::string clientInfo() const;
    const std::string clientRentsInfo() const;

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;

    void setAddress(std::string street, std::string number);
    void setRegistredAddress(std::string street, std::string number);

    void setClientType(const ClientTypePtr &clientType);
    const std::string getClientType() const;
    const int getMaxNumOfRentalVehicles() const;
    const int getClientDiscount(int RentPrice) const;

    bool addRent(RentPtr rent);
    bool removeRent(RentPtr rent);
};


#endif //POBIPROJECT_CLIENT_H
