/*********************************************************************
** Program Filename: item.hpp
** Author: Daniel Olivas
** Date: 10/24/2016
** Description: item.hpp has the Item class that has the members of
**				that are used in itemList array in List class
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item {
private:
	std::string name;
	std::string unitType;
	int quantity;
	double unitPrice;
	double total;
public:
	//default constructor
	Item();
	//construcor
	Item(std::string, std::string, int, double);
	//setters and getters
	void setName(std::string);
	void setUnitType(std::string);
	void setQuantity(int);
	void setUnitPrice(double);
	std::string getName();
	std::string getUnitType();
	int getQuantity();
	double getUnitPrice();
	double getTotal();
};

#endif // !ITEM_HPP

