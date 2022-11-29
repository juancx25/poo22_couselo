#ifndef TATETI_H_INCLUDED
#define TATETI_H_INCLUDED
#include <cstring>
#include <conio.h>

#define ROWS 3
#define COLS 3

class board{

    private:
        char** squares;
        int rows;
        int cols;
        std::pair<int,int> selected;

    public:
        board(int rows, int cols);
        ~board();

        char square(int row,int col);
        int selected_row();
        int selected_col();
        int getRows();
        int getCols();

        void set(int row,int col,char c);

        void draw();
        void navigate(int current_player);

};

board::board(int rows=ROWS,int cols=COLS){
    this->selected.first = 0;
    this->selected.second = 0;

    this->rows = rows;
    this->cols = cols;

    char** aux = new char*[rows];
    for (int i=0;i<rows;i++){
        aux[i] = new char[cols];
        memset(aux[i],0x20,cols);
    }
    this->squares = aux;
}

board::~board(){
    for (int i = 0; i < rows; ++i){
        delete [] squares[i];
    }
    delete [] squares;
}

char board::square(int row,int col){ return squares[row][col]; }
int board::getRows(){ return rows; }
int board::getCols(){ return cols; }
int board::selected_row(){ return selected.first; }
int board::selected_col(){ return selected.second; }


void board::set(int row,int col,char c){ squares[row][col] = c; }

void board::draw(){
    for (int i=0;i<rows;i++){
        std::cout << "-------" << std::endl;
        for (int j=0;j<cols;j++){
            std::cout << "|";
            if ((selected.first == i) && (selected.second == j)) std::cout << (char)177;
            else std::cout << squares[i][j];
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-------" << std::endl;
}

void board::navigate(int current_player){
    char key = 0;
    bool valid_selection = false;
    while (!valid_selection){
        system("cls");
        std::cout << "Player: " << current_player << std::endl;
        draw();
        key = _getch();
        switch (key){
            case ('w'):
                if (selected.first>0){
                    selected.first--;
                }
                else selected.first = rows-1;
                break;

            case ('s'):
                if (selected.first<rows-1){
                    selected.first++;
                }
                else selected.first = 0;
                break;

            case ('a'):
                if (selected.second>0){
                    selected.second--;
                }
                else selected.second = cols-1;
                break;

            case ('d'):
                if (selected.second<cols-1){
                    selected.second++;
                }
                else selected.second = 0;
                break;
            case (13):
                if (square(selected.first,selected.second) == 0x20)
                    valid_selection = true;
                break;
        }


    }
}


class game{

    private:
        int player_total;
        int current_player;
        board _board;
        bool over;

    public:
        game(int player_total);
        int start();
        void turn_action();
        int is_over();
};

game::game(int player_total){
    this->player_total = player_total;
    current_player = 1;
    board* aux = new board();
    _board = *aux;
    over = false;
}

int game::start(){
    int winner;
    while (!over){
        _board.navigate(current_player);
        turn_action();
        winner = is_over();
        if (!over){
            if (current_player == 1) current_player = 2;
            else current_player = 1;
        }
    }
    if (winner){
        std::cout << "Winner: Player " << current_player << std::endl;
    }
    else std::cout << "Game tied!" << std::endl;
    return 0;
}

void game::turn_action(){
    if (current_player == 1) _board.set(_board.selected_row(),_board.selected_col(),'X');
    if (current_player == 2) _board.set(_board.selected_row(),_board.selected_col(),'O');

}

int game::is_over(){
    int winner = 0;
    int rows = _board.getRows();
    char symbol;
    if (current_player == 1) symbol = 'X';
    else if (current_player == 2) symbol = 'O';

    int i = 0;
    int full = 0;int diag1 = 0;int diag2 = 0;
    while ((!over) && (i<rows)){
        int j = 0;
        int line=0;int column = 0;
        if (_board.square(i,i) == symbol) diag1++;
        if (_board.square(rows-1-i,i) == symbol) diag2++;
        while ((!over) && (j<rows)){
            if (_board.square(i,j) == symbol) line++;
            if (_board.square(j,i) == symbol) column++;
            if (_board.square(i,j) != 0x20) full++;
            j++;
        }
        if ((line==rows) || (column==rows) || (diag1==rows) || (diag2==rows) || (full == rows*rows)){
            over = true;
            if (full == rows*rows) winner = 0;
            else winner = current_player;
        }
        else i++;
    }
    return winner;
}

#endif // TATETI_H_INCLUDED
