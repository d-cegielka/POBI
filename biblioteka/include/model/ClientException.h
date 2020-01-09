//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#ifndef POBIPROJECT_CLIENTEXCEPTION_H
#define POBIPROJECT_CLIENTEXCEPTION_H

#include <stdexcept>

class ClientException : public std::logic_error{
public:
    explicit ClientException(const std::string &arg);

    static const std::string exceptionClientFirstName;

    static const std::string exceptionClientLastName;

    static const std::string exceptionClientPersonalId;

    static const std::string exceptionClientRegistredAddress;

    static const std::string exceptionClientAddress;

};


#endif //POBIPROJECT_CLIENTEXCEPTION_H
