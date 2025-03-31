#include <iostream>
using namespace std;
#pragma once

class Napoj {
    private:
        string nazwa;
        double cena;
    public:
        Napoj(string n, double c);
        string getNazwa();
        double getCena();
};