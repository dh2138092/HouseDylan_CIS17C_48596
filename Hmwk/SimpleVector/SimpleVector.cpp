#include "SimpleVector.h"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
	///////////////////////////////////////////////////////
	// main() is used to demonstrate SimpleVector class //
	///////////////////////////////////////////////////////

	srand(static_cast<int> (time(0)));
	int size = 10;
	int howManyToPush = 5;
	int howManyToPull = 0;
	int randomNum = 0;
	SimpleVector<int> list(size);

	// Initialze starting vector
	std::cout << "Initializing a vector of size " << size << " with random 1-digit integers...\n\n";
	for (int i = 0; i < size; i++)
	{
		list[i] = rand() % 9 + 2;
	}

	// Print starting vector to show its contents
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list.getElementAt(i) << " ";
	}

	std::cout << endl << endl;

	std::cout << "==================================\n"
		<< "Demonstrating SimpleVector::push()\n"
		<< "==================================\n\n";

	// Push howManyToPush number of elements into the vector
	for (int i = 0; i < howManyToPush; i++)
	{
		// Pushing a random number into the vector
		randomNum = rand() % 200 + 2;
		std::cout << "Pushing:               " << randomNum << endl;
		list.push(randomNum);
		std::cout << "Vector's new size:     " << list.size() << endl;
		std::cout << "Vector's new capacity: " << list.capacity() << endl;
		std::cout << "Vector's new list:     ";
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << list.getElementAt(i) << " ";
		}

		std::cout << endl << endl;
	}

	std::cout << endl << endl << endl;

	std::cout << "==================================\n"
		<< "Demonstrating SimpleVector::pull()\n"
		<< "==================================\n\n";

	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list.getElementAt(i) << " ";
	}

	std::cout << endl << endl;

	howManyToPull = list.size();
	for (int i = 0; i < howManyToPull; i++)
	{
		std::cout << "Pulling:               " << list.getElementAt(list.size() - 1) << endl;
		list.pull();
		std::cout << "Vector's new size:     " << list.size() << endl;
		std::cout << "Vector's new capacity: " << list.capacity() << endl;
		std::cout << "Vector's new list:     ";
		for (int i = 0; i < list.size(); i++)
		{
			std::cout << list.getElementAt(i) << " ";
		}

		std::cout << endl << endl;
	}

	std::cout << endl << endl;

	return 0;
}