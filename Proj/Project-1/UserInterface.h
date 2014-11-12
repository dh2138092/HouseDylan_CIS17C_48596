#ifndef INTERFACE
#define INTERFACE

#include <iostream>

#include "StoreManager.h"

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void displayMainMenu();
	void printInventory(StoreManager store) const;
	void printCustomers(StoreManager store) const;
	void printMovie(StoreManager store) const;
	void printCustomer(StoreManager store) const;
	void displayCheckOut() const;
	void displayCheckIn() const;
	void printOverdue() const;

	int getMenuSelection();

private:
	int menuSelection;
};

#endif