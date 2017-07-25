// Cows And Bulls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

short int input;
short int d1; short int d2; short int d3; short int d4;
short int i;
short int g1; short int g2; short int g3; short int g4;
short int cows;  short int bulls;

int playerInput() {
	while (1) {
		input = _getch();
		switch (input) {
		case 0x30:
			cout << "0";
			return 0;
		case 0x31:
			cout << "1";
			return 1;
		case 0x32:
			cout << "2";
			return 2;
		case 0x33:
			cout << "3";
			return 3;
		case 0x34:
			cout << "4";
			return 4;
		case 0x35:
			cout << "5";
			return 5;
		case 0x36:
			cout << "6";
			return 6;
		case 0x37:
			cout << "7";
			return 7;
		case 0x38:
			cout << "8";
			return 8;
		case 0x39:
			cout << "9";
			return 9;
		}
	}
}

int main() {
	srand(time(NULL));

	while (1) {
		cout << "I have chosen a 4 digit number.\nYou have 12 guesses.\n\nRules:\nCow means there is a correct number in the wrong spot.\nBull means there is a correct number in the right spot.\nNo number starts with 0.\nNo digit repeats.\n" << endl;

		i = 1;

		d1 = ((rand() % (9)) + 1);

		d2 = (rand() % (10));
		while (d2 == d1) { d2 = (rand() % (10)); }

		d3 = (rand() % (10));
		while (d3 == d1 || d3 == d2) { d3 = (rand() % (10)); }

		d4 = (rand() % (10));
		while (d4 == d1 || d4 == d2 || d4 == d3) { d4 = (rand() % (10)); }

		while (i <= 12) {
			cows = 0;
			bulls = 0;
			cout << "---Round Number " << i << "/12---" << endl;
			cout << "Enter Your Guess: ";
			g1 = playerInput();
			g2 = playerInput();
			g3 = playerInput();
			g4 = playerInput();
			cout << endl;
			if (g1 == d2 || g1 == d3 || g1 == d4) { cows++; }
			if (g1 == d1) { bulls++; }

			if (g2 == d1 || g2 == d3 || g2 == d4) { cows++; }
			if (g2 == d2) { bulls++; }

			if (g3 == d1 || g3 == d2 || g3 == d4) { cows++; }
			if (g3 == d3) { bulls++; }

			if (g4 == d1 || g4 == d2 || g4 == d3) { cows++; }
			if (g4 == d4) { bulls++; }

			if (bulls == 4) { cout << "Your guess " << g1 << g2 << g3 << g4 << " is correct, you win!" << endl; i = 25; break; }
			else {
				cout << "Your guess " << g1 << g2 << g3 << g4 << " has:" << endl;
				cout << "Bulls: " << bulls << "\nCows: " << cows << endl << endl;
				i++;
			}
		}
		if (bulls != 4) { cout << "Sorry, you are out of turns, the correct answer is " << d1 << d2 << d3 << d4 << "." << endl; }
		cout << "\n(Press Enter To Play Again)\n" << endl;
		_getch();
		system("CLS");
	}
}

