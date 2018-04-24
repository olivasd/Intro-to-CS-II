/*********************************************************************
** Program Filename: harrypotter.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: harryPotter is a derived class from creature
*********************************************************************/
#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H
#include "creature.h"

class HarryPotter : public Creature {

public:
	HarryPotter() : Creature(6, 6, 0, 10, 20) {};
	int attack();
	int defense();
	int strengthPoint(int);
	int getStrengthPoint();
	void setStrenthPoints(int);
	// getName and heal are added for assignment 4
	std::string getName();
	int heal();
};
#endif // !HARRYPOTTER_H
