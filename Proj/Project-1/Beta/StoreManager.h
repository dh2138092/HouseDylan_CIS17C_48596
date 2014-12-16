#ifndef STORE
#define STORE

#include <iostream>
#include <set>
#include "Movie.h"
#include "Customer.h"
#include "HashTable.h"

class StoreManager
{
public:
	StoreManager();
	~StoreManager();

	std::set<Movie *> getInventory() const;
	HashTable<Customer *>* getCustomers() const;

	bool addToInventory(Movie *m);
	bool removeFromInventory(Movie *m);
	Movie* findMovie(int id);

	bool addCustomer(int phoneNumber, Customer *c);
	bool removeCustomer(int phoneNumber);
	Customer* findCustomer(int phoneNumber);

	bool checkIn(int customerPhoneNumber, int movieId);
	bool checkOut(int customerPhoneNumber, int movieId);

private:
	std::set<Movie *> inventory;
	HashTable<Customer *> *customers;
};

#endif