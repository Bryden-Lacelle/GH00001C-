/***************************************************************************************************
Filename:			Account.cpp
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
using namespace std;
#ifndef ITEM_H
#include "Item.h"
#define ITEM_H
#endif // !ITEM_H
#ifndef ACCOUNT_H
#include "Account.h"
#define ACCOUNT_H
#endif // !ACCOUNT_H

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
	Account::items = NULL;
}

/*******************************************************************************
Function Name:		Account::Account
Purpose:			Copy Constructor for an Account
In Parameters:		Account&
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Account::Account(Account& account)
{
	int i = -1;
	ID = new char[strlen(account.ID) + 1]; // Allocate memory for ID
	strcpy(ID, account.ID); // Copy ID
	PassWord = new char[strlen(account.PassWord) + 1];
	strcpy(PassWord, account.PassWord);
	numItems = account.numItems;
	items = new pItem[numItems]; // Allocate memory for items
	while (++i < account.numItems) { items[i] = new Item(*account.items[i]); } // Copy Items
}

/*******************************************************************************
Function Name:		Account::Account
Purpose:			Overloaded Constructor for a new Account
In Parameters:		char*, char*
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
Account::Account(char* ID, char* password)
{
	Account::ID = new char[strlen(ID) + 1];
	Account::PassWord = new char[strlen(password) + 1];
	strcpy(Account::ID, ID);
	strcpy(Account::PassWord, password);
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
	char* description;
	double price;
	char tempChar, *pTempChar = new char[50]; // Allocate a temporary buffer for user input
	bool addNItem = true;
	ppItem oldItemList; // Create a new temporary ppItem 
	cout << "These are your current items for sale:" << endl;
	while(++i < numItems) 
		cout << *items[i];
	if (!numItems)
		cout << "**NO ITEMS FOUND**" <<  endl;
	while (addNItem)
	{
		cout << "Do you wish to change a password (yes = 'P')?" << endl;
		cout << "Do you wish to add another Item (yes = 'Y')?" << endl;
		cout << "Want to quit this menu (yes = 'Q')?" << endl;
		cin >> tempChar;
		i = -1; // Reset i
		switch(tempChar)
		{
		case 'Q':
			addNItem = false;
			break;
		case 'Y':
			oldItemList = items; // Set pointer to the old list of pointers
			items = new pItem[numItems + 1]; // Allocate memory for a new list of pointers
			while (++i < numItems) { items[i] = oldItemList[i]; } // Copy the old list of pointers over to the newly allocated space in memory
			cout << "Please enter new item description: ";
			cin.ignore();
			cin.getline(pTempChar, maxIDSize);
			description = new char[strlen(pTempChar) + 1]; // Allocate the exact amount of memory needed for the user's item description
			strcpy(description, pTempChar);
			do // Loop until valid input is found
			{
				cin.clear(); // Reset error flags
				cout << "Please Enter the new item price: ";
				cin >> price;
				cin.sync(); // Clear cin
			} while(cin.fail());
			items[numItems] = new Item(description, price); //Create a new item
			++numItems; // Incriment the number of items stored in the database
			delete oldItemList; // Delete the old list of pointers
			delete description;
			break;
		case 'P':
			cout << "Please enter a new password: ";
			cin.ignore();
			cin.getline(pTempChar, maxIDSize);
			delete PassWord; // delete old Password
			PassWord = new char[strlen(pTempChar) + 1]; // Allocate memory for new password
			strcpy(PassWord, pTempChar); // Copy password to PassWord
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}
	cout << "Exit";
	delete pTempChar; // Free the memory allocated for the buffer
}

/*******************************************************************************
Function Name:		Account::getPassword
Purpose:			Return value of password
Out Parameters:		char*
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
char*& Account::getPassWord()
{
	return PassWord;
}

/*******************************************************************************
Function Name:		operator<<
Purpose:			Overload the ostream << operator to print an account to the console
In Parameters:		ostream&, Account&
Out Parameters		ostream&
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
ostream& operator<<(ostream& stream, Account& account)
{
	int i = -1;
	stream << "Account ID: " << account.ID << endl;
	while(++i < account.numItems) // Incriment through all the stored account descriptions and prices and print them to the console
	{
		stream << "Item " << i << ":" << *account.items[i];
	}
	return stream;
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
