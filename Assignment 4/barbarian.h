/*********************************************************************
** Program Filename: barbarian.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Barbarian is a derived class from creature
*********************************************************************/
#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "creature.h"

class Barbarian : public Creature {

public:
	Barbarian() : Creature(6, 6, 0, 12, 0) {};
	int attack();
	int defense();
	int strengthPoint(int);
	int getStrengthPoint();
	void setStrenthPoints(int);
	// getName and heal are added for assignment 4
	std::string getName();
	int heal();
};

#endif // !BARBARIAN_H
