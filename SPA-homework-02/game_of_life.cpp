#include "game_of_life.h"
#include <ctime>
//#include <stdlib.h>
#include <windows.h>
using namespace std;
bool game_of_life::random_value()
{
    

    int a = rand() % 4; // 25% , 0 1 2 3
    //cout << a; random gen debug, needs one more uncomment below
    if (a == 3) {
        return true;
    }
    else {
        return false;
    }
}

bool game_of_life::cell_taken(int i, int j)
{
    return _generation[i][j];
}

int game_of_life::check_2d(int i, int j)
{
    int n = 0;

        //top
        // i0 , j39
        if (i != 0) { //if not first row
            
            if (j != 0) { //top left
                if (cell_taken(i - 1, j - 1)) {
                    ++n;
                }
            };
            if (cell_taken(i - 1, j)) { //top mid
                ++n;
            };
            if (j != COLS - 1) {
                if (cell_taken(i - 1, j + 1)) { //top right
                    ++n;
                };
            }
        }

        //mid
        if (j != 0) {
            if (cell_taken(i, j - 1)) { //left
                ++n;
            };
        }
        if (j != COLS-1) {
            if (cell_taken(i, j + 1)) { //right
                ++n;
            };
        }

        //bot
        if (i != ROWS-1) {

            if (j != 0) {
                if (cell_taken(i + 1, j - 1)) { //left
                    ++n;
                };
            }
            if (cell_taken(i + 1, j)) { //mid
                ++n;
            };
            if (j != COLS-1) {
                if (cell_taken(i + 1, j + 1)) { //right
                    ++n;
                };
            }
        }

        return n;



        //  ---
        //  |x|
        //  ---
    
    /*
    1. A living organism in a cell survives in the next generation if the
    number of its neighbors is two or three. n == 2 , n == 3
    2. A living organism in a cell dies in the next generation if 
    the number of its neighbors is less than (n >= 2 && n <= 3))
    two (due to loneliness) or greater than three (due to overcrowding).
    3. A new organism is born in an empty cell if there are living 
    organisms in exactly three of its neighboring cells.*/

}


game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            _generation[i][j] = random_value();
            _next_generation[i][j] = _generation[i][j];
        }
        //cout << endl; part of random generator debug
    }
}

void game_of_life::next_generation()
{

    //next_gen_init();
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int n = check_2d(i, j);
            if (cell_taken(i, j)) { //is alive
                if ((n >= 2 && n <= 3)) {
                //cout << '*';
                    _next_generation[i][j] = true;
                }
                else {
                    _next_generation[i][j] = false;
                }
            }
            else { //is dead
                if (n == 3) {
                    //cout << '*';
                    _next_generation[i][j] = true;
                }
                else {
                    //cout << '-';
                    _next_generation[i][j] = false;
                }
            }
            //_generation[i][j] = _next_generation[i][j]; cell_taken issue
        }
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
          _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw() {
    this->draw(15,8); //white , grey
}

void game_of_life::draw(int c1, int c2)
{
    //cout << string(100, '\n'); no
    //system("cls"); //clear console, flicker
    //cout << "\033[H\033[J" << endl; //clear console
    //cout << "\033c" << endl; //clear console

    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (_next_generation[i][j] == true) {
                SetConsoleTextAttribute(console_color, c1); //30 , 15
                cout << '*';
            }
            else {
                SetConsoleTextAttribute(console_color, c2); //0 , 12
                cout << '-';
            }
        }
        cout << endl;
        SetConsoleTextAttribute(console_color, 7); //default
    }
    
}