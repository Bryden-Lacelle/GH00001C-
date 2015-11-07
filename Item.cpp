/***************************************************************************************************
Filename:			Item.cpp
Version:			1.0
Author:				Bryden Lacelle
Student Number:		040754048
Course Name:		C++ Programming CST8219
Lab Section:		301
Assignment Number:	1
Assignment Name:	FleaBay in C++
Due Date:			2015/10/19
Submission Date:	2015/10/20
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
#ifndef ITEM_H
#include "Item.h"
#define ITEM_H
#endif // !ITEM_H
using namespace std;

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
Function Name:		Item::Report
Purpose:			Display all information for a single item
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
void Item::Report()
{
	cout << "   " << description << ", Cost = $" << setiosflags(ios::showpoint) << price << endl;
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