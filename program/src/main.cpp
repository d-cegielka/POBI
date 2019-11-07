#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client k1;
    Client k2("Jan","Kowalski","87110701881");
    cout<<k1.clientInfo()<<endl;
    cout<<k2.clientInfo()<<endl;
    //k1.firstName = "Stefan";

    return 0;
}