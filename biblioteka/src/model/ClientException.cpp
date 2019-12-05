//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 05.12.2019.
//

#include "model/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg) {}
