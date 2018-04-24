/*********************************************************************
** Program Filename: main.cpp
** Author: Daniel Olivas
** Date: 10/24/16
** Description: main.cpp creates an instance of List and has a do-while
**			loop to receive user selection from menu options
*********************************************************************/
#include "list.hpp"
#include "item.hpp"
#include <iostream>

int main(){
	
	List list;
	char select;

	do {
		list.menu();
		std::cin >> select;
		switch (select) {
		case '1':
			std::cout << "\033[2J\033[1;1H" << std::endl;	//clears console before displaying next move
			list.addItem();
			break;
		case '2':
			std::cout << "\033[2J\033[1;1H" << std::endl;	//clears console before displaying next move
			list.removeItem();
			break;
		case '3':
			list.displayList();
			std::cout << "\nPress any key and enter to go back to menu ";
			char z;
			std::cin >> z;
			std::cout << "\033[2J\033[1;1H" << std::endl;	//clears console before displaying next move
			break;
		case '4':
			break;
		default:
			std::cout << "invalid selection\n";
		}
	} while (select != '4');
	
	return 0;
}