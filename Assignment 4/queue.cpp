/*********************************************************************
** Program Filename: queue.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: Queue is used to hold creatures for the tournament
*********************************************************************/

#include "queue.h"
#include <iostream>
//constructor
Queue::Queue()
{
	head = NULL;
	tail = NULL;
}
// destructor
Queue::~Queue()
{
	ListNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		ListNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage->C;
		delete garbage;
	}
}
/*********************************************************************
** Function: void push
** Description: push is called in tournament and is used to push creature
**  into queued link list. winner of battle is pushed back into queue
*********************************************************************/

void Queue::push(Creature * C)
{
	ListNode *nodePtr = new ListNode(C);
	nodePtr->next = NULL;
	nodePtr->previous = tail;

	if (head == NULL)
	{
		head = nodePtr;
		tail = nodePtr;
	}
	else
	{
		tail->next = nodePtr;
		tail = nodePtr;
	}
}
/*********************************************************************
** Function: Creature pop
** Description: pop is called in tournament to pop creature out of
**		linked list for battle.
*********************************************************************/

Creature *Queue::pop()
{
	ListNode *nodePtr = tail;
	if (!head)
	{
		std::cout << "Queue is empty\n";
		return 0;
	}
	else
	{
		nodePtr = head;
		Creature *x = head->C;
		head = head->next;
		delete nodePtr;
		return x;
	}
}
/*********************************************************************
** Function: bool isEmpty
** Description: isEmpty return true if list is empty, false if list
**  is not empty.
*********************************************************************/

bool Queue::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}
