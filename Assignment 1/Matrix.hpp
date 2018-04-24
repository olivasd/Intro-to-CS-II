/*********************************************************************
** Author: Daniel Olivas
** Date: 10/9/2016
** Description: Matrix.hpp
*********************************************************************/

#ifndef MATRIX_HPP
#define MARTRIX_HPP

class Matrix {

private:

	int sizeX;
	int sizeY;
	char **array;
	char white;
	
public:
	//constructor
	Matrix();
	//destructor
	~Matrix();
	//setters and getters
	void setSizeX(int);
	int getSizeX();
	void setSizeY(int);
	int getSizeY();
	//fills the grid
	char **grid();
};

#endif // !MATRIX_HPP
