/*********************************************************************
** Author: Daniel Olivas
** Date: 10/9/2016
** Description: main.cpp
*********************************************************************/
#include "Matrix.hpp"
#include "Ant.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int spot, x, y, spotX, spotY;
	Matrix A;
	Ant B;
	std::cout << "****Welcome to Langton's Ant!****" << std::endl;
	std::cout << "How many COLUMNS would you like? Between 10 to 50 is recommended. ";
	std::cin >> x;
	std::cout << "How many ROWS would you like? Between 10 to 50 is recommended. ";
	std::cin >> y;
	A.setSizeX(x);
	A.setSizeY(y);
			
	// do while loop to get either user defined starting location or a random starting location
	// displays "invalid Selection" is 1 or 2 is not selected.
	do {
		std::cout << "press 1 to manually select the starting location" << std::endl << "or press 2 to have ant randomly placed. ";
		std::cin >> spot;

		switch (spot)
		{

		case '1':
			std::cout << "Which COLUMN would you like? " << x / 2 << " is recommended.";
			std::cin >> spotX;
			std::cout << "Which ROW would you like? " << y / 2 << " is recommended.";
			std::cin >> spotY;
			break;
		case '2':
			// random location
			spotX = rand() % x;
			spotY = rand() % y;
			break;
		default:
			std::cout << "Invalid Selection!" << std::endl;
		}
	}
		while (spot != '1' && spot != '2');
		B.move(A.grid(), A.getSizeX(), A.getSizeY(), spotX - 1, spotY - 1);
	
	std::cout << "Thanks for playing and have a great day!\n";
	return 0;
}