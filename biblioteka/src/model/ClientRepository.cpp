//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/ClientRepository.h"

/*bool operator==(const ClientPtr &client1, const ClientPtr &client2) {
    return (client1->getPersonalId() == client2->getId());
}*/

void ClientRepository::changeClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}




