#include "automat.h"
#include <algorithm>

void Automat::napelnij(string n, int ilosc, double c){
    if(ilosc + magazyn.size() <= pojemnosc){
        for (int i = 0; i < ilosc; i++){
            magazyn.push_back(Napoj(n, c));
        }
        cout << "napoje zostaly dodane"<< endl;
    }else{
        cout << "nie ma tyle miejsca w automacie, pozostale miejsce: " << pojemnosc - magazyn.size() <<endl;
        cout << "napoje nie zostaly dodane" << endl;
    }
};

void Automat::sprzedaj(string n, int ilosc, double c, double k){
    while (c * ilosc > k)
    {
        int d = 0;
        cout << "wplacona kwota jest za niska, dodaj wiecej pieniedzy" << endl;
        cin >> d;
        k += d;
    }

    vector <int> indeksy;

    for(int i=0; i < magazyn.size(); i++){
        if(magazyn[i].getNazwa() == n && magazyn[i].getCena() == c){ 
            indeksy.push_back(i);
        }
    }

    if(indeksy.size() >= ilosc){
        int ilosc_kopia = ilosc;
        for(int i = magazyn.size() - 1; i >= 0; i--) {
            if(find(indeksy.begin(), indeksy.end(), i) != indeksy.end()) {
                magazyn.erase(magazyn.begin() + i);
                ilosc_kopia-=1;
            }
            if(ilosc_kopia == 0){
                break;
            }
        }

        float koszt = c * ilosc;
        float reszta = k - koszt;

        if (reszta >= 0){
            cout << "zakupiono " << ilosc << " napoi " << n << ", reszta: " << reszta << " PLN:" << endl;

            vector<int> nominaly = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

            int resztaGrosze = static_cast<int>(reszta * 100 + 0.5);

            for (int nominal : nominaly){
                int liczbaNominalow = resztaGrosze / nominal;
                if (liczbaNominalow > 0){
                    if(nominal/100.0 >= 0.99){
                        cout << liczbaNominalow << " x " << nominal / 100.0 << " zl" << endl;
                    }else{
                        nominal = nominal*100;
                        cout << liczbaNominalow << " x " << nominal / 100.0 << " gr" << endl;
                    }
                }
                resztaGrosze -= liczbaNominalow * nominal;
            }
        }


    }else{
        cout << "w automacie nie ma danej ilosci napoi o podanej nazwie i cenie" << endl;
    }

};

vector <Napoj>& Automat::getMagazyn(){
    return magazyn;
};

Automat::Automat(int p){
    pojemnosc = p;
    magazyn.reserve(pojemnosc);
};