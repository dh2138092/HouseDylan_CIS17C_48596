#ifndef APPLICATION
#define APPLICATION

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "UserInterface.h"

class Application
{
public:
	Application();

	int execute();
	bool initialize();
	bool update();
	void cleanup();
	void exit();

private:
	bool RUNNING;

	UserInterface interface;
	StoreManager store;

	// Hardcode a database of movies and customers
	// Didn't manage to get a basic .txt-based database to work in time
	Movie *KillBill;
	Movie *Annie;
	Movie *Interstellar;
	Customer *customer01;
	Customer *customer02;
};

#endif