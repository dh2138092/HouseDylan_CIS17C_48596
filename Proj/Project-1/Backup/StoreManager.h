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

	std::set<Movie *> getInventory() const;
	std::set<Customer *> getCustomers() const;

	bool addToInventory(Movie *m);
	bool removeFromInventory(Movie *m);
	Movie* findMovie(int id);

	bool addCustomer(Customer *c);
	bool removeCustomer(Customer *c);
	Customer* findCustomer(int id);

	bool checkIn(int customerId, int movieId);
	bool checkOut(int customerId, int movieId);

private:
	std::set<Movie *> inventory;
	std::set<Customer *> customers;
};

#endif