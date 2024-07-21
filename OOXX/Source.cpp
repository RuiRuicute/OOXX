#include <iostream>
#include"bot.h"
using namespace std;

void show();
void ask();
void start();
void whoTurn();
void startAsk();
void determination();
int answer;
char whoFirst;
int who;
int row;
int column;
bool win = false;
char block[3][3] = {{' ',' ',' '},
			        {' ',' ',' '}, 
			        {' ',' ',' '}};
int turn=0;

int main() {
	start();
	cout << "1|2|3" <<endl;
	cout << "4|5|6" << endl;
	cout << "7|8|9" << endl;
	while (win!=true) {
		
		startAsk();
		ask();
		whoTurn();
		show();
		determination();
		turn++;
		if (turn == 9) {
			cout << "Tie";
			break;
		}
	}
}

void show() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << block[i][j]<<"|";
		}
		cout << block[i][2];
		cout << endl;
	};
}

void startAsk() {
	cout << "Please select a location" << endl;
}

void ask() {
	cin >> answer;
	switch (answer) {    
		case 1:
			row = 0;
			column = 0;
			break;
		case 2:
			row = 0;
			column = 1;
			break;
		case 3:
			row = 0;
			column = 2;
			break;
		case 4:
			row = 1;
			column = 0;
			break;
		case 5:
			row = 1;
			column = 1;
			break;
		case 6:
			row = 1;
			column = 2;
			break;
		case 7:
			row = 2;
			column = 0;
			break;
		case 8:
			row = 2;
			column = 1;
			break;
		case 9:
			row = 2;
			column = 2;
			break;
	}
	if (block[row][column] == ' ') {
		block[row][column] = who;
	}
	else {
		cout << "This grid has been selected, please select again.";
		ask();
	}
}

void start() {
	cout << "Please choose who goes first?  (O or X)";
	cin >> whoFirst;
	if (whoFirst == 'x' || whoFirst == 'X') {
		who = 'X';
	}
	else if (whoFirst == 'O' || whoFirst == 'o') {
		who = 'O';
	}
	else {
		start();
	}
}

void whoTurn() {
	if (who == 'O') {
		who = 'X';
	}
	else {
		who = 'O';
	}
}

void determination() {
	for (int i = 0; i < 3; i++) {
		if (block[i][0] == block[i][1] && block[i][1] == block[i][2]&& block[i][0]!=' ') {
			cout << block[i][0] << "  win";
			win = true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (block[0][i] == block[1][i] && block[1][i] == block[2][i] && block[0][i] != ' ') {
			cout << block[0][i] << "  win";
			win = true;
		}
	}
	if (block[0][0] == block[1][1] && block[1][1] == block[2][2] && block[0][0] != ' ') {
		cout << block[0][0] << "  win";
		win = true;
	}
	if (block[0][2] == block[1][1] && block[2][0] == block[1][1] && block[0][2] != ' ') {
		cout << block[0][2] << "  win";
		win = true;
	}
}