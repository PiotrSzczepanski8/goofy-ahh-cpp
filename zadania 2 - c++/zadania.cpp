#include <iostream>
#include <cmath>


void zadanie1(){
    for(int i=1; i<=10; i++){
        std::cout<<i<<std::endl;
    }
}

void zadanie2(){
    for(int i=10; i>=1; i--){
        std::cout<<i<<std::endl;
    }
}
void zadanie3(){
    int a = 0;
    for(int i=1; i<=10; i++){
        a += i;
    }
    std::cout << a << std::endl;
}

void zadanie4(){
    for(int i=2; i<=20; i+=2){
        std::cout << i << std::endl;
    }
}
void zadanie5(){
    int suma = 0;
    int pierwszy_element = 5;
    for (int i = 0; i < 100; i++){
        suma += pierwszy_element + i * 10;
    }
    std::cout << suma << std::endl;
}
void zadanie6(){
    int cegly = 0;
    for (int i = 1; i <= 10; i++){
        cegly += i * i;
    }
    std::cout << cegly << std::endl;
}
void ciag(int n, int x, int y){
    int a = 1;
    for (int i=x; a<=n; i+=y){
        std::cout << i << std::endl;
        a++;
    }
}
void suma(){
    int a = 0;
    int b = 0;
    do {
        std::cin >> a >> b;
        std::cout << "Suma: " << a + b << std::endl;
    } while (a + b != 0);
}
int silnia(int n){
    if (n == 0 || n == 1) return 1;
    return n * silnia(n - 1);
}
void ciag_kwadratow(int n, int pierwsza){
    int liczba = pierwsza;
    for (int i = 1; i <= n; i++){
        std::cout << liczba << std::endl;
        liczba *= liczba;
    }
}
void suma_srednia(){
    int suma = 0;
    for (int i = 0; i < 10; i++){
        suma += rand() % 100 + 50;
    }
    std::cout << "Suma: " << suma << std::endl;
    std::cout << "Średnia: " << suma / 10.0 << std::endl;
}

void suma_pieciu(){
    int suma = 0;
    for(int i = 1; i <= 5; i++){
        int liczba;
        std::cin >> liczba;
        suma += liczba;
    }
    std::cout << suma << std::endl;
}
int potega(int l, int p){
    int wynik = l;
    for(int i = 1; i < p; i++){
        wynik *= l;
    }
    return wynik;
}
void kwadrat(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
}
void prostokat(int a, int b){
    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
}
void piramida(int h){
    for(int i = 1; i <= h; i++){
        for(int j = i; j < h; j++){
            std::cout << " ";
        }
        for(int k = 0; k < (2 * i - 1); k++){
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
}

int main(){
    std::cout << "1.------------------" << std::endl;
    zadanie1();

    std::cout << "2.------------------" << std::endl;
    zadanie2();

    std::cout << "3.------------------" << std::endl;
    zadanie3();

    std::cout << "4.------------------" << std::endl;
    zadanie4();

    std::cout << "5.------------------" << std::endl;
    zadanie5();

    std::cout << "6.------------------" << std::endl;
    zadanie6();

    std::cout << "7.------------------" << std::endl;
    ciag(10, 2, 3);

    std::cout << "8.------------------" << std::endl;
    // suma();

    std::cout << "9.------------------" << std::endl;
    // int n;
    // std::cin >> n;
    // std::cout << silnia(n) << std::endl;

    std::cout << "10.------------------" << std::endl;
    // int pierwsza;
    // std::cin >> pierwsza;
    // ciag_kwadratow(5, pierwsza);

    std::cout << "11.------------------" << std::endl;
    // suma_srednia();

    std::cout << "12.------------------" << std::endl;
    // suma_pieciu();

    std::cout << "13.------------------"<< std::endl;
    std::cout << potega(2, 3) << std::endl;

    std::cout << "14.------------------" << std::endl;
    kwadrat(4);

    std::cout << "15.------------------" << std::endl;
    prostokat(5, 3);

    std::cout<<"16.------------------" << std::endl;
    
    piramida(10);

    return 0;
}