/*********************************************************************
** Program Filename: medusa.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Medusa is a derived class from creature
*********************************************************************/
#ifndef MEDUSA_H
#define MEDUSA_H
#include "creature.h"

class Medusa : public Creature {

public:
	Medusa() : Creature(6, 6, 3, 8, 0) {};
	int attack();
	int defense();
	int strengthPoint(int);
	int getStrengthPoint();
	void setStrenthPoints(int);
	// getName and heal are added for assignment 4
	std::string getName();
	int heal();
};
#endif // !MEDUSA_H

