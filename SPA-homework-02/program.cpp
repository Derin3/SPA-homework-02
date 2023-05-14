#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "game_of_life.h"
using namespace std;
using namespace std::chrono;

int main() {
	game_of_life the_game;
	
	bool again;
	
	int uinput = 404;
	string uinput3;
	int interval = 404;
	bool automode = false;
	bool continuegame = true;
	string uinput2;
	string colorscheme;
	int cycles = 0;
	int c1 = 0;
	int c2 = 0;
	steady_clock::time_point start;
	steady_clock::time_point end;
	
	cout << "--GAME OF LIFE--" << endl;
	cout << "Select Mode "
		<< "(0 - Manual | 1 - Auto): ";
	cin >> automode;
	cin.ignore();
	cout << "Select Color scheme "
		<< "(empty - Default | 1 - Red): ";
	getline(cin, colorscheme);
	if (colorscheme == "") {
		c1 = 15;
		c2 = 8;
	}
	else {
		c1 = 15;
		c2 = 12;
	}
	if (automode) {
		cout << "Enter automatic refresh interval in milliseconds (empty for default): ";
		getline(cin, uinput2);
		if (uinput2 == "") {
			interval = 250;
		}
		else {
			interval = stoi(uinput2);
		}
		cout << "Enter maximum number of generations to simulate (empty for default): ";
		getline(cin,uinput3);
		if (uinput3 == "") {
			uinput = 20;
		}
		else {
			uinput = stoi(uinput3);
		}


	}
	start = high_resolution_clock::now();
	end = start;
	while ((cycles < uinput) && automode || !automode) {
		if (duration_cast<milliseconds> (end - start).count() > interval || !automode && continuegame) {
			system("cls"); //clear console , flicker
			the_game.draw(c1, c2);
			the_game.next_generation();
			cout << endl << endl << "Generation: "<< cycles + 1 << endl;
			cycles++;
			if (automode == true) {
				start = high_resolution_clock::now();
			}
			else {
				cout << "Again (1/0): ";
				cin >> continuegame;
				cin.ignore();
				if (!continuegame) {
					break;
				}
			}
		}
		else {
			if (automode == true) {
				end = high_resolution_clock::now();
			}
		}
	};
	cout << endl << endl << "End of program" << endl;
	if (automode == true) {
		cout << "Execution interval: " << interval << " ms" << endl
			 << "Maximum generation count: " << cycles << endl << endl;
	}
	return 0;
}