/*********************************************************************
** Author: Daniel Olivas
** Date: 10/9/2016
** Description: Matrix.cpp
*********************************************************************/

#include "Matrix.hpp"
#include <iostream>

//constructor
Matrix::Matrix()
{
	this->white = ' ';
}
//destructor -- deallocates dynamic 2d array, sets array to 0
Matrix::~Matrix()
{
	for (int i = 0; i < sizeX; i++) {
		delete[] array[i];
	}
	delete[] array;
	array = 0;
}

void Matrix::setSizeX(int sizeX)
{
	this->sizeX = sizeX;
}

int Matrix::getSizeX()
{
	return sizeX;
}

void Matrix::setSizeY(int sizeY)
{
	this->sizeY = sizeY;
}

int Matrix::getSizeY()
{
	return sizeY;
}
// dynamically allocates 2d array with user defined size.
//returns array filled with all white
char **Matrix::grid()
{
	array = new char*[sizeX];
	for (int i = 0; i < sizeX; i++)
		array[i] = new char[sizeY];
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			array[i][j] = white;
		}
	}
	return array;
}