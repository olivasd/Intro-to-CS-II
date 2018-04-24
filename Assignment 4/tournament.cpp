/*********************************************************************
** Program Filename: tournament.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Tournament is called by main and runs battle of creatures
*********************************************************************/

#include "tournament.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//constructor
Tournament::Tournament()
{
	srand(time(NULL));
	win1 = 0;
	win2 = 0;
	round = 1;
	count = 1;
}
/*********************************************************************
** Function: void cMenu
** Description: cMenu diplays creature menu
*********************************************************************/

void Tournament::cMenu()
{
	std::cout << "1. Vampire\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n";
}
/*********************************************************************
** Function: void fighterQueue
** Description: Prompts user names, creature amounts, and calls 
** queue push function to add creature to queue
*********************************************************************/

void Tournament::fighterQueue()
{
	std::cout << "Please enter first team name: ";
	std::getline(std::cin, p1name);
	std::cout << "Please enter second team name: ";
	std::getline(std::cin, p2name);
	std::cout << "How many fighters will each team have? ";
	std::cin >> numCreature;
	std::cout << p1name << std::endl;
	cMenu();
	for (int i = 0; i < numCreature; i++)
			{
			std::cout << "\nPress number for creature " << count << " or x to show menu: ";
			std::cin >> select;
			switch (select)
			{
			case '1':
				creature = new Vampire;
				P1.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '2':
				creature = new Barbarian;
				P1.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '3':
				creature = new BlueMen;
				P1.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '4':
				creature = new Medusa;
				P1.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '5':
				creature = new HarryPotter;
				P1.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case 'x':
			case 'X':
				cMenu();
				i--;
				break;
			default:
				std::cout << "Invalid Selection!\n";
				i--;
			}
	} 
		
	std::cout << p2name << std::endl;
	cMenu();
	count = 1;
		for (int i = 0; i < numCreature; i++)
		{
			std::cout << "\nPress number for creature " << count << " or x to show menu: ";
			std::cin >> select;
			switch (select)
			{
			case '1':
				creature = new Vampire;
				P2.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '2':
				creature = new Barbarian;
				P2.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '3':
				creature = new BlueMen;
				P2.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '4':
				creature = new Medusa;
				P2.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case '5':
				creature = new HarryPotter;
				P2.push(creature);
				std::cout << "Creature " << count << ": " << creature->getName() << std::endl;
				count++;
				break;
			case 'x':
			case 'X':
				cMenu();
				i--;
				break;
			default:
				std::cout << "Invalid Selection!\n";
				i--;
			}
		} 
}
/*********************************************************************
** Function: void battle
** Description: same battle algorithm as assinment 3. Added round counter
** and display for winner of each round. winner is pushed back to 
** team queue, loser is pushed to stack
*********************************************************************/

void Tournament::battle()
{
	
	while (!P1.isEmpty() && !P2.isEmpty())
	{
		C1 = P1.pop();
		C2 = P2.pop();
		int damage;
		char check;
		int c1Strength = C1->getStrengthPoint();
		int c2Strength = C2->getStrengthPoint();
		int turn = (rand() % 2);		//random for who goes first
		if (turn == 0)					//turn 0 = creature1 first
		{
			while (c1Strength > 0 && c2Strength > 0)
			{
				damage = C1->attack() - C2->defense();
				c2Strength = C2->strengthPoint(damage);

				if (c2Strength > 0)
				{
					damage = C2->attack() - C1->defense();
					c1Strength = C1->strengthPoint(damage);
				}
			}
		}
		else					//Creature 2 goes first
		{
			while (c2Strength > 0 && c1Strength > 0)
			{
				c2Strength;
				damage = C2->attack() - C1->defense();
				c1Strength = C1->strengthPoint(damage);

				if (c1Strength > 0)
				{
					damage = C1->attack() - C2->defense();
					c2Strength = C2->strengthPoint(damage);
				}
			}
		}
		std::cout << "Round " << round << ": " << p1name << "'s " << C1->getName() << " vs " << p2name << "'s " << C2->getName() << std::endl;
		if (c1Strength > 0)		//C1 = winner
		{
			std::cout << p1name << "'s " << C1->getName() << " defeated " << p2name << "'s " << C2->getName() << std::endl;
			c1Strength = C1->heal();
			C1->setStrenthPoints(c1Strength);
			P1.push(C1);
			L.push(C2);
			round++;
			win1++;
		}
		else					//C2 = winner
		{
			std::cout << p2name << "'s " << C2->getName() << " defeated " << p1name << "'s " << C1->getName() << std::endl;
			c2Strength = C2->heal();
			C2->setStrenthPoints(c2Strength);
			P2.push(C2);
			L.push(C1);
			round++;
			win2++;
		}
		std::cout << "\nPress 1 for current score or any other key to continue: ";
		do {
			std::cin >> check;
			{
				std::cout << std::endl;
				if (check == '1')
					currScore();
				
			}
		} while (check == '1');
	}
}
/*********************************************************************
** Function: void losers
** Description: calls stack pop function in stack to display the loser
** list when called in main
*********************************************************************/

void Tournament::losers()
{
	int count;
	while (!L.isEmpty())
	{
		creature = L.pop();
		std::cout << "round " << round - 1 << " loser: ";
		std::cout << creature->getName() << std::endl;
		round--;
	}
}
/*********************************************************************
** Function:  void winner
** Description: is called in main, displays the winner of tournament
**	and point total
*********************************************************************/

void Tournament::winner()
{
	if (win1 > win2)
	{
		std::cout << "congratulations " << p1name << "!\n"
			"You defeated " << p2name << " " << win1 << " to " << win2 << "!\n\n";
	}
	else
	{
		std::cout << "congratulations " << p2name << "!\n"
			"You defeated " << p1name << " " << win2 << " to " << win1 << "!\n\n";
	}
}
/*********************************************************************
** Function: void currScore
** Description: currScore is called in between rounds in battle to
** display the current score
*********************************************************************/

void Tournament::currScore()
{
	if (win1 > win2)
		std::cout  << p1name << " is winning " << win1 << " to " << win2 << "!";
	else if(win2 > win1)
		std::cout << p2name << " is winning " << win2 << " to " << win1 << "!";
	else if (win1 == win2)
		std::cout << "Tournament is tied " << win1 << " to " << win2 << "!";
	std::cout << "\nPress 1 for current score or any other key to continue: ";
	std::cout << std::endl;
}
