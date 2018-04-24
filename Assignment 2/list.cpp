/*********************************************************************
** Program Filename: list.cpp
** Author: Daniel Olivas
** Date: 10/24/2016
** Description: list class creates itemList array with functions that
**		 adds/removes items from list and displays list
*********************************************************************/
#include "list.hpp"
#include <iostream>
#include <iomanip>
//default constructor
List::List()
{
	size = 4;
	current = 0;
	itemList = new Item[size];
}
//deconstructor -- deallocates itemList array
List::~List()
{
	delete[] itemList;
	itemList = 0;
}
/*********************************************************************  
** Function:  addItem function
** Description:  addItem gets item, type, quantity, and price from user
**		if itemList is full(current == size), itemList is doubled in size
*********************************************************************/
void List::addItem()
{
	std::cout << "please enter the item's name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Unit type (can, box, pound, or ounce): ";
	std::getline(std::cin, unitType);
	std::cout << "How many " << unitType << "s of " << name << ": ";
	std::cin >> quantity;
	std::cout << "Price per " << unitType << " of " << name << ": $";
	std::cin >> unitPrice;
	if (current < size)
	{
		itemList[current] = Item(name, unitType, quantity, unitPrice);
		current++;
	}
	else
	{
		Item *temp = new Item[size * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = itemList[i];
		}
		size = size * 2;
		delete[] itemList;
		itemList = new Item[size];
		for (int i = 0; i < size; i++)
		{
			itemList[i] = temp[i];
		}
		delete[] temp;
		temp = 0;
		itemList[current] = Item(name, unitType, quantity, unitPrice);
		current++;
	}
}
/*********************************************************************  
** Function: removeItem
** Description: removeItem removes an item from itemList. Calls display
**   function and get user input for item number of corresponding number
*********************************************************************/
void List::removeItem()
{
	if (current == 0)
	{
		std::cout << "No items to remove\n";
	}
	else {
		int remove;
		displayList();
		std::cout << "Please select the item number you wish to remove ";
		std::cin >> remove;
		
		Item *temp = new Item[size];
		for (int i = 0; i < size; i++)
			temp[i] = itemList[i];
		for (int i = remove; i < size; i++)
			temp[i - 1] = itemList[i];
		for (int i = 0; i < size; i++)
			itemList[i] = temp[i];
		delete[] temp;
		current--;
	}
}
/*********************************************************************  
** Function:  dispayList
** Description: displayList displays the items inside of itemList
**		displayList also displays the total $$ amount
*********************************************************************/
void List::displayList()
{
	if (current == 0)
	{
		std::cout << "No items to display\n";
	}
	else {
		double itemsTotal = 0;
		std::cout << "   item           unit  quantity per item  total\n";
		for (int i = 0; i < current; i++)
		{
			std::cout << "#" << i + 1 << ". " << std::left << std::setw(15) << itemList[i].getName();
			std::cout << std::left << std::setw(8) << itemList[i].getUnitType();
			std::cout << std::left << std::setw(8) << itemList[i].getQuantity();
			std::cout << "$" << std::left << std::setw(4) << std::fixed << std::setprecision(2)
				<< itemList[i].getUnitPrice() << std::right << std::setw(4);
			std::cout << "$" << itemList[i].getTotal() << std::endl;
			itemsTotal = itemsTotal + itemList[i].getTotal();
		}
		std::cout << "The overall total is $" << itemsTotal << std::endl;
	}
}
/*********************************************************************
** Function:  menu
** Description: menu dispays options for user to select from
*********************************************************************/
void List::menu()
{
	std::cout << "\033[2J\033[1;1H" << std::endl;	//clears console before displaying next move
	std::cout << "*********************************\n";
	std::cout << "1. Add an item to the list      *\n";
	std::cout << "2. Remove an item from the list *\n";
	std::cout << "3. Display the list             *\n";
	std::cout << "4. Exit the program             *\n";
	std::cout << "*********************************\n";
	std::cout << "   Please make a selection: ";
}
