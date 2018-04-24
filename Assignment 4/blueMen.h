/*********************************************************************
** Program Filename: blueMen.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: BlueMen is a derived class from creature
*********************************************************************/
#ifndef BLUEMEN_H
#define BLUEMEN_H
#include "creature.h"

class BlueMen : public Creature {

public:
	BlueMen() : Creature(10, 6, 3, 12, 0) {};
	int attack();
	int defense();
	int strengthPoint(int);
	int getStrengthPoint();
	void setStrenthPoints(int);
	// getName and heal are added for assignment 4
	std::string getName();
	int heal();
};
#endif // !BLUEMEN_H

