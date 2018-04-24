/*********************************************************************
** Program Filename: list.hpp
** Author: Daniel Olivas
** Date: 10/24/2016
** Description: list class creates itemList array with functions that
**		adds/removes items from list and displays list
*********************************************************************/
#ifndef LIST_HPP
#define LIST_HPP
#include "item.hpp"

class List {
private:
	int size, current;
	Item *itemList;
	double listTotal;
	std::string name;
	std::string unitType;
	int quantity;
	double unitPrice;
public:
	//default constructor
	List();
	//deconstructor
	~List();
	//functions
	void addItem();
	void removeItem();
	void displayList();
	void menu();
};

#endif // !LIST_HPP
