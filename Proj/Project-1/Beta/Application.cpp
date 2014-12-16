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
	interface = new UserInterface();
	store = new StoreManager();

	KillBill = new Movie("Kill Bill Vol. 1", "Action", 2004, 190, 1, 5, 5);
	Annie = new Movie("Annie", "Family", 1982, 127, 2, 15, 5);
	Interstellar = new Movie("Interstellar", "Adventure", 2014, 169, 3, 20, 17);
	Shawshank = new Movie("The Shawshank Redemption", "Crime Drama", 1994, 142, 4, 5, 3);
	Godfather = new Movie("The Godfather", "Crime Drama", 1972, 175, 5, 6, 18);
	Ikiru = new Movie("Ikiru", "Drama", 1956, 143, 6, 5, 3);

	Movie testA("A", NULL, 0, 0, 1, 0, 0);
	Movie testB("B", NULL, 0, 0, 3, 0, 0);
	Movie testC("C", NULL, 0, 0, 5, 0, 0);

	if (testC > testB)
		std::cout << "True!\n";
	else
		std::cout << "False!\n";

	customer01 = new Customer("Dylan House", 01);
	customer02 = new Customer("Susan House", 02);

	store->addToInventory(KillBill);
	store->addToInventory(Annie);
	store->addToInventory(Interstellar);
	store->addToInventory(Shawshank);
	store->addToInventory(Godfather);
	store->addToInventory(Ikiru);

	store->addCustomer(customer01->getId(), customer01);
	store->addCustomer(customer02->getId(), customer02);

	customer01->addMovie(Interstellar);
	customer02->addMovie(Annie);
	customer02->addMovie(Ikiru);

	return true;
}

bool Application::update()
{
	interface->displayMainMenu();

	int selection = interface->getMenuSelection();
	switch (selection)
	{
	case 1:
		system("cls");
		interface->printInventory(*store);
		break;
	case 2:
		system("cls");
		interface->printMovie(*store);
		break;
	case 3:
		system("cls");
		interface->printCustomer(*store);
		break;
	case 4:
		system("cls");
		interface->displayCheckOut(*store);
		break;
	case 5:
		system("cls");
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

	delete customer01;
	delete customer02;
}

void Application::exit()
{
	RUNNING = false;
}