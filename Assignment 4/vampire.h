/*********************************************************************
** Program Filename: vampire.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Vampire is a derived class from creature
*********************************************************************/
#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "creature.h"

class Vampire : public Creature {
private:
	int charm;
public:
	Vampire() : Creature(12, 6, 1, 18, 0) {};
	int attack();
	int defense();
	int strengthPoint(int);
	int getStrengthPoint();
	void setStrenthPoints(int);
	// getName and heal are added for assignment 4
	std::string getName();
	int heal();

};
#endif // !VAMPIRE_H