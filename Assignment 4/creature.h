/*********************************************************************
** Program Filename: creature.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Creature class is a virtual base class
*********************************************************************/
#ifndef CREATURE_H
#define CREATURE_H
#include <string>

class Creature {
protected:
	int aDice;
	int dDice;
	int armor;
	int strPoints;
	int assault;
	int defend;
	int tempStr;
	int hogPoints;
public:
	Creature(int aDice, int dDice, int armor, int strPoints, int hogPoints) : aDice(aDice), dDice(dDice), armor(armor), strPoints(strPoints), hogPoints(hogPoints) {};
	virtual int attack() = 0;
	virtual int defense() = 0;
	virtual int strengthPoint(int) = 0;
	virtual void setStrenthPoints(int) = 0;
	virtual int getStrengthPoint() = 0;
	// getName and heal are added for assignment 4
	virtual std::string getName() = 0;
	virtual int heal() = 0;
};

#endif // !CREATURE_H
