//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#ifndef POBIPROJECT_RENTSMANAGEREXCEPTION_H
#define POBIPROJECT_RENTSMANAGEREXCEPTION_H

#include <stdexcept>

class RentsManagerException : public std::logic_error {
public:
    explicit RentsManagerException(const std::string &arg);

    static const std::string exceptionClientNullPtr;

    static const std::string exceptionVehicleNullPtr;

    static const std::string exceptionIncorrectRentalDate;

    static const std::string exceptionVehicleNotAvailable;

    static const std::string exceptionClientReachLimitOfRentedVehicles;

    static const std::string exceptionVehicleAvailable;
};


#endif //POBIPROJECT_RENTSMANAGEREXCEPTION_H
