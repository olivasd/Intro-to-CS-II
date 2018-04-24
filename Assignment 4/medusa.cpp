/*********************************************************************
** Program Filename: medusa.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
*********************************************************************/
#include "medusa.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

/*********************************************************************
** Function:  attack
** Description:  attack function rolls 2 dicee of aDice size and
**	is set to assault. Assault is returned. If assault == 12, 100 is
**  returned(Glare turns opponent to stone).
*********************************************************************/
int Medusa::attack()
{
	assault = (rand() % aDice) + 1;
	assault += (rand() % aDice) + 1;
	if (assault == 12)
	{
		return 100;
	}
	else
		return assault;
}
/*********************************************************************
** Function: defense
** Description: defense function rolls a single die of aDice size and
**	is set to defend. Defend is returned
*********************************************************************/
int Medusa::defense()
{
	defend = 0;
	defend = (rand() % dDice) + 1;
	return defend;
}
/*********************************************************************
** Function: strengthPoints
** Description: strengthPoints takes damage and calculates to return
** new strength points. If new strength points is more than previous
** previous is returned.
*********************************************************************/
int Medusa::strengthPoint(int damage)
{
	tempStr = 0;
	tempStr = strPoints - damage + armor;
	if (tempStr > strPoints)
		return strPoints;
	else
	{
		strPoints = tempStr;
		return strPoints;
	}
}
//returns strPoints
int Medusa::getStrengthPoint()
{
	return strPoints;
}
void Medusa::setStrenthPoints(int heal)
{
	strPoints = heal;
}
/*********************************************************************
** Function: getName
** Description: returns name
**
*********************************************************************/
std::string Medusa::getName()
{
	return "Medusa";
}
/*********************************************************************
** Function: heal
** Description: heal is called if creature wins. 3 points are added
** to strPoints. If more than strPoints + heal points is more than
** original strPoints, strPoints is reset to 100%.
*********************************************************************/
int Medusa::heal()
{
	int heal = strPoints + 3;
	if (heal > strPoints)
		return 8;
	else
	{
		strPoints = heal;
		return strPoints;
	}
}
