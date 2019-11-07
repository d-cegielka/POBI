//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#include <iostream>
#include "model/Client.h"

using namespace std;

Client::Client() : firstName("IMIĘ"), lastName("NAZWISKO"), personalID("PESEL"){
    cout << "Konstruktor bezparametrowy Client zostal wywolany" << endl;
}

Client::Client(const string &firstName, const string &lastName, const string &personalId) : firstName(firstName),
                                                                                            lastName(lastName),
                                                                                            personalID(personalId) {
    cout << "Konstruktor parametrowy Client zostal wywolany" << endl;
}

Client::~Client() {
    cout << "Destruktor Client zostal wywolany" << endl;
}

string Client::clientInfo() {
        return "Imie i nazwisko: " + firstName + " " + lastName +
        "\nPESEL " + personalID;
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
