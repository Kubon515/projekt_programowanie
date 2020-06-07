/*! \file main.cpp
*
* \author Jakub Rosinski, Micha³ Skowroñski . Oskar Smektala
* \date 2020.05.18
* \version 1.00.00
*/

#include <iostream>
#include "windows.h"
#include "time.h"

using namespace std;

char map[20][20] = {

"###################",
"#                 #",
"#  @ @ @ @ @ @ @  #",
"#   @ @ @ @ @ @   #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#        W        #",
"###################"

};

bool endGame = false;
bool loose = false;
int gameSpeed = 1000;
int randomNum;
int maxHealth = 100;
int yourHealth = maxHealth;
int maxLives = 3;
int lives = maxLives;
int points = 0;
HANDLE hConsole;
COORD leftTopCursorPos = { 0, 0 };

void clearConsole()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
	DWORD size = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD charsWrited;
	COORD home = { 0, 0 };
	if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', size, home, &charsWrited)) return;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
	if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, size, home, &charsWrited)) return;
	SetConsoleCursorPosition(hConsole, home);
}

void clearBullets()
{
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {
			if (map[y][x] == '*') map[y][x] = ' ';
		}
	}
}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);

	while (endGame == false) {

		srand(time(0));
		SetConsoleCursorPosition(hConsole, leftTopCursorPos);

		for (int y = 0; y < 20; y++ ) {
			cout << map[y] << endl;
		}

		cout << "Health " << yourHealth << "/" << maxHealth << endl;
		cout << "Lives " << lives << "/" << maxLives << endl;
		cout << "Points " << points << endl;

		for (int y = 0; y < 20; y++ ) {
			for (int x = 0; x < 20; x++) {

				switch (map[y][x]) {
					
					case 'W':

						if (GetAsyncKeyState(VK_LEFT) & 0x8000) {

							int newX = x - 1;
						    if (map[y][newX] == ' ') {
								map[y][x] = ' ';
								x--;
								map[y][newX] = 'W';
							}

						}
						if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {

							int newX = x + 1;
							if (map[y][newX] == ' ') {
								map[y][x] = ' ';
								x++;
								map[y][newX] = 'W';
							}
						}
						if (GetAsyncKeyState(VK_SPACE) & 0x8000) {

							y--;
							map[y][x] = '^';

						}
						if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {

							endGame = true;

						}
						break;

				    case '^':

						map[y][x] = ' ';
						y--;
						if (map[y][x] != '#' && map[y][x] != '@') {
							map[y][x] = '^';
						}
						else if (map[y][x] == '@') {
							map[y][x] = ' ';
							points++;
						}

						break;

					case '@':

						randomNum = rand() % 50 + 1;

						if (randomNum == 1) {

							y++;
							map[y][x] = '*';
						}
						break;

					case '*':

						map[y][x] = ' ';
						y++;
						if (map[y][x] != '#' && map[y][x] != 'W') {
							map[y][x] = '*';
						}
						else if (map[y][x] == 'W') {
							yourHealth -= 20;
						}
						break;

				}
			}
			if (yourHealth <= 0) {
				yourHealth = 0;
				if (lives > 0) {
					lives--;
					yourHealth = maxHealth;
					clearConsole();
					clearBullets();
					cout << endl << "You were killed" << endl;
					Sleep(1500);
				} else {
					loose = true;
					endGame = true;
				}
			}
		}
		Sleep(gameSpeed);
	}
	clearConsole();
	if (loose) {
		cout << "You failed to protect the earth from hostile aliens" << endl;
	}
	return 0;
}
