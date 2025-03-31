#include "napoj.h"

string Napoj::getNazwa(){
    return nazwa;
}
double Napoj::getCena(){
    return cena;
}
Napoj::Napoj(string n, double c){
    nazwa = n;
    cena = c;
};