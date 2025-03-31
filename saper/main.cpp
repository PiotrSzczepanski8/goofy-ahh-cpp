#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string> 
using namespace std;

class Field{
    public:
        string type;
        bool hidden;
        bool marked;
        bool checked;
        Field();
        void changeType();
};

class Board{
    public:
        int rows;
        int columns;
        Field** board;
        int mines;
        Board(int rows, int columns);
        void showBoard();
        int chooseField(int w);
        void showEmptyFields(int x, int y);
        int checkUncovered();
};

Field::Field(){
    type = " ";
    hidden = true;
    marked = false;
    checked = false;
};

Board::Board(int r, int c){
    rows = r;
    columns = c;
    board = new Field*[rows]; // tablica wskaźników, która ma rows elementów
    for (int i = 0; i < rows; ++i){
        board[i] = new Field[columns];
        
    }
    int losowyx;
    int losowyy;
    srand(time(NULL));
    mines = 0;
    switch(rows){
        case 8:
            mines = 10;
            break;
        case 16:
            mines = 40;
            break;
    }
    if(mines == 0){
        mines = (rows*(rows/5));
    }
    for(int w = 0; w<mines; w++){
        losowyx = rand() % r;
        losowyy = rand() % c;
        board[losowyx][losowyy].type = "x";
    }
    int XD = 0;
    for(int i = 0;i<rows;++i){
        for(int j = 0;j<rows;++j){
            XD = 0;
            if(board[i][j].type == " "){
                if(i == 0){
                    if(j == 0){
                        if(board[i+1][j].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j+1].type == "x"){
                            XD++;
                        }if(board[i][j+1].type == "x"){
                            XD++;
                        }
                    } else if(j+1 == columns){
                       if(board[i+1][j].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j-1].type == "x"){
                            XD++;
                        }if(board[i][j-1].type == "x"){
                            XD++;
                        } 
                    } else{
                        if(board[i+1][j].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j+1].type == "x"){
                            XD++;
                        }if(board[i][j+1].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j-1].type == "x"){
                            XD++;
                        }if(board[i][j-1].type == "x"){
                            XD++;
                        } 
                    }
                }else if(i+1 == rows){
                    if(j == 0){
                        if(board[i-1][j].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j+1].type == "x"){
                            XD++;
                        }if(board[i][j+1].type == "x"){
                            XD++;
                        }
                    } else if(j+1 == columns){
                       if(board[i-1][j].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j-1].type == "x"){
                            XD++;
                        }if(board[i][j-1].type == "x"){
                            XD++;
                        } 
                    } else{
                        if(board[i-1][j].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j+1].type == "x"){
                            XD++;
                        }if(board[i][j+1].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j-1].type == "x"){
                            XD++;
                        }if(board[i][j-1].type == "x"){
                            XD++;
                        } 
                    }
                } else{
                    if(j == 0){
                        if(board[i-1][j].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j+1].type == "x"){
                            XD++;
                        }if(board[i][j+1].type == "x"){
                            XD++;
                        }if(board[i+1][j].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j+1].type == "x"){
                            XD++;
                        }
                    } else if(j+1 == columns){
                       if(board[i-1][j].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j-1].type == "x"){
                            XD++;
                        }if(board[i][j-1].type == "x"){
                            XD++;
                        } 
                        if(board[i+1][j].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j-1].type == "x"){
                            XD++;
                        }
                    } else{
                        if(board[i-1][j].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j+1].type == "x"){
                            XD++;
                        }if(board[i][j+1].type == "x"){
                            XD++;
                        }
                        if(board[i-1][j-1].type == "x"){
                            XD++;
                        }if(board[i][j-1].type == "x"){
                            XD++;
                        } if(board[i+1][j-1].type == "x"){
                            XD++;
                        }if(board[i+1][j].type == "x"){
                            XD++;
                        }
                        if(board[i+1][j+1].type == "x"){
                            XD++;
                        }
                    }

                }
                board[i][j].type = to_string(XD);
            }
        }
    }
}

int Board::checkUncovered(){
    int uncovered = 0;
    for(int i; i<rows; i++){
        for(int j; j<columns; j++){
            if(!this->board[i][j].hidden){
                uncovered++;
            }
        }
    }
    return uncovered;
}

