#ifndef STORE
#define STORE

#include <iostream>
#include <set>
#include <list>
#include "Movie.h"
#include "Customer.h"

#include "HashTable.h"

class StoreManager
{
public:
	StoreManager();
	StoreManager(int size);
	~StoreManager();

	std::set<Movie *> getInventory() const;
	std::set<Customer *> getCustomers() const;
	HashTable* getEmployees() const;

	bool addToInventory(Movie *m);
	bool removeFromInventory(Movie *m);
	Movie* findMovie(int id);

	bool addCustomer(Customer *c);
	bool removeCustomer(Customer *c);
	Customer* findCustomer(int id);

	bool addEmployee(std::string name);
	bool removeEmployee(std::string name);
	std::string findEmployee(std::string name);

	bool checkIn(int customerId, int movieId);
	bool checkOut(int customerId, int movieId);

private:
	std::set<Movie *> inventory;
	std::set<Customer *> customers;
	HashTable *employees;
};

#endif