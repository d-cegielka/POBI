//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 20.01.2020.
//

#ifndef POBIPROJECT_VEHICLEMANAGEREXCEPTION_H
#define POBIPROJECT_VEHICLEMANAGEREXCEPTION_H

#include <stdexcept>

class VehicleManagerException : public std::logic_error {
public:
    explicit VehicleManagerException(const std::string &arg);

    static const std::string exceptionVehicleExist;

    static const std::string exceptionVehicleNotExist;
};


#endif //POBIPROJECT_VEHICLEMANAGEREXCEPTION_H
