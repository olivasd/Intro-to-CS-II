/*********************************************************************
** Program Filename: barbarian.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
*********************************************************************/
#include "barbarian.h"
#include <stdlib.h>
#include <time.h>
/*********************************************************************
** Function:  attack
** Description:  attack function rolls 2 dice of aDice size and
**	is set to assault. Assault is returned
*********************************************************************/
int Barbarian::attack()
{
	assault = (rand() % aDice) + 1;
	assault += (rand() % aDice) + 1;
	return assault;
}
/*********************************************************************
** Function: defense
** Description: defense function rolls 2 dice of aDice size and
**	is set to defend. Defend is returned
*********************************************************************/
int Barbarian::defense()
{
	defend = (rand() % dDice) + 1;
	defend += (rand() % dDice) + 1;
	return defend;
}
/*********************************************************************
** Function: strengthPoints
** Description: strengthPoints takes damage and calculates to return
** new strength points. If new strength points is more than previous
** previous is returned.
*********************************************************************/
int Barbarian::strengthPoint(int damage)
{
	tempStr = strPoints - damage + armor;
	if (tempStr > strPoints)
		return strPoints;
	else
	{
		strPoints = tempStr;
		return strPoints;
	}
}
//return strPoints
int Barbarian::getStrengthPoint()
{
	return strPoints;
}
void Barbarian::setStrenthPoints(int heal)
{
	strPoints = heal;
}
/*********************************************************************
** Function: getName
** Description: returns name
**
*********************************************************************/

std::string Barbarian::getName()
{
	return "Barbarian";
}
/*********************************************************************
** Function: heal
** Description: heal is called if creature wins. 3 points are added
** to strPoints. If more than strPoints + heal points is more than
** original strPoints, strPoints is reset to 100%.
*********************************************************************/

int Barbarian::heal()
{
	int heal = strPoints + 3;
	if (heal > strPoints)
		return 12;
	else
	{
		strPoints = heal;
		return strPoints;
	}
}
