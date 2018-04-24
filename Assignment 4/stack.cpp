/*********************************************************************
** Program Filename: stack.cpp
** Author: Daniel Olivas
** Date: 11/20/2016
** Description: stack is used to hold the loser pile creatures in tournament
*********************************************************************/
#include "stack.h"
#include <iostream>
//constructor
Stack::Stack()
{
	head = NULL;
}
//destructor
Stack::~Stack()
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
** Description: push is called in tournament to add loser of battle
**  into stacked link list.
*********************************************************************/
void Stack::push(Creature *C)
{
	if (head == NULL)
		head = new ListNode(C);
	else
	{
		ListNode *nodePtr = head;
		nodePtr = nodePtr->next;
		nodePtr = head;
		head = new ListNode(C, nodePtr);
	}
}
/*********************************************************************
** Function: Creature pop
** Description: pop is called in tournament to pop creature out of
**		linked list to display loser pile.
*********************************************************************/
Creature * Stack::pop()
{
	ListNode *nodePtr;
	if (!head)
	{
		std::cout << "List is empty\n";
		return NULL;
	}
	else
	{
		nodePtr = head;
		Creature *remove = nodePtr->C;
		head = head->next;
		delete nodePtr;
		return remove;
	}
}
/*********************************************************************
** Function: bool isEmpty
** Description: isEmpty return true if list is empty, false if list
**  is not empty.
*********************************************************************/

bool Stack::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

