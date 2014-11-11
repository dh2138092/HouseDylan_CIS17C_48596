#include "StoreManager.h"

int main(int argc, char* argv[])
{
	StoreManager store;

	Movie KillBill("Kill Bill Vol. 1", "Action", 2004, 190, 100001, 30, 10);
	Movie Interstellar("Interstellar", "Drama", 2014, 190, 10002, 10, 25);
	Movie Annie("Annie", "Family", 1939, 100, 10003, 14, 39);

	Customer customer01("Dylan House", 10001);
	Customer customer02("Susan", 10002);

	store.addToInventory(KillBill);
	store.addToInventory(Annie);
	store.addToInventory(Interstellar);
	store.addCustomer(customer01);
	store.addCustomer(customer02);

	store.printInventory();

	store.checkOut(customer01, Interstellar);
	store.checkOut(customer02, Annie);

	store.printInventory();
	store.printCustomers();

	return 0;
}