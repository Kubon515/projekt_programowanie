/*! \file main.cpp
*
* \author Jakub Rosinski, Michał Skowroński 
* \date 2020.05.15, 2020.05.16
* \version 1.00.00
*/

#include <iostream>
#include "windows.h"
#include "time.h"

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
"#        W        #",
"###################"

};

bool endgame = false;
int gamespeed = 100;
int randomNum;
int MaxHealth = 200;
int yourHealth = MaxHealth;

int main()
{
	
	
	
	system("color 0a");
	while (endgame == false) {
		

		srand(time(0));
		system("cls");
		for (int y = 0; y < 20; y++ ) {

			cout << map[y] << endl;

		}
		
		cout<< "Health " << yourHealth << "/" << maxHealth;

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

					

					}


				break;
						
					case '@ ':
					randomNum = rand() %10 +1;
						
						if(randomNum == 1) {
							y++;
							Map[y][x] = '*';
						
						break;
						
							case '*':
							Map[y][x] = '';
							y++;
							
							if(Map[y][x] !='#' && Map[y][x] !='W'){
							Map[y][x] = '*';
							}else if (Map[y][x] == 'W') {
								
									yourHealth -= 20;
							}
							break;
							
				}
			}
		}
		if(yourHealth <= 0){
		
			endgame = true;
		}
			
		Sleep(gamespeed);
	}

	system("cls");	
	cout << "You failed to protect the earth from hostile aliens" <<endl;	
	
		system("PAUSE");
	return 0;
}