void Board::showEmptyFields(int x, int y){
    // if (this->board[x][y].type != " ") return;

    this->board[x][y].checked = true;
    this->board[x][y].hidden = false;

    int changes;
    do {
        changes = 0;
        for (int i = 0; i < this->columns; i++){
            for (int j = 0; j < this->rows; j++){
                if (this->board[i][j].checked && this->board[i][j].type == "0"){
                    for (int dx = -1; dx <= 1; dx++){
                        for (int dy = -1; dy <= 1; dy++){
                            int ni = i + dx;
                            int nj = j + dy;
                            if (ni >= 0 && ni < this->columns && nj >= 0 && nj < this->rows){
                                if (this->board[ni][nj].hidden && this->board[ni][nj].type != "x"){
                                    this->board[ni][nj].hidden = false;
                                    this->board[ni][nj].checked = true;
                                    changes++;
                                }
                            }
                        }
                    }
                }
            }
        }
    } while (changes != 0);
}

void Board::showBoard(){
    char alfabet[25]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','X','Y','Z'};
    cout << "\n\n";
    cout << "   \033[94m";
    for(int j = 0;j<rows;++j){
        cout << alfabet[j] << " ";
    }
    cout << "\033[0m" << endl;
    for(int i = 0;i<rows;++i){
        if(to_string(i+1).length() == 1){
            cout << " \033[94m" << i+1 << "\033[0m ";
        }else{
            cout << "\033[94m" << i+1 << "\033[0m "; 
        }
        for(int j = 0;j<rows;++j){
            if(board[i][j].marked == true){
                cout << "# ";
            }
            else if(board[i][j].hidden == true){
                    cout << "■ ";
            }else{
                if(board[i][j].type == "0"){
                    cout << "□ ";  
                } else if(board[i][j].type == "x"){
                    cout << "X ";
                } else{
                    cout << board[i][j].type << " ";
                }  
            }
        }
        cout << endl;
    }
}

int Board::chooseField(int w){
    int x = 0;
    int y = 0;
    char alfabet[25]{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','X','Y','Z'}; 
    char l;
    if(w == 1){
        cout << "Podaj numer pola" << endl;
        cin >> x;
        x = x-1;
        cout << "Podaj litere pola" << endl;
        cin >> l;
        l = toupper(l);
        int size = sizeof(alfabet);
        for(int w = 0;w<size;w++){
            if(alfabet[w] == l){
                y = w;
                break;
            }
        }
        if(this->board[x][y].marked == true){
            return 0;
        }else{
            this->board[x][y].hidden = false;
            this->board[x][y].checked = true;  
            if(this->board[x][y].type == "0" || this->board[x][y].type == " "){
                this->showEmptyFields(x, y);
            }
        }
        

            if(this->board[x][y].type == "x"){
                return 1;
            } else{
                return 0;
            }
        } else{
        cout << "Podaj numer pola" << endl;
        cin >> x;
        x=x-1;
        cout << "Podaj litere pola" << endl;
        cin >> l;
        l = toupper(l);
        int size = sizeof(alfabet);
        for(int w = 0;w<size;w++){
            if(alfabet[w] == l){
                y = w;
                break;
            }
        }
        if(this->board[x][y].marked == true){
            this->board[x][y].marked = false;
            if(this->board[x][y].type == "x"){
                return -1;
            } else{
                return 0;
            }
        }
        else if(this->board[x][y].type == "x"){
            this->board[x][y].marked = true;
            return 1;
        } 
        else{
            this->board[x][y].marked = true;
            return 0;
        }
    }
    
}

int main(){
    Board plansza1(8, 8);
    bool przegrana = false;
    int wygrana = plansza1.mines;
    cout << wygrana << endl;
    int potencjal = 0;
    int wybor = 0;
    while(!przegrana && wygrana != potencjal){
        plansza1.showBoard();
        cout << "\nWybierz akcję:\n1 - Sprawdź pole \n2 - Oznacz pole flagą" << endl;
        cin >> wybor;
        if(wybor == 1){
            przegrana = plansza1.chooseField(wybor);
        } else{
            plansza1.chooseField(wybor);
            potencjal = plansza1.checkUncovered();
        }
        if(wygrana == potencjal){
            cout << "wygrales" << endl;
        }
        if(przegrana){
            cout << "przegrales" << endl;
        }
        
    }
    plansza1.showBoard();
    return  0;
}