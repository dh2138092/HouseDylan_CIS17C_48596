#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{

}

void UserInterface::displayMainMenu() 
{
	std::cout << "1. Total Inventory\n"
		      << "2. All Customers\n"
		      << "3. Lookup Movie\n"
		      << "4. Lookup Customer\n"
		      << "5. Check-Out Movie\n"
		      << "6. Check-In Movie\n"
			  << "7. Print Employees\n"
		      << "0. Exit\n\n"
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

void UserInterface::printCustomers(StoreManager store) const
{
	std::set<Customer *> customers = store.getCustomers();

	std::cout << "              CUSTOMER REPORT\n"
		      << "===========================================\n\n";

	for (std::set<Customer *>::iterator it = customers.begin(); it != customers.end(); ++it)
		(*it)->printInfo();
}

void UserInterface::printEmployees(StoreManager store) const
{
	HashTable *employees = store.getEmployees();

	employees->printData();	
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
	int id = 0;
	std::cout << "Enter customer ID# : ";
	std::cin >> id;
	std::cout << "\n\n";

	Customer *customer = store.findCustomer(id);

	if (store.findCustomer(id) != NULL)
		customer->printInfo();
	else
		std::cout << "Customer not found.\n\n";
}

void UserInterface::displayCheckOut(StoreManager store) const
{
	int customerId = 0;
	int movieId = 0;
	std::cout << "Customer ID# : ";
	std::cin >> customerId;
	std::cout << "Movie ID# : ";
	std::cin >> movieId;

	store.checkOut(customerId, movieId);
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