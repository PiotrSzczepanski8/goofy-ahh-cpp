#include "napoj.h"
#include "automat.h"
#include <vector>

int main(){

    Automat automat1(250);
    automat1.napelnij("Pepsi", 50, 3.90);
    automat1.napelnij("Cola", 50, 3.45);
    automat1.napelnij("Fanta", 50, 4.20);
    // cout << automat1.getMagazyn().size() << endl;
    while (true)
    {    
        int decyzja = 0;
        string nazwa = "";
        int ilosc = 0;
        double kwota = 0.00;
        double koszt = 0.00;

        cout << "Co chcesz zrobić? \n 1 - sprawdz magazyn \n 2 - kup napoje \n 3 - napelnij automat \n wpisz cokolwiek innego żeby zakończyć program" << endl;

        cin >> decyzja;
        
        if(decyzja == 1){
            // automat1.getMagazyn();

            vector<string> nazwy;
            vector<double> ceny;
            vector<int> ilosci;

            for(int i = 0; i < automat1.getMagazyn().size(); i++){
                string nazwa = automat1.getMagazyn()[i].getNazwa();
                double cena = automat1.getMagazyn()[i].getCena();

                bool znaleziono = false;

                for(int j = 0; j < nazwy.size(); j++){
                    if(nazwy[j] == nazwa && ceny[j] == cena){
                        ilosci[j]++;
                        znaleziono = true;
                        break;
                    }
                }

                if(!znaleziono){
                    nazwy.push_back(nazwa);
                    ceny.push_back(cena);
                    ilosci.push_back(1);
                }
            }
            for(int i = 0; i < nazwy.size(); i++){
            cout << nazwy[i]
                 << ", cena: " << ceny[i]
                 << ", ilość: " << ilosci[i] << endl;
            }

        }else if(decyzja == 2){
            //mogą być dwa napoje o takiej samej nazwie ale innej cenie
            cout << "podaj nazwe, ilosc sztuk, cene za sztukę i wpłaconą kwotę (odzielone spacjami)" << endl;
            cin >> nazwa >> ilosc >> koszt >> kwota;
            automat1.sprzedaj(nazwa, ilosc, koszt, kwota);

        }else if(decyzja == 3){
            cout << "podaj nazwe, ilosc sztuk i cene za sztukę dodanych napoi (oddzielone spacjami)" << endl;
            double cena;
            cin >> nazwa >> ilosc >> cena;
            automat1.napelnij(nazwa, ilosc, cena);
            
        }else break;
    };
    return 0;
};