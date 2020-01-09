//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 09.01.2020.
//

#include "model/ClientManagerException.h"

ClientManagerException::ClientManagerException(const std::string &arg) : logic_error(arg) {}

const std::string ClientManagerException::exceptionClientExist = "Taki klient juz istnieje, nie mozna dodac klienta!";

const std::string ClientManagerException::exceptionClientNotExist = "Taki klient nie istnieje, nie mozna usunac klienta!";