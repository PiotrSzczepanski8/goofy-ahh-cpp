#include <iostream>
#include "napoj.h"
#include <vector>
using namespace std;

class Automat {
    private:
        int pojemnosc;
        vector <Napoj> magazyn;
    public:
        Automat(int p);
        void napelnij(string n, int i, double c);
        void sprzedaj(string n, int i, double c, double k);
        vector <Napoj>& getMagazyn();
};