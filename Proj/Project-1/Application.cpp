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

	KillBill = new Movie("Kill Bill Vol. 1", "Action", 2004, 190, 100001, 5, 5);
	Annie = new Movie("Annie", "Family", 1982, 127, 22582, 15, 5);
	Interstellar = new Movie("Interstellar", "Adventure", 2014, 169, 96232, 20, 17);

	customer01 = new Customer("Dylan House", 10001);
	customer02 = new Customer("Susan House", 10002);

	store.addToInventory(KillBill);
	store.addToInventory(Annie);
	store.addToInventory(Interstellar);

	store.addCustomer(customer01);
	store.addCustomer(customer02);

	return true;
}

bool Application::update()
{
	interface.displayMainMenu();
	int selection = interface.getMenuSelection();
	
	switch (selection)
	{
	case 1:
		interface.printInventory(store);
		break;
	case 2:
		interface.printCustomers(store);
		break;
	case 3:
		interface.printMovie(store);
		break;
	case 4:
		interface.printCustomer(store);
		break;
	case 5:
		interface.displayCheckOut();
		break;
	case 6:
		interface.displayCheckIn();
		break;
	case 7:
		interface.printOverdue();
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
	delete customer01;
	delete customer02;
}

void Application::exit()
{
	RUNNING = false;
}