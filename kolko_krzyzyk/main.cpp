#include <iostream>
#include <vector>

using namespace std;
class Plansza {
    private:
        vector<int> plansza;
        bool koniec_gry;
        string zwyciezca;
    public:
        vector<int>& get_plansza();
        void show_plansza();
        void game_over_check();
        void place_sign(string sign, int field);
        bool get_koniec_gry();
        string get_zwyciezca();
        Plansza();
};

Plansza::Plansza(){
    plansza = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    koniec_gry = false;
    zwyciezca = "";
}

vector<int>& Plansza::get_plansza(){
    return plansza;
}

void Plansza::game_over_check(){
    int sign = 0;

    for (int j = 0; j < 7; j+=3){
        if(plansza[j]==plansza[j+1] && plansza[j+1]==plansza[j+2] && plansza[j+2]!=0){
            koniec_gry = true;
            sign = plansza[j];
        }
    } 

    for (int j = 0; j < 3; j++){
        if(plansza[j]==plansza[j+3] && plansza[j+3]==plansza[j+6] && plansza[j+6]!=0){
            koniec_gry = true;
            sign = plansza[j];
        }
    }

    if(plansza[0]==plansza[4] && plansza[4]==plansza[8] && plansza[8]!=0 || plansza[2]==plansza[4] && plansza[4]==plansza[6] && plansza[6]!=0){
        koniec_gry = true;
        sign = plansza[4];
    }

    bool allNonZero = true;
    for(int i=0; i<9; i++){
        if(plansza[i]==0){
            allNonZero = false;
            break;
        }
    }
    if(allNonZero == true){
            koniec_gry = true;
    }

    if(sign == 1){
        zwyciezca = "kółko";
    }else if(sign == 2){
        zwyciezca = "krzyżyk";
    }

}

bool Plansza::get_koniec_gry(){
    return koniec_gry;
};

string Plansza::get_zwyciezca(){
    return zwyciezca;
}

void Plansza::place_sign(string sign, int field){
    int sign_value = 0;
    if(sign == "o"){
        sign_value = 1;
    } else if(sign == "x"){
        sign_value = 2;
    }
    if(plansza[field-1] == 0){
        plansza[field-1] = sign_value;
    }
}

void Plansza::show_plansza(){
    int nl = 0;
    for (int i = 0; i < 9; i++){
        if(plansza[i] == 0){
            cout << i+1 << " ";
        }else if(plansza[i] == 1){
            cout << "O" << " ";
        }else if(plansza[i] == 2){
            cout << "X" << " ";
        }
        nl++;
        if (nl == 3){
            cout << endl;
            nl = 0;
        }
    }
};

int main(){
    Plansza plansza1 = Plansza();

    string sign = "x";

    string validValues[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    while (plansza1.get_koniec_gry() == false){
        string field = "0";
        while(true){
           
            plansza1.show_plansza();
            
            cout << "wpisz numer pola, w które chcesz wstawić znak: "<< sign << endl;
            cin >> field;
            int field_number = 0;
            bool field_changed = false;
            for(int i = 0; i < 9; i++){
                if(field == validValues[i]){
                    field_number = stoi(field);
                    if(plansza1.get_plansza()[field_number-1] == 0){
                        field_changed = true;
                    }
                    plansza1.place_sign(sign, field_number);
                    break;

                }
            }
            if(field_changed){
                break;
            }else{
                cout << "\033[31m --- wstaw znak w poprawne pole! --- \033[0m" << endl;
            }
        }
        if(sign == "x"){
            sign = "o";
        }else{
            sign = "x";
        }
        plansza1.game_over_check();
    }

    plansza1.show_plansza();
    if(plansza1.get_zwyciezca() != ""){
        cout << "Wygrywa: " << plansza1.get_zwyciezca() << ".";
    }else{
        cout << "Remis";
    }
    
    return 0;
}