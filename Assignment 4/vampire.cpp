/*********************************************************************
** Program Filename: vampire.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
*********************************************************************/
#include "vampire.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
/*********************************************************************
** Function:  attack
** Description:  attack function rolls a single die of aDice size and
**	is set to assault. Assault is returned
*********************************************************************/
int Vampire::attack()
{
	assault = (rand() % aDice) + 1;
	return assault;
}
/*********************************************************************
** Function: defense
** Description: defense function rolls a single die of aDice size and
**	is set to defend. Defend is returned
*********************************************************************/
int Vampire::defense()
{
	defend = (rand() % dDice) + 1;
	return defend;
}
/*********************************************************************
** Function: strengthPoints
** Description: strengthPoints takes damage and calculates to return
** new strength points. If new strength points is more than previous
** previous is returned. If Charm, no damage happens.
*********************************************************************/
int Vampire::strengthPoint(int damage)
{
	charm = (rand() % 2);
	if (charm == 0)
	{
		return strPoints;
	}
	tempStr = strPoints - damage + armor;
	if (tempStr > strPoints)
		return strPoints;
	else
	{
		strPoints = tempStr;
		return strPoints;
	}

}
//returns strengthPoints
int Vampire::getStrengthPoint()
{
	return strPoints;
}
void Vampire::setStrenthPoints(int heal)
{
	strPoints = heal;
}
/*********************************************************************
** Function: getName
** Description: returns name
**
*********************************************************************/
std::string Vampire::getName()
{
	return "Vampire";
}
/*********************************************************************
** Function: heal
** Description: heal is called if creature wins. 3 points are added
** to strPoints. If more than strPoints + heal points is more than
** original strPoints, strPoints is reset to 100%.
*********************************************************************/
int Vampire::heal()
{
	int heal = strPoints + 3;
	if (heal > strPoints)
		return 18;
	else
	{
		strPoints = heal;
		return strPoints;
	}
}
