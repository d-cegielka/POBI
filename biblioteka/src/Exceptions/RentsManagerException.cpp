//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#include "Exceptions/RentsManagerException.h"

RentsManagerException::RentsManagerException(const std::string &arg) : logic_error(arg) {}

const std::string RentsManagerException::exceptionClientNullPtr = "Klient jest niepoprawny! (nullptr)";

const std::string RentsManagerException::exceptionVehicleNullPtr = "Pojazd jest niepoprawny! (nullptr)";

const std::string RentsManagerException::exceptionIncorrectRentalDate = "Nieprawidłowa data wypożyczenia (nie może być z przyszłości)!";

const std::string RentsManagerException::exceptionVehicleNotAvailable = "Pojazd jest obecnie wypożyczony!";

const std::string RentsManagerException::exceptionClientReachLimitOfRentedVehicles = "Klient osiągnał limit wypożycznych pojazdów!";

const std::string RentsManagerException::exceptionVehicleAvailable = "Nie można zwrócić pojazdu, ponieważ nie został wypożyczony!";