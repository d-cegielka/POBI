//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#include "Exceptions/VehicleException.h"

VehicleException::VehicleException(const std::string &arg) : logic_error(arg) {}

const std::string VehicleException::exceptionVehicleId = "ID pojazdu musi mieć conajmniej 3 znaki!";

const std::string VehicleException::exceptionVehicleBaseRentPrice = "Cena bazowa musi być większa od 0!";

const std::string VehicleException::exceptionMotorVehicleEngineDisplacement = "Pojemność silnika musi być większa od 100 cm3!";

const std::string VehicleException::exceptionCarSegment = "Segment jest niepoprawny! (A,B,C,D,E)";


