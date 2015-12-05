/***************************************************************************************************
Filename:			Item.cpp
Version:			1.0
Author:				Bryden Lacelle
Student Number:		040754048
Course Name:		C++ Programming CST8219
Lab Section:		301
Assignment Number:	1
Assignment Name:	FleaBay with Overloaded Operators
Due Date:			2015/11/08
Submission Date:	2015/11/09
Professor's Name:	Andrew Taylor
Purpose:			To manage the use of an Item object
***************************************************************************************************/
#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif // !IOSTREAM
#ifndef IOMANIP
#include <iomanip>
#define IOMANIP
#endif // !IOMANIP
using namespace std;
#ifndef ITEM_H
#include "Item.h"
#define ITEM_H
#endif // !ITEM_H

/*******************************************************************************
Function Name:		Item::Item
Purpose:			Constructor for a new Item
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Item::Item()
{
	description = NULL;
	price = 0.0;
}

/*******************************************************************************
Function Name:		Item::Item
Purpose:			Copy Constructor for an Item 
In Parameters		&item
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Item::Item(Item& item)
{
	description = new char[strlen(item.description) + 1];
	strcpy(description, item.description);
	price = item.price;
}

/*******************************************************************************
Function Name:		Item::Item
Purpose:			Constructor for a new Item with 2 parameters
In parameters		char*, double
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Item::Item(char* description, double price)
{
	Item::description = new char[strlen(description) + 1];
	strcpy(Item::description, description);
	Item::price = price;
}

/*******************************************************************************
Function Name:		operator<<
Purpose:			Overload the ostream << operator to print an item to the console
In Parameters:		ostream&, Item&
Out Parameters		ostream&
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
ostream& operator<<(ostream& stream, Item& item)
{
	stream << "   " << item.description << ", Cost = $" << setiosflags(ios::showpoint) << item.price << endl;
	return stream;
}
/*******************************************************************************
Function Name:		Item::~Item
Purpose:			Destructor for an Item
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Item::~Item()
{
	delete description;
}
