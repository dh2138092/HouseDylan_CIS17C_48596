#include "Application.h"

Application::Application()
{
	RUNNING = true;
}

int main(int argc, char* argv[])
{
	Application app;

	app.execute();

	return 0;
}

int Application::execute()
{
	if (initialize() == false)
		return -1;

	while (RUNNING)
		update();

	cleanup();

	return 0;
}

bool Application::initialize()
{
	std::cout << "\n Flicks-R-Us Store Management System\n\n";

	interface = new UserInterface();
	store = new StoreManager();

	KillBill = new Movie("Kill Bill Vol. 1", "Action", 2004, 190, 1, 5, 5);
	Annie = new Movie("Annie", "Family", 1982, 127, 2, 15, 5);
	Interstellar = new Movie("Interstellar", "Adventure", 2014, 169, 3, 20, 17);
	Shawshank = new Movie("The Shawshank Redemption", "Crime Drama", 1994, 142, 4, 5, 3);
	Godfather = new Movie("The Godfather", "Crime Drama", 1972, 175, 5, 6, 18);
	Ikiru = new Movie("Ikiru", "Drama", 1956, 143, 6, 5, 3);

	Dylan = new Customer("Dylan House", 1);
	Mark = new Customer("Mark Lehr", 2);

	store->addToInventory(KillBill);
	store->addToInventory(Annie);
	store->addToInventory(Interstellar);
	store->addToInventory(Shawshank);
	store->addToInventory(Godfather);
	store->addToInventory(Ikiru);

	store->addCustomer(Dylan->getId(), Dylan);
	store->addCustomer(Mark->getId(), Mark);

	Dylan->addMovie(Interstellar);
	Mark->addMovie(Annie);
	Mark->addMovie(Shawshank);

	return true;
}

bool Application::update()
{
	interface->displayMainMenu();

	int selection = interface->getMenuSelection();
	switch (selection)
	{
	case 1:
		interface->printInventory(*store);
		break;
	case 2:
		interface->printMovie(*store);
		break;
	case 3:
		interface->printCustomer(*store);
		break;
	case 4:
		interface->displayCheckOut(*store);
		break;
	case 5:
		interface->displayCheckIn(*store);
		break;
	case 0:
		exit();
		break;
	default:
		break;
	}

	return true;
}

void Application::cleanup()
{
	delete interface;
	delete store;

	delete KillBill;
	delete Annie;
	delete Interstellar;
	delete Shawshank;
	delete Godfather;
	delete Ikiru;

	delete Dylan;
	delete Mark;
}

void Application::exit()
{
	RUNNING = false;
}