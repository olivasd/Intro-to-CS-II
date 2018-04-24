/*********************************************************************
** Author: Daniel Olivas
** Date: 10/9/2016
** Description: Ant.cpp
*********************************************************************/
#include "Ant.hpp"
#include <iostream>
#include <cstdlib>
//#include "Matrix.hpp"
// constructor
Ant::Ant()
{
	this->ant = '*';
	this->white = ' ';
	this->black = '#';
	this->dir = 'n';						//sets starting direction north
	this->newCurr = 'w';					//sets first spot ant is on white
}
// move function
void Ant::move(char **array, int sizeX, int sizeY, int spotX, int spotY)
{
	int moves;
	array[spotX][spotY] = ant;		//places ant at spotX x spotY
	std::cout << "How many moves (recommend less than 10,000)?? ";
	std::cin >> moves; 
	for (int i = 0; i < moves; i++) {
		// checks boundaries and changes direction 180 degrees if ant at boundaries
		{
			if (spotX >= (sizeX - 1))
			{
				if (newCurr == 'w')
				array[spotX][spotY] = black;
				else array[spotX][spotY] = white;
				int temp = (spotX - 1);
					spotX = temp;
					array[spotX][spotY] = ant;
			}
			else if (spotX == 0)
			{
				if (newCurr == 'w')
					array[spotX][spotY] = black;
				else array[spotX][spotY] = white;
				int temp = (spotX + 1);
				spotX = temp;
				array[spotX][spotY] = ant;
			}
			else if (spotY >= (sizeY - 1))
			{
				if (newCurr == 'w')
					array[spotX][spotY] = black;
				else array[spotX][spotY] = white;
				int temp = (spotY - 1);
				spotY = temp;
				array[spotX][spotY] = ant;
			}
			else if (spotY == 0)
			{
				if (newCurr == 'w')
					array[spotX][spotY] = black;
				else array[spotX][spotY] = white;
				int temp = (spotY + 1);
				spotY = temp;
				array[spotX][spotY] = ant;
			}
			
			else if (spotY >= (sizeY - 1) || spotY == 0)
			{
				if (dir = 'w') {
					array[spotX][spotY] = black;
					int temp = (spotY + 1);
					spotY = temp;
					//dir = 'e';
					array[spotX][spotY] = ant;
				}
				else if (dir = 'e') {
					array[spotX][spotY] = black;
					int temp = (spotY - 1);
					spotY = temp;
					//dir = 'w';
					array[spotX][spotY] = ant;
				}
			}
		}
		 // 16 different possible moves. 8 if-else if statements for the possible directions from
		 //   and color of current ant position. 2 nested if-else if per to identify which direction to
		 //	  go depending on color of next spot.
		if (dir == 'n' && newCurr == 'w')
		{
			if (array[spotX - 1][spotY] == white) {
				dir = 'e';
				newCurr = 'w';
				array[spotX][spotY] = black;
				int  temp = spotX - 1;
				spotX = temp;
				array[spotX][spotY] = ant;

			}
			else if (array[spotX - 1][spotY] == black) {
				array[spotX][spotY] = black;
				dir = 'w';
				newCurr = 'b';
				int  temp = spotX - 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 'n' && newCurr == 'b')
		{
			if (array[spotX - 1][spotY] == white) {
				array[spotX][spotY] = white;
				dir = 'e';
				newCurr = 'w';
				int  temp = spotX - 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX - 1][spotY] == black) {
				array[spotX][spotY] = white;
				dir = 'w';
				newCurr = 'b';
				int  temp = spotX - 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 's' && newCurr == 'w')
		{
			if (array[spotX + 1][spotY] == white) {
				array[spotX][spotY] = black;
				dir = 'w';
				newCurr = 'w';
				int  temp = spotX + 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX + 1][spotY] == black) {
				array[spotX][spotY] = black;
				dir = 'e';
				newCurr = 'b';
				int  temp = spotX + 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 's' && newCurr == 'b')
		{
			if (array[spotX + 1][spotY] == white) {
				array[spotX][spotY] = white;
				dir = 'w';
				newCurr = 'w';
				int  temp = spotX + 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX + 1][spotY] == black) {
				array[spotX][spotY] = white;
				dir = 'e';
				newCurr = 'w';
				int  temp = spotX + 1;
				spotX = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 'e' && newCurr == 'w')
		{
			if (array[spotX][spotY + 1] == white) {
				array[spotX][spotY] = black;
				dir = 's';
				newCurr = 'w';
				int  temp = spotY + 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX][spotY + 1] == black) {
				array[spotX][spotY] = black;
				dir = 'n';
				newCurr = 'w';
				int  temp = spotY + 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 'e' && newCurr == 'b')
		{
			if (array[spotX][spotY + 1] == white) {
				array[spotX][spotY] = white;
				dir = 's';
				newCurr = 'w';
				int  temp = spotY + 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX][spotY + 1] == black) {
				array[spotX][spotY] = white;
				dir = 'n';
				newCurr = 'b';
				int  temp = spotY + 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 'w' && newCurr == 'w')
		{
			if (array[spotX][spotY - 1] == white) {
				array[spotX][spotY] = black;
				dir = 'n';
				newCurr = 'w';
				int  temp = spotY - 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX][spotY - 1] == black) {
				array[spotX][spotY] = black;
				dir = 's';
				newCurr = 'b';
				int  temp = spotY - 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
		}
		else if (dir == 'w' && newCurr == 'b')
		{
			if (array[spotX][spotY - 1] == white) {
				array[spotX][spotY] = white;
				dir = 'n';
				newCurr = 'w';
				int  temp = spotY - 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
			else if (array[spotX][spotY - 1] == black) {
				array[spotX][spotY] = white;
				dir = 's';
				newCurr = 'b';
				int  temp = spotY - 1;
				spotY = temp;
				array[spotX][spotY] = ant;
			}
		}
		std::cout << "\033[2J\033[1;1H" << std::endl;	//clears console before displaying next move
		// 033 - Escape
		// [2J - Clear console
		// [1;1H - Move cursor to (1,1)
		int count = 0;
		// for loop to display array
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				std::cout << array[i][j] << " ";
				count++;
				if (count % sizeX == 0)
					std::cout << std::endl;
			}
		}
	}
}