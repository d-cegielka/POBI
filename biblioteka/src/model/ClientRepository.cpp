//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/ClientRepository.h"
#include <algorithm>

bool operator ==(const ClientPtr & client1, const ClientPtr & client2) {
   return (client1->getPersonalId() == client2->getPersonalId());
}

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {

}

void ClientRepository::createClient(const ClientPtr &client) {
        listOfClients.push_back(client);
}

void ClientRepository::removeClient(const ClientPtr &client) {
        listOfClients.remove(client);
}

void ClientRepository::changeClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}

const bool ClientRepository::findClient(const ClientPtr &client) const {
    if(find(listOfClients.begin(), listOfClients.end(), client) != listOfClients.end())
        return true;

    return false;
}
