//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 07.11.2019.
//

#ifndef POBIPROJECT_CLIENT_H
#define POBIPROJECT_CLIENT_H

#include <string>

using namespace std;

class Client {
private:
    string firstName;
    string lastName;
    string personalID;
    string address;
    string registredAddress;
public:
    Client();
    Client(const string &firstName, const string &lastName, const string &personalId);
    virtual ~Client();
    string clientInfo();

    const string &getFirstName() const;

    const string &getLastName() const;

    const string &getPersonalId() const;
};


#endif //POBIPROJECT_CLIENT_H
