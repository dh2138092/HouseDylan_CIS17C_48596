#include "StoreManager.h"

StoreManager::StoreManager()
{

}

StoreManager::~StoreManager()
{

}

std::set<Movie *> StoreManager::getInventory() const
{
	return inventory;
}

std::set<Customer *> StoreManager::getCustomers() const
{
	return customers;
}

bool StoreManager::addToInventory(Movie *m)
{
	inventory.insert(m);
	return true;
}

bool StoreManager::removeFromInventory(Movie *m)
{
	inventory.erase(inventory.find(m));
	return true;
}

Movie* StoreManager::findMovie(int id)
{
	for (std::set<Movie *>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		if (id == (*it)->getId())
			return *it;
	}

	return NULL;
}

bool StoreManager::addCustomer(Customer *customer)
{
	customers.insert(customer);
	return true;
}

bool StoreManager::removeCustomer(Customer *customer)
{
	customers.erase(customers.find(customer));
	return true;
}

Customer* StoreManager::findCustomer(int id)
{
	for (std::set<Customer *>::iterator it = customers.begin(); it != customers.end(); ++it)
	{
		if (id == (*it)->getId())
			return *it;
	}

	return NULL;
}

bool StoreManager::checkIn(Customer *customer, Movie *movie)
{
	customer->removeMovie(movie);
	movie->setInCount(movie->getInCount() + 1);
	movie->setOutCount(movie->getOutCount() - 1);
	return true;
}

bool StoreManager::checkOut(Customer *customer, Movie *movie)
{
	if (movie->getOutCount() == movie->getStockCount())
	{
		std::cout << movie->getTitle() << " is out of stock.\n"
			      << "Cannot add to customer # " << customer->getId() << "\n\n";
		return false;
	}
	else
	{
		customer->addMovie(movie);
		movie->setInCount(movie->getInCount() - 1);
		movie->setOutCount(movie->getOutCount() + 1);
		return true;
	}
}