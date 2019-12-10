//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 10.12.2019.
//

#include <iostream>
#include "model/ClientManager.h"

ClientManager::ClientManager(const ClientRepositoryPtr &clients) : clients(clients) {}

ClientManager::~ClientManager() {}

void ClientManager::addClient(const ClientPtr &client) {
    if(!clients->findClient(client))
        clients->createClient(client);

}

void ClientManager::removeClient(const ClientPtr &client) {
    if(clients->findClient(client))
        clients->removeClient(client);
}
