/*! \file main.cpp
*
* \author Jakub Rosinski, Michal Skowronski, Oskar Smektala
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

bool endgame = false;
int gamespeed = 100;
int randomNum;
int maxhealth = 200;
int yourhealth = maxhealth;

int main()
{
	system("color 0a");
	while (endgame == false) {

		srand(time(0));
		system("cls");
		for (int y = 0; y < 20; y++ ) {

			cout << map[y] << endl;

		}

		cout << "Health " << yourhealth << "/" << maxhealth;

		for (int y = 0; y < 20; y++ ) {
			for (int x = 0; x < 20; x++) {

				switch (map[y][x]) {
					
					case 'W':

						if (GetAsyncKeyState(VK_LEFT) != 0) {

							int newX = x - 1;

						    switch (map[y][newX]) {

								case ' ':
								map[y][x] = ' ';
								x--;
								map[y][newX] = 'W';
								break;
								}

						}
						if (GetAsyncKeyState(VK_RIGHT) !=0) {

							int newX = x + 1;

							switch (map[y][newX]) {

								case ' ':
								map[y][x] = ' ';
								x++;
								map[y][newX] = 'W';
								break;
								}
							}
						if (GetAsyncKeyState(VK_SPACE) !=0) {

							y--;
							map[y][x] = '^';

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

					}


					break;

					case '@':

						randomNum = rand() % 50 + 1;;

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
							yourhealth -= 20;
						}
						break;

				}
			}
			if (yourhealth <= 0) {
				endgame = true;
			}
		}
		Sleep(gamespeed);
	}
	system("cls");
	cout << "You failed to protect the earth from hostile aliens" << endl;
	system("PAUSE");
	return 0;
}
