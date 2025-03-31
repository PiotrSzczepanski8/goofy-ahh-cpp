#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Picture{
    private:
        vector<string> stages;
        int current_stage;
        friend class Word;
    public:
        int get_current_stage();
        void show_current_stage();
        Picture();
};

Picture::Picture(){
    current_stage = 0;
    stages = {" ", "\n \n \n \n \n \n▔▔▔▔▔▔▔▔", "\n  |	    \n  |         \n  |           \n  |           \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	    \n  |         \n  |           \n  |           \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	   |\n  |         \n  |           \n  |           \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	   |\n  |        O\n  |           \n  |           \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	   |\n  |        O\n  |        |  \n  |           \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	   |\n  |        O\n  |       /|\\ \n  |           \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	   |\n  |        O\n  |       /|\\ \n  |         \\ \n  |\n▔▔▔▔▔▔▔▔", "   ________\n  |	   |\n  |        O\n  |       /|\\ \n  |       / \\ \n  |\n▔▔▔▔▔▔▔▔"};
};

void Picture::show_current_stage(){
    cout << stages[current_stage]<< endl;
}

int Picture::get_current_stage(){
    return current_stage;
}

class Word{
    private:
        string word_structure;
        vector<char> failed_letters;
        string word;
    public:
        Word();
        Word(string word);
        vector<char>& get_failed_letters();
        void place_letter(string letter, Picture& picture);
        void show_word();
        string get_word();
        string get_word_structure();
        void show_word_structure();
};

Word::Word(){
    word = "Nierodka";
    word_structure = "";
    for (int i=0; i<word.length(); i++){
        word_structure += "_";
    }
};

Word::Word(string w){
    word = w;
    word_structure = "";
    for (int i=0; i<w.length(); i++){
        word_structure += "_";
    }
}

vector<char>& Word::get_failed_letters(){
    return failed_letters;
};

string Word::get_word(){
    return word;
}

string Word::get_word_structure(){
    return word_structure;
}

void Word::show_word_structure(){
    for (int i=0; i<word.length(); i++){
        cout << word_structure[i] << " ";
    }
    cout << endl;
}

void Word::place_letter(string letter, Picture& picture){
    bool not_in_word = true;
    bool not_failed_yet = true;
    for(int i=0; i<word.size(); i++){
        if(tolower(word[i]) == tolower(letter[0])){
            not_in_word = false;
            letter = word[i];
            word_structure = word_structure.replace(i, 1, letter);
        }
    }
    for(int i=0; i<failed_letters.size(); i++){
        if(failed_letters[i] == letter[0]){
            not_failed_yet = false;
        }
    }
    if(not_in_word){
        picture.current_stage++;
        if(not_failed_yet){
            failed_letters.push_back(letter[0]);
        }
    }
}

int get_random_int(int n) {
    int random_int = rand() % n;
    return random_int;
}


int main(){
    srand(time(0));

    vector <string> slowa = {"Anakonda", "Bambusy", "Kinematografia", "Nierodka", "Dzicz"}; 
    int index = get_random_int(slowa.size());
    Word slowo1 = Word(slowa[index]);
    Picture obrazek1 = Picture();
    slowo1.show_word_structure();
    while(true){
        if(obrazek1.get_current_stage() == 9){
            cout << "Przegrales" << endl;
            break;
        }
        if(slowo1.get_word() == slowo1.get_word_structure()){
            cout << "wygrales" << endl;
            break;
        }
        string l = "";
        cout << "Podaj litere \nZnaki, ktore nie sa literami beda brane pod uwage jako bledne litery" << endl;
        if (slowo1.get_failed_letters().size() > 0){
            cout << "Wczesniej podane zle znaki: ";
            for(int i=0; i < slowo1.get_failed_letters().size(); i++){
                char failed_letter = toupper(slowo1.get_failed_letters()[i]);
                cout << failed_letter << ", ";
            }
            cout << endl;
        }
        
        cin >> l;
        if(l.size() == 1){
            slowo1.place_letter(l, obrazek1);
            obrazek1.show_current_stage();
            slowo1.show_word_structure();
        } else{
            cout << "Podaj poprawny znak" << endl; 
        }
    }
    return 0;
}