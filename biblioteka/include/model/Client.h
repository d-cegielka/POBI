//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>
#include "Address.h"

using namespace std;

class Client {
private:
    string firstName;
    string lastName;
    string personalID;
    Address *address;
    Address *registredAddress;
public:
    Client(const string &firstName, const string &lastName, const string &personalId,const string &registredAddress_street,
           const string &registredAddress_number, const string &address_street,const string &address_number);
    virtual ~Client();
    string clientInfo();

    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getPersonalId() const;

    void setAddress(string street, string number);
    void setRegistredAddress(string street, string number);
};


#endif //POBIPROJECT_CLIENT_H
