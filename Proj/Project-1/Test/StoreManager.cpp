#include "StoreManager.h"

StoreManager::StoreManager(int size)
{
	employees = new HashTable(size);
}

StoreManager::StoreManager()
{

}

StoreManager::~StoreManager()
{
	//delete employees;
	employees = NULL;
}

std::set<Movie *> StoreManager::getInventory() const
{
	return inventory;
}

std::set<Customer *> StoreManager::getCustomers() const
{
	return customers;
}

HashTable* StoreManager::getEmployees() const
{
	return employees;
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

bool StoreManager::addEmployee(std::string name)
{
	employees->insert(name);

	return true;
}

bool StoreManager::removeEmployee(std::string name)
{
	employees->remove(name);

	return true;
}

std::string StoreManager::findEmployee(std::string name)
{
	employees->find(name);

	return name;
}

bool StoreManager::checkIn(int customerId, int movieId)
{
	Customer *customer = findCustomer(customerId);
	Movie *movie = findMovie(movieId);

	if (customer == NULL)
		std::cout << "Customer not found.\n\n";

	if (movie == NULL)
		std::cout << "Movie not found.\n\n";

	if (customer == NULL || movie == NULL)
		return false;

	std::list<Movie *> movies = customer->getMovies();

	for (std::list<Movie *>::const_iterator it = movies.begin(); it != movies.end(); ++it)
	{
		if (*it == movie)
		{
			customer->removeMovie(movie);
			movie->setInCount(movie->getInCount() + 1);
			movie->setOutCount(movie->getOutCount() - 1);
			return true;
		}
	}

	std::cout << "That movie was not found in customer's profile.\n\n";

	return false;

}

bool StoreManager::checkOut(int customerId, int movieId)
{
	Customer *customer = findCustomer(customerId);
	Movie *movie = findMovie(movieId);

	if (customer == NULL)
		std::cout << "Customer not found.\n\n";

	if (movie == NULL)
		std::cout << "Movie not found.\n\n";

	if (customer == NULL || movie == NULL)
		return false;
	else
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
}