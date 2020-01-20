//
// Created by Kamil Zarych <224546@edu.p.lodz.pl> on 07.01.2020.
//

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>
#include <model/ClientManager.h>
#include <model/ClientManagerException.h>
#include <model/ClientRepository.h>

using namespace std;
typedef shared_ptr<ClientManager> ClientManagerPtr;

BOOST_AUTO_TEST_SUITE(ClientManagerSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerAddClientTestCase) {
            ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();
            ClientManagerPtr clientManager = make_shared<ClientManager>(clientRepo);

            ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
            clientManager->addClient(client1);
            BOOST_REQUIRE_EQUAL(clientManager->operator()(client1->getId()), client1);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRemoveClientTestCase) {
            ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();
            ClientManagerPtr clientManager = make_shared<ClientManager>(clientRepo);

            ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
            clientManager->addClient(client1);
            BOOST_REQUIRE_EQUAL(clientManager->operator()(client1->getId()), client1);
            clientManager->removeClient(client1);
            BOOST_REQUIRE_EQUAL(clientManager->operator()(client1->getId()), nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerExceptionTestCase) {
        ClientRepositoryPtr clientRepo = make_shared<ClientRepository>();
        ClientManagerPtr clientManager = make_shared<ClientManager>(clientRepo);

        ClientPtr client1 = make_shared<Client>("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
        BOOST_CHECK_THROW(clientManager->removeClient(client1),ClientManagerException);
        BOOST_CHECK_NO_THROW(clientManager->addClient(client1));
        BOOST_CHECK_THROW(clientManager->addClient(client1),ClientManagerException);
        BOOST_CHECK_NO_THROW(clientManager->removeClient(client1));
    }

BOOST_AUTO_TEST_SUITE_END();