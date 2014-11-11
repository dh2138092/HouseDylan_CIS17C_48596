#include "StoreManager.h"

StoreManager::StoreManager()
{

}

StoreManager::~StoreManager()
{

}

std::set<Movie> StoreManager::getInventory() const
{
	return inventory;
}

bool StoreManager::addToInventory(Movie m)
{
	inventory.insert(m);
	return true;
}

bool StoreManager::removeFromInventory(Movie m)
{
	inventory.erase(inventory.find(m));
	return true;
}

bool StoreManager::addCustomer(Customer customer)
{
	customers.insert(customer);
	return true;
}

bool StoreManager::removeCustomer(Customer customer)
{
	customers.erase(customers.find(customer));
	return true;
}

bool StoreManager::checkIn(Customer customer, Movie movie)
{
	customer.removeMovie(movie);
	movie.setInCount(movie.getInCount() + 1);
	movie.setOutCount(movie.getOutCount() - 1);
	return true;
}

bool StoreManager::checkOut(Customer customer, Movie movie)
{
	if (movie.getOutCount() == movie.getStockCount())
	{
		printf("Movie is out of stock.");
		return false;
	}
	else
	{
		customer.addMovie(movie);
		movie.setInCount(movie.getInCount() - 1);
		movie.setOutCount(movie.getOutCount() + 1);
		return true;
	}
}

void StoreManager::printInventory() const
{
	std::cout << "             INVENTORY REPORT\n"
		<< "===========================================\n\n";

	for (std::set<Movie>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		it->printInfo();
	}
}

void StoreManager::printCustomers() const
{
	std::cout << "              CUSTOMER REPORT\n"
		      << "===========================================\n\n";

	for (std::set<Customer>::iterator cit = customers.begin(); cit != customers.end(); ++cit)
	{
		std::cout << "Name:  " << cit->getName() << '\n'
			      << "ID#:   " << cit->getId() << "\n\n";

		//cit->getMovies().begin()->printInfo();

		// Print every movie that the customer has currently checked-out
		/*for (std::set<Movie>::iterator it = cit->getMovies().begin(); it != cit->getMovies().end(); ++it)
		{
			it->printInfo();
		}*/
	}
}