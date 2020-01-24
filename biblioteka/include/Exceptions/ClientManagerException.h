//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.01.2020.
//

#ifndef POBIPROJECT_CLIENTMANAGEREXCEPTION_H
#define POBIPROJECT_CLIENTMANAGEREXCEPTION_H

#include <stdexcept>

class ClientManagerException : public std::logic_error {
public:
    explicit ClientManagerException(const std::string &arg);

    static const std::string exceptionClientExist;

    static const std::string exceptionClientNotExist;

};


#endif //POBIPROJECT_CLIENTMANAGEREXCEPTION_H
