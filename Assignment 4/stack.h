/*********************************************************************
** Program Filename: stack.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: stack is used to hold the loser pile creatures in tournament
*********************************************************************/

#ifndef STACK_H
#define STACK_H
#include <string>
#include "creature.h"
#include "vampire.h"
#include "barbarian.h"
#include "blueMen.h"
#include "medusa.h"
#include "harryPotter.h"

class Stack {
private:
	struct ListNode {
		Creature *C;
		ListNode *next;
		ListNode(Creature *C1 = NULL, ListNode *next1 = NULL)
		{
			C = C1;
			next = next1;
		}
	};
	ListNode *head;
public:
	Stack();
	~Stack();
	void push(Creature *);
	Creature* pop();
	bool isEmpty();
};

#endif // !STACK_H
