#include <iostream>
#include "RentalGenerator.h"

using namespace std;

int main() {
    RentalGenerator* rentalGenerator = new RentalGenerator();
    delete rentalGenerator;
    return 0;
}