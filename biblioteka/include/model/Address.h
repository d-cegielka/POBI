//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_ADDRESS_H
#define POBIPROJECT_ADDRESS_H

#include <string>

class Address {
private:
    std::string street;
    std::string number;
public:
    Address(const std::string &street, const std::string &number);

    virtual ~Address();

    const std::string &getStreet() const;

    void setStreet(const std::string &street);

    const std::string &getNumber() const;

    void setNumber(const std::string &number);

};


#endif //POBIPROJECT_ADDRESS_H
