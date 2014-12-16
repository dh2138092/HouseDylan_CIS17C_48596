#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{

}

void UserInterface::displayMainMenu()
{
	std::cout << "1. Display Movie Inventory\n"
			  << "2. Lookup Movie\n"
			  << "3. Lookup Customer\n"
			  << "4. Check-Out Movie for Customer\n"
			  << "5. Check-In Movie from Customer\n\n"
			  << "0. Exit Store Management System\n\n"
			  << "       Option : ";
}

void UserInterface::printInventory(StoreManager store) const
{
	std::set<Movie *> inventory = store.getInventory();

	std::cout << "             INVENTORY REPORT\n"
		<< "===========================================\n\n";

	for (std::set<Movie *>::iterator it = inventory.begin(); it != inventory.end(); ++it)
		(*it)->printInfo();
}

void UserInterface::printMovie(StoreManager store) const
{
	int id = 0;
	std::cout << "Enter movie ID# : ";
	std::cin >> id;
	std::cout << "\n\n";

	Movie *movie = store.findMovie(id);

	if (store.findMovie(id) != NULL)
		movie->printInfo();
	else
		std::cout << "Movie not found.\n\n";
}

void UserInterface::printCustomer(StoreManager store) const
{
	int phoneNumber = 0;
	std::cout << "Enter customer's phone #: ";
	std::cin >> phoneNumber;
	std::cout << "\n\n";

	Customer *customer = store.findCustomer(phoneNumber);

	if (customer != NULL)
		customer->printInfo();
	else
		std::cout << "Customer not found.\n\n";
}

void UserInterface::displayCheckOut(StoreManager store) const
{
	int phoneNumber = 0;
	int movieId = 0;
	std::cout << "Customer phone # : ";
	std::cin >> phoneNumber;
	std::cout << "Movie ID# : ";
	std::cin >> movieId;

	store.checkOut(phoneNumber, movieId);
}

void UserInterface::displayCheckIn(StoreManager store) const
{
	int customerId = 0;
	int movieId = 0;
	std::cout << "Customer ID# : ";
	std::cin >> customerId;
	std::cout << "Movie ID# : ";
	std::cin >> movieId;

	store.checkIn(customerId, movieId);
}

int UserInterface::getMenuSelection()
{
	std::cin >> menuSelection;

	std::cout << '\n';

	return menuSelection;
}