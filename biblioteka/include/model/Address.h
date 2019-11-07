//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_ADDRESS_H
#define POBIPROJECT_ADDRESS_H

#include <string>

using namespace std;

class Address {
private:
    string street;
    string number;
public:
    Address();

    virtual ~Address();

    Address(const string &street, const string &number);

    const string &getStreet() const;

    void setStreet(const string &street);

    const string &getNumber() const;

    void setNumber(const string &number);

};


#endif //POBIPROJECT_ADDRESS_H
