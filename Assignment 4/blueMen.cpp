/*********************************************************************
** Program Filename: blueMen.cp
** Author: Daniel Olivas
** Date: 11/20/2016
*********************************************************************/
#include "blueMen.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
/*********************************************************************
** Function:  attack
** Description:  attack function rolls 2 dice of aDice size and
**	is set to assault. Assault is returned
*********************************************************************/
int BlueMen::attack()
{
	assault = (rand() % aDice) + 1;
	assault += (rand() % aDice) + 1;
	return assault;
}
/*********************************************************************
** Function: defense
** Description: defense function rolls 3 dice of aDice size if strPoint
**  is greater than 8, 2 dice if strPoints is greater than 4 or less than
**  or equal to 8, and 1 die if strPoints is 4 or less.
**	Defend is returned
*********************************************************************/
int BlueMen::defense()
{
	if (strPoints > 8)
	{
		defend = (rand() % dDice) + 1;
		defend += (rand() % dDice) + 1;
		defend += (rand() % dDice) + 1;
	}
	else if (strPoints > 4 || strPoints <= 8)
	{
		defend = (rand() % dDice) + 1;
		defend += (rand() % dDice) + 1;
	}
	else if (strPoints <= 4)
	{
		defend = (rand() % dDice) + 1;
		std::cout << "\n" << defend << "\n";
	}
	return defend;
}
/*********************************************************************
** Function: strengthPoints
** Description: strengthPoints takes damage and calculates to return
** new strength points. If new strength points is more than previous
** previous is returned.
*********************************************************************/
int BlueMen::strengthPoint(int damage)
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
int BlueMen::getStrengthPoint()
{
	return strPoints;
}
void BlueMen::setStrenthPoints(int heal)
{
	strPoints = heal;
}
/*********************************************************************
** Function: getName
** Description: returns name
**
*********************************************************************/
std::string BlueMen::getName()
{
	return "Blue Men";
}
/*********************************************************************
** Function: heal
** Description: heal is called if creature wins. 3 points are added
** to strPoints. If more than strPoints + heal points is more than
** original strPoints, strPoints is reset to 100%.
*********************************************************************/
int BlueMen::heal()
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
