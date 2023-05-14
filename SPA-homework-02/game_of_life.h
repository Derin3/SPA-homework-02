#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLS = 40;
	static const unsigned int ROWS = 20;
	bool _generation[ROWS][COLS];
	bool _next_generation[ROWS][COLS];
	bool random_value();
	bool cell_taken(int i, int j);
	int check_2d(int i, int j);
public:
	game_of_life();
	void next_generation();
	void draw();
	void draw(int c1, int c2);
};

#endif
