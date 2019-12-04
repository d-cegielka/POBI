//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#include "model/ClientRepository.h"
#include <algorithm>

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {

}

bool ClientRepository::createClient(ClientPtr client) {
    if(find(listOfClients.begin(), listOfClients.end(), client) == listOfClients.end())
    {
        listOfClients.push_back(client);
        return true;
    }
    else return false;
}

bool ClientRepository::removeClient(ClientPtr client) {
    if(find(listOfClients.begin(), listOfClients.end(), client) != listOfClients.end())
    {
        listOfClients.remove(client);
        return true;
    }
    else return false;
}

void ClientRepository::changeClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}
