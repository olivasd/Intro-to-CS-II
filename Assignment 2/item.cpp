/*********************************************************************
** Program Filename: item.cpp
** Author: Daniel Olivas
** Date: 10/24/2016
** Description: item.cpp has the Item class that has the members of
**				that are used in itemList array in List class
*********************************************************************/

#include "item.hpp"
#include <iostream>

//default constructor
Item::Item()
{
	name = " ";
	unitType = " ";
	quantity = 0;
	unitPrice = 0.0;
}
//constructor
Item::Item(std::string newName, std::string newUnitType, int newQuantity, double newUnitPrice)
{
	name = newName;
	unitType = newUnitType;
	quantity = newQuantity;
	unitPrice = newUnitPrice;
}
//setters and getters
void Item::setName(std::string newName)
{
	name = newName;
}

void Item::setUnitType(std::string newUnitType)
{
	unitType = newUnitType;
}

void Item::setQuantity(int newQuantity)
{
	quantity = newQuantity;
}

void Item::setUnitPrice(double newUnitPrice)
{
	unitPrice = newUnitPrice;
}

std::string Item::getName()
{
	return name;
}

std::string Item::getUnitType()
{
	return unitType;
}

int Item::getQuantity()
{
	return quantity;
}

double Item::getUnitPrice()
{
	return unitPrice;
}

double Item::getTotal()
{
	return quantity * unitPrice;
}
