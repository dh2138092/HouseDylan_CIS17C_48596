#ifndef INTERFACE
#define INTERFACE

#include <iostream>

#include "StoreManager.h"

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void printInventory(StoreManager m) const;
	void printCustomers() const;

	void printMovie(Movie m) const;
	void printCustomer(Customer c) const;
};

#endif