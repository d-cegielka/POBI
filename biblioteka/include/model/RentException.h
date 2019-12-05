//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#ifndef POBIPROJECT_RENTEXCEPTION_H
#define POBIPROJECT_RENTEXCEPTION_H


#include <stdexcept>

class RentException : public std::logic_error {
public:
    explicit RentException(const std::string &arg);
};


#endif //POBIPROJECT_RENTEXCEPTION_H
