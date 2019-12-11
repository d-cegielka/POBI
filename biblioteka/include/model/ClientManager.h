//
// Created by Dominik Cegiełka <224478@edu.p.lodz.pl> on 10.12.2019.
//

#ifndef POBIPROJECT_CLIENTMANAGER_H
#define POBIPROJECT_CLIENTMANAGER_H

#include "model/ClientRepository.h"

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

class ClientManager {
private:
    ClientRepositoryPtr clients;
public:
    ClientManager(const ClientRepositoryPtr &clients);

    virtual ~ClientManager();

    void addClient(const ClientPtr &client);

    void removeClient(const ClientPtr  &client);

    ClientPtr operator()(const std::string ID);
};


#endif //POBIPROJECT_CLIENTMANAGER_H
