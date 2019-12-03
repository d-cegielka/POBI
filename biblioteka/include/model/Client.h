//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>
#include <list>
#include <memory>
#include "Address.h"

class Rent;

typedef std::unique_ptr<Address> AddressPtr;
typedef std::shared_ptr<Rent> RentPtr;

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    AddressPtr registredAddress;
    std::list<RentPtr> rents;
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,const std::string &registredAddress_street,
           const std::string &registredAddress_number, const std::string &address_street, const std::string &address_number);
    virtual ~Client();
    std::string clientInfo();
    std::string clientRentsInfo();

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;

    void setAddress(std::string street, std::string number);
    void setRegistredAddress(std::string street, std::string number);

    bool addRent(RentPtr rent);
    bool removeRent(RentPtr rent);
};


#endif //POBIPROJECT_CLIENT_H
