/*********************************************************************
** Program Filename: queue.h
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Queue is used to hold creatures for the tournament
*********************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "creature.h"
#include "vampire.h"
#include "barbarian.h"
#include "blueMen.h"
#include "medusa.h"
#include "harryPotter.h"

class Queue {
private:
	struct ListNode {
		Creature *C;
		ListNode *next;
		ListNode *previous;
		ListNode(Creature *C1 = NULL)
		{
			C = C1;
			next = NULL;
			previous = NULL;
		}
	};
	ListNode *head;
	ListNode *tail;
public:
	Queue();
	~Queue();
	void push(Creature *);
	Creature* pop();
	bool isEmpty();
	
};
#endif // !QUEUE_H