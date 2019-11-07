#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client k1("Waldemar","Nowak","92875697851");
    Client k2("Jan","Kowalski","87110701881");
    cout<<k1.clientInfo()<<endl;
    cout<<k2.clientInfo()<<endl;


    return 0;
}