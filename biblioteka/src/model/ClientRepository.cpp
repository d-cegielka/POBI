//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/ClientRepository.h"
#include <algorithm>

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {

}

void ClientRepository::createClient(const ClientPtr &client) {
    if(find(listOfClients.begin(), listOfClients.end(), client) == listOfClients.end())
        listOfClients.push_back(client);
}

void ClientRepository::removeClient(const ClientPtr &client) {
    if(find(listOfClients.begin(), listOfClients.end(), client) != listOfClients.end())
        listOfClients.remove(client);
}

void ClientRepository::changeClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}
