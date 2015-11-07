/***************************************************************************************************
Filename:			FleaBay.cpp
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
Purpose:			To register a list of users to the online service Fleabay
***************************************************************************************************/
#ifndef IOSTREAM
#include <iostream>
#define IOSTREAM
#endif // !IOSTREAM
#ifndef ITEM_H
#include "Item.h"
#define ITEM_H
#endif // !ITEM_H
#ifndef ACCOUNT_H
#include "Account.h"
#define ACCOUNT_H
#endif // !ACCOUNT_H
#ifndef FLEA_H
#include "FleaBay.h"
#define FLEA_H
#endif // !FLEA_H
using namespace std;

/*******************************************************************************
Function Name:		FleaBay::FleaBay
Purpose:			Constructor for a new FleaBay
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
FleaBay::FleaBay()
{
	FleaBay::numAccounts = 0;
	FleaBay::accounts = new pAccount;
}

/*******************************************************************************
Function Name:		FleaBay::Login
Purpose:			Login to an existing FleaBay Account
Out Parameters:		bool
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
bool FleaBay::Login()
{
	int maxIDSize = 50, i = -1;
	char* tempID, *tempPass;
	bool fbLogin = true;
	char i_response;
	if (!numAccounts)
		cout << "**NO ACCOUNTS**" << endl;
	while (fbLogin) // Prompt the user to add a new account, login to an account, or return to the main menu
	{
		cout << "1: Add a new account" << endl;
		cout << "2: Open an existing account" << endl;
		cout << "3: Return to Main Menu" << endl;
		cin>>i_response;
		switch(i_response)
		{
		case '1':
			AddNewAccount();
			return true;
		case '2':
			tempID = new char[maxIDSize];
			tempPass = new char[maxIDSize];
			cout << "Please enter your account ID: ";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> tempID;
			while (++i < numAccounts)
				{
					// Check if the ID is not valid
					if (!strcmp(tempID, accounts[i]->ID))
						break; // Exit loop when match is found
					else if (i == numAccounts - 1) // Iterated through all the IDs and no match is found
					{
						cout << tempID << " is an invalid ID" << endl;
						delete(tempID);
						delete(tempPass);
						return 1;
					}
				}
			i = -1; // Reset i
			cout << "Please enter your account Password: ";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> tempPass;
			while (++i < numAccounts)
				{
					// Check if the password matches to the ID
					if (!strcmp(tempID, accounts[i]->ID) && !strcmp(tempPass, accounts[i]->PassWord))
					{
						delete tempID;
						delete tempPass;
						accounts[i]->AddItem();
						return true;
					}
				}
			cout << "Password doesn't match this ID" << tempPass << endl;
			delete tempID;
			delete tempPass;
			return true;
		case '3':
			return true;
		}
	}
	return true;
}

/*******************************************************************************
Function Name:		FleaBay::AddNewAccount
Purpose:			Add a new Account to the database
Out Parameters:		bool
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
bool FleaBay::AddNewAccount()
{
	int maxIDSize = 50, i = -1;
	char* tempString = new char[maxIDSize]; // Allocate a temporary buffer for user input
	ppAccount oldList; // Create a new temporary FleaBay 
	cout << "Please Enter your account ID" << endl;
	cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin >> tempString; // Get user ID
	while (++i < numAccounts) // Loop through all the accounts in the database to make ensure the ID is unique
	{
		if (!strcmp(tempString, accounts[i]->ID)) // Compare user input with currently known IDs
		{
			cout << "is an invalid ID" << tempString; // If a match is found print an error and return to the main menu
			delete tempString;
			return true;
		}
	}
	i = -1; // Reset i for later use
	oldList = accounts; // Copy the old list of pointers to pAccounts to the temp FleaBay
	accounts = new pAccount[numAccounts + 1]; // Allocate memory for a new list of pointers
	while (++i < numAccounts) { accounts[i] = oldList[i]; } // Copy the old list of pointers over to the newly allocated space in memory
	accounts[numAccounts] = new (Account); // Allocate memory for a new Account
	accounts[numAccounts]->ID = new char[strlen(tempString) + 1]; // Allocate the exact amount of memory needed for the user's ID
	strcpy(accounts[numAccounts]->ID, tempString);

	cout << "Please Enter your account password" << endl;
	cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin >> tempString; // Get the users password
	accounts[numAccounts]->PassWord = new char[strlen(tempString) + 1]; // Allocate the exact amount of memory needed for the user's password
	strcpy(accounts[numAccounts]->PassWord, tempString);

	++numAccounts; // Incriment the number of accounts stored in the database
	delete tempString; // Free the memory allocated for the buffer
	delete oldList;
	return true;
}

/*******************************************************************************
Function Name:		FleaBay::
Purpose:			Display all information stored in a FleaBay
Out Parameters:		bool
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
bool FleaBay::Report()
{
	int i = -1;
	cout << (!numAccounts ? "**NO ACCOUNTS FOUND**" : "") << endl; // Return an error message if no accounts are found
	while(++i < numAccounts) // Incriment through all the stored account IDs and print them to the console
	{
		cout << "Account ID: " << accounts[i]->ID << endl;
		accounts[i]->Report();
	}
	return true;
}

/*******************************************************************************
Function Name:		FleaBay::~FleaBay
Purpose:			Destructor for a FleaBay
Version:			1.0
Author:				Bryden Lacelle
*******************************************************************************/
FleaBay::~FleaBay()
{
	int i = numAccounts;
	while (--i >= 0)
		delete accounts[i];
	delete []accounts;
}