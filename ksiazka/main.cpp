#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Entry{
    string name;
    string phone;
};

class AddressBook{
private:
    vector<Entry> entries;
public:
    void addEntry(const Entry& e){
        entries.push_back(e);
    }

    void deleteEntry(int index){
        if (index < 0 || index >= static_cast<int>(entries.size())){
            cout << "nieprawidlowy index" << endl;
            return;
        }
        entries.erase(entries.begin() + index);
        cout << "usunieto pozycje." << endl;
    }

    void showEntry(int index) const{
        if (index < 0 || index >= static_cast<int>(entries.size())){
            cout << "nieprawidlowy index" << endl;
            return;
        }
        cout << "nazwa: " << entries[index].name << "\n" << "telefon: " << entries[index].phone << "\n";
    }

    void saveToFile(const string& filename) const{
        ofstream ofs(filename);
        for (const auto& e : entries){
            ofs << e.name << '\n' << e.phone << '\n';
        }
        cout << "zapisano pozycje do: " << filename << endl;
    }

    void loadFromFile(const string& filename){
        ifstream ifs(filename);
        entries.clear();
        string name, phone;
        while (getline(ifs, name) && getline(ifs, phone)){
            entries.push_back({name, phone});
        }
        cout << "odczytano pozycje z: " << filename << endl;
    }
};

void printMenu(){
    cout << "\033[95m1.\033[0m Dodaj pozycje\n" << "\033[95m2.\033[0m Usun pozycje\n" << "\033[95m3.\033[0m Pokaz pozycje\n" << "\033[95m4.\033[0m Zapisz do pliku\n" << "\033[95m5.\033[0m Odczytaj z pliku\n" << "\033[95m6.\033[0m wyjdz\n" << "wybierz opcje: ";
}

int main(){
    AddressBook book;
    bool running = true;
    while (running){
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice){
            case 1:{
                Entry e;
                cout << "nazwa: "; getline(cin, e.name);
                cout << "telefon: "; getline(cin, e.phone);
                book.addEntry(e);
                break;
            }
            case 2:{
                int idx;
                cout << "podaj index (zaczynajac od 0), zeby usunac pozycje: "; cin >> idx;
                cin.ignore();
                book.deleteEntry(idx);
                break;
            }
            case 3:{
                int idx;
                cout << "podaj index (zaczynajac od 0), zeby zobaczyc pozycje: "; cin >> idx;
                cin.ignore();
                book.showEntry(idx);
                break;
            }
            case 4:{
                string filename;
                cout << "podaj nazwa pliku do zapisania: "; getline(cin, filename);
                book.saveToFile(filename);
                break;
            }
            case 5:{
                string filename;
                cout << "podaj nazwe pliku do odczytania: "; getline(cin, filename);
                book.loadFromFile(filename);
                break;
            }
            case 6:
                running = false;
                break;
            default:
                cout << "nieprawidlowa opcja" << endl;
        }
    }
    return 0;
}