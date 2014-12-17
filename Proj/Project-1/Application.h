#ifndef APPLICATION
#define APPLICATION

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

#include "UserInterface.h"
#include "HashTable.h"

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

	UserInterface *interface;
	StoreManager *store;

	// Hardcode a database of movies and customers
	// Didn't manage to get a basic .txt-based database to work in time
	Movie *KillBill;
	Movie *Annie;
	Movie *Interstellar;
	Movie *Shawshank;
	Movie *Godfather;
	Movie *Ikiru;
	Customer *Dylan;
	Customer *Mark;
};

#endif