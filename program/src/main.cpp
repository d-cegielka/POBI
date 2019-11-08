#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client k1("Waldemar","Nowak","92875697851", "Warszawska", "22","Batorego","55G");
    Client k2("Jan","Kowalski","87110701881","Spokojna","1","Głośna","12");
    cout<<k1.clientInfo()<<endl;
    cout<<k2.clientInfo()<<endl;

    k1.setAddress("Gdańska","110");
    k2.setAddress("Błotna","55");

    cout<<k1.clientInfo()<<endl;
    cout<<k2.clientInfo()<<endl;

    return 0;
}