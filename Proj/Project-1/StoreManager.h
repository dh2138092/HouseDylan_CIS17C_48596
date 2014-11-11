#ifndef STORE
#define STORE

#include <iostream>
#include <set>
#include "Movie.h"
#include "Customer.h"

class StoreManager
{
public:
	StoreManager();
	~StoreManager();

	std::set<Movie> getInventory() const;

	bool addToInventory(Movie m);
	bool removeFromInventory(Movie m);

	bool addCustomer(Customer c);
	bool removeCustomer(Customer c);

	bool checkIn(Customer c, Movie m);
	bool checkOut(Customer c, Movie m);

	void printInventory() const;
	void printCustomers() const;

private:
	std::set<Movie> inventory;
	std::set<Customer> customers;
};

#endif