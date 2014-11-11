#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{

}

void UserInterface::printInventory(StoreManager inventory) const
{
	for (std::set<Movie>::iterator it = inventory.getInventory().begin(); it != inventory.getInventory().end(); ++it)
	{
		std::cout << "Title: " << it->getTitle() << '\n'
			<< "Genre: " << it->getGenre() << '\n'
			<< "Length: " << it->getLength() << '\n'
			<< "ID: " << it->getId() << '\n'
			<< "Stock: " << it->getStockCount() << '\n';
	}
}

void UserInterface::printCustomers() const
{

}

void UserInterface::printMovie(Movie movie) const
{

}

void UserInterface::printCustomer(Customer customer) const
{

}