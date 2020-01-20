//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 20.01.2020.
//

#include "model/VehicleManagerException.h"

VehicleManagerException::VehicleManagerException(const std::string &arg) : logic_error(arg) {}

const std::string VehicleManagerException::exceptionVehicleExist = "Taki pojazd juz istnieje, nie mozna dodac pojazdu!";

const std::string VehicleManagerException::exceptionVehicleNotExist = "Taki pojazd nie istnieje, nie mozna usunac pojazdu!";