//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#ifndef POBIPROJECT_VEHICLEEXCEPTION_H
#define POBIPROJECT_VEHICLEEXCEPTION_H


#include <stdexcept>

class VehicleException : public std::logic_error{
public:
    explicit VehicleException(const std::string &arg);
};


#endif //POBIPROJECT_VEHICLEEXCEPTION_H
