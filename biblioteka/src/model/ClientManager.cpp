//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 10.12.2019.
//

#include "model/ClientManager.h"
#include "model/ClientManagerException.h"
#include "model/ClientRepository.h"

ClientManager::ClientManager(const ClientRepositoryPtr &clients) : clients(clients) {}

ClientManager::~ClientManager() = default;

void ClientManager::addClient(const ClientPtr &client) {
    if(clients->find(client) != nullptr)
        throw ClientManagerException(ClientManagerException::exceptionClientExist);
    clients->create(client);
}

void ClientManager::removeClient(const ClientPtr &client) {
    if(clients->find(client) == nullptr)
        throw ClientManagerException(ClientManagerException::exceptionClientNotExist);
    clients->remove(client);
}

ClientPtr ClientManager::operator()(const std::string ID) {
    return ClientPtr(clients->find(ID));
}
