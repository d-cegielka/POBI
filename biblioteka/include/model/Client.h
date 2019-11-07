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
public:
    Client();
    Client(const string &firstName, const string &lastName, const string &personalId);
    virtual ~Client();
    string clientInfo();
};


#endif //POBIPROJECT_CLIENT_H
