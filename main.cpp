/*! \file main.cpp
*
* \author Jakub Rosinski
* \date 2020.05.15
* \version 1.00.00
*/

#include <iostream>
#include "windows.h"

using namespace std;

char map[20][20] = {

"###################",
"#                 #",
"# @ @ @ @ @ @ @ @ #",
"#  @ @ @ @ @ @ @  #",
"#   @ @ @ @ @ @   #",
"#    @ @ @ @ @    #",
"#     @ @ @ @     #",
"#      @ @ @      #",
"#       @ @       #",
"#        @        #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#       W         #",
"###################"

};

bool endgame = false;
int gamespeed = 100;
int randomNum;

int main()
{
	system("color 0a");
	while (endgame == false) {

		system("cls");
		for (int y = 0; y < 20; y++ ) {

			cout << map[y] << endl;

		}

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
				}
			}
		}
		Sleep(gamespeed);
	}

	return 0;
}