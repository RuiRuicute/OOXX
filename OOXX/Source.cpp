#include <iostream>
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

int main() {
	start();
	while (win!=true) {
		startAsk();
		ask();
		whoTurn();
		show();
		determination();
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
	cout << "請選擇位置" << endl;
}

void ask() {
	cin >> answer;
	switch (answer) {        //將程式改為row及column
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
		cout << "此格子已經被選定，請重新選擇";
		ask();
	}
}

void start() {
	cout << "請問誰間開始O或X";
	cin >> whoFirst;
	if (whoFirst == 'x' || whoFirst == 'X') {
		who = 'X';
	}
	else if (whoFirst == 'O' || whoFirst == 'o') {
		who = 'O';
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
		int j = 0;
		if (block[i][j] == block[i][j++] && block[i][j++] == block[i][j + 2]&& block[i][j]!=' ') {
			cout << block[i][j] << "獲勝";
			win = true;
		}
	}
	for (int i = 0; i < 3; i++) {
		int j = 0;
		if (block[j][i] == block[j+1][i] && block[j+1][i] == block[j+2][i] && block[j][i] != ' ') {
			cout << block[i][j] << "獲勝";
			win = true;
		}
	}
	if (block[0][0] == block[1][1] && block[1][1] == block[2][2] && block[0][0] != ' ') {
		cout << block[0][0] << "獲勝";
		win = true;
	}
	if (block[0][2] == block[1][1] && block[2][0] && block[0][2] != ' ') {
		cout << block[0][2] << "獲勝";
		win = true;
	}
}