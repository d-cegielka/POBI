//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 07.01.2020.
//

#include <boost/test/unit_test.hpp>
#include <Repositories/ClientRepository.h>
#include <Managers/ClientManager.h>
#include <ClientTypes/VipClientType.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(ClientRepositorySuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientTestCase) {
        ClientPtr client1 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();

        clientRepo->create(client1);

        list<ClientPtr> clientList;
        clientList.push_back(client1);

        bool result = true;
        for(auto client:clientList){
            if(client != clientRepo->find(client))
                result = false;
        }

        BOOST_REQUIRE_EQUAL(result, true);

    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryChangeClientTypeTestCase) {
        ClientPtr client1 = make_shared<Client>("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
        ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();

        clientRepo->create(client1);
        BOOST_REQUIRE_EQUAL(client1->getClientType(), "Typ klienta: Standard");
        clientRepo->changeClientType(client1,make_shared<VipClientType>());
        BOOST_REQUIRE_EQUAL(client1->getClientType(), "Typ klienta: VIP");

    }


BOOST_AUTO_TEST_SUITE_END();