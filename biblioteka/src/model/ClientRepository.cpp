//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/ClientRepository.h"

void ClientRepository::changeClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}




