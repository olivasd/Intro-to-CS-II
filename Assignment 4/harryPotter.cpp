/*********************************************************************
** Program Filename: harryPotter.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
*********************************************************************/
#include "harryPotter.h"
#include <stdlib.h>
#include <time.h>

/*********************************************************************
** Function:  attack
** Description:  attack function rolls 2 dice of aDice size and
**	is set to assault. Assault is returned
*********************************************************************/
int HarryPotter::attack()
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
int HarryPotter::defense()
{
	defend = (rand() % dDice) + 1;
	defend += (rand() % dDice) + 1;
	return defend;
}
/*********************************************************************
** Function: strengthPoints
** Description: strengthPoints takes damage and calculates to return
** new strength points. If new strength points is more than previous
** previous is returned. If strPoints is 0 or less, then strPoints becomes
**  hogPoints.
*********************************************************************/
int HarryPotter::strengthPoint(int damage)
{
	tempStr = 0;
	tempStr = strPoints - damage + armor;
	if (tempStr > strPoints)
		return strPoints;
	else
	{
		strPoints = tempStr;
	}

	if (strPoints <= 0)
	{
		strPoints = hogPoints;
		hogPoints = 0;
	}
	return strPoints;
}
// returns strPoints
int HarryPotter::getStrengthPoint()
{
	return strPoints;
}
void HarryPotter::setStrenthPoints(int heal)
{
	strPoints = heal;
}
/*********************************************************************
** Function: getName
** Description: returns name
**
*********************************************************************/
std::string HarryPotter::getName()
{
	return "Harry Potter";
}
/*********************************************************************
** Function: heal
** Description: heal is called if creature wins. 3 points are added
** to strPoints. If more than strPoints + heal points is more than
** original strPoints, strPoints is reset to 100%.
*********************************************************************/
int HarryPotter::heal()
{
	int heal = strPoints + 3;
	if (heal > strPoints)
		return 10;
	else
	{
		strPoints = heal;
		return strPoints;
	}
}
