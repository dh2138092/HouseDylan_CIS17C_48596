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
	// The plan was to read-in database files of movies and customers
	// instead of hardcoding them in this function, but I
	// ran out of time. It would have made the experience more seamless
	// because I also wanted to make it so that you could permanently add
	// and remove movies & customers from the database, so that when 
	// you restarted the application, the information was just as it was
	// when you left.

	store = StoreManager(4);

	KillBill = new Movie("Kill Bill Vol. 1", "Action", 2004, 190, 100001, 5, 5);
	Annie = new Movie("Annie", "Family", 1982, 127, 22582, 15, 5);
	Interstellar = new Movie("Interstellar", "Adventure", 2014, 169, 96232, 20, 17);
	Shawshank = new Movie("The Shawshank Redemption", "Crime Drama", 1994, 142, 56322, 5, 3);
	Godfather = new Movie("The Godfather", "Crime Drama", 1972, 175, 35252, 6, 18);
	Ikiru = new Movie("Ikiru", "Drama", 1956, 143, 64293, 5, 3);


	customer01 = new Customer("Dylan House", 10001);
	customer02 = new Customer("Susan House", 10002);

	store.addEmployee("Mark");
	store.addEmployee("Dylan");
	store.addEmployee("Robert");
	store.addEmployee("Susan");

	store.addToInventory(KillBill);
	store.addToInventory(Annie);
	store.addToInventory(Interstellar);
	store.addToInventory(Shawshank);
	store.addToInventory(Godfather);
	store.addToInventory(Ikiru);

	store.addCustomer(customer01);
	store.addCustomer(customer02);

	customer01->addMovie(Interstellar);
	customer02->addMovie(Annie);
	customer02->addMovie(Ikiru);

	return true;
}

bool Application::update()
{
	interface.displayMainMenu();

	int selection = interface.getMenuSelection();
	switch (selection)
	{
	case 1:
		system("cls");
		interface.printInventory(store);
		break;
	case 2:
		system("cls");
		interface.printCustomers(store);
		break;
	case 3:
		system("cls");
		interface.printMovie(store);
		break;
	case 4:
		system("cls");
		interface.printCustomer(store);
		break;
	case 5:
		system("cls");
		interface.displayCheckOut(store);
		break;
	case 6:
		system("cls");
		interface.displayCheckIn(store);
		break;
	case 7:
		system("cls");
		interface.printEmployees(store);
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