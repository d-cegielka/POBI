//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 04.12.2019.
//

#ifndef POBIPROJECT_CLIENTREPOSITORY_H
#define POBIPROJECT_CLIENTREPOSITORY_H

#include "model/Client.h"
#include "Repository.h"

typedef std::shared_ptr<Client> ClientPtr;

class ClientRepository : public Repository<Client> {
public:
    virtual void changeClientType(ClientPtr client, ClientTypePtr clientType);
};

#endif //POBIPROJECT_CLIENTREPOSITORY_H
