/*********************************************************************
** Author: Daniel Olivas
** Date: 10/9/2016
** Description: Ant.hpp
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Ant.hpp"

class Ant {
private:
	char dir;
	char newCurr;
	char ant;
	char white;
	char black;
	int spotX;
	int spotY;
public:
	//constructor
	Ant();
	// move function places the ant on user defined location.
	// function also moves ant the user defined times and displays the 2d array after each move.
	void move(char **, int, int, int, int);
};

#endif // !ANT_HPP
