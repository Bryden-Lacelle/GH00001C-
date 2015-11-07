/***************************************************************************************************
Filename:			Account.cpp
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
Purpose:			To manage Account objects and add Items to Accounts
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
#ifndef ACCOUNT_H
#include "Account.h"
#define ACCOUNT_H
#endif // !ACCOUNT_H
#ifndef FLEA_H
#include "Fleabay.h"
#define FLEA_H
#endif // !ACCOUNT_H
using namespace std;

/*******************************************************************************
Function Name:		Account::Account
Purpose:			Constructor for a new Account
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Account::Account()
{
	Account::ID = NULL;
	Account::PassWord = NULL;
	Account::numItems = 0;
	Account::items = new pItem;
}

/*******************************************************************************
Function Name:		Account::AddItem
Purpose:			Add a(n) items(s) to an Account
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
void Account::AddItem()
{
	int maxIDSize = 50, i = -1;
	char tempChar, *pTempChar = new char[50]; // Allocate a temporary buffer for user input
	bool addNItem = true;
	ppItem oldItemList; // Create a new temporary ppItem 
	cout << "These are your current items for sale:" << endl;
	while(++i < numItems) 
	items[i]->Report();
	if (!numItems)
		cout << "**NO ITEMS FOUND**" <<  endl;
	while (addNItem)
	{
		cout << "Do you wish to add another Item (yes = 'Y', no = 'N'?" << endl;
		cin >> tempChar;
		i = -1; // Reset i
		switch(tempChar)
		{
		case 'N':
			addNItem = false;
			break;
		case 'Y':
			oldItemList = items; // Set pointer to the old list of pointers
			items = new pItem[numItems + 1]; // Allocate memory for a new list of pointers
			while (++i < numItems) { items[i] = oldItemList[i]; } // Copy the old list of pointers over to the newly allocated space in memory
			items[numItems] = new Item; // Allocate memory for a new Item
			cout << "Please enter new item description: ";
			cin.ignore();
			cin.get(pTempChar, maxIDSize);
			items[numItems]->description = new char[strlen(pTempChar) + 1]; // Allocate the exact amount of memory needed for the user's item description
			strcpy(items[numItems]->description, pTempChar);
			do // Loop until valid input is found
			{
				cin.clear(); // Reset error flags
				cout << "Please Enter the new item price: ";
				cin >> items[numItems]->price;
				cin.sync(); // Clear cin
			} while(cin.fail());
			++numItems; // Incriment the number of items stored in the database
			delete oldItemList; // Delete the old list of pointers
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}
	cout << "Exit";
	delete pTempChar; // Free the memory allocated for the buffer
}

/*******************************************************************************
Function Name:		Account::Report
Purpose:			Display all information for a single account
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
void Account::Report()
{
	int i = -1;
	cout << (!numItems ? "**NO ITEMS FOUND**" : "") << endl; // Return an error message if no items are found
	while(++i < numItems) // Incriment through all the stored account descriptions and prices and print them to the console
	{
		cout << "Item " << i << ":";
		items[i]->Report();
	}
}

/*******************************************************************************
Function Name:		Account::~Account
Purpose:			Destructor for an Account
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Account::~Account()
{
	int i = -1;
	delete ID;
	delete PassWord;
	while (++i < numItems)
		delete items[i];
	delete items;
}