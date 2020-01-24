//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#include "Exceptions/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg) {}

const std::string ClientException::exceptionClientFirstName = "Imię jest wymagane!";

const std::string ClientException::exceptionClientLastName = "Nazwisko jest wymagane!";

const std::string ClientException::exceptionClientPersonalId = "Numer PESEL jest wymagany!";

const std::string ClientException::exceptionClientRegistredAddress = "Ulica i numer domu jest wymagany w adresie zameldowania!";

const std::string ClientException::exceptionClientAddress = "Ulica i numer domu jest wymagany w adresie zamieszkania!";