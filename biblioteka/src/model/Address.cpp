//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#include "model/Address.h"

using namespace std;

Address::Address(const string &street, const string &number) : street(street), number(number) {}

Address::~Address() {}

const string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

const string &Address::getNumber() const {
    return number;
}

void Address::setNumber(const string &number) {
    Address::number = number;
}



