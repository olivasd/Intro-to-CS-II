/*********************************************************************
** Program Filename: main.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: main.cpp runs the tournament
*********************************************************************/

#include "tournament.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	Tournament A;
	std::cout << "\n*************************************************\n" <<
		"* Welcome To The Fantasy Combat Game Tournament *\n"<<
		"*************************************************\n\n";
	A.fighterQueue();
	A.battle();
	A.winner();
	std::cout << "Press 1 to see loser pile or other key to exit:";
	char choice;
	std::cin >> choice;
	if (choice == '1')
		A.losers();

	return 0;
}