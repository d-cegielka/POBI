//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>
#include <list>
#include "Address.h"

class Rent;

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address *address;
    Address *registredAddress;
    std::list<Rent *> rents;
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

    bool addRent(Rent *rent);
    bool removeRent(Rent *rent);
};


#endif //POBIPROJECT_CLIENT_H
