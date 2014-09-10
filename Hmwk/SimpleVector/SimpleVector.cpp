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
<<<<<<< HEAD
	SimpleVector<int> list(size);

	// Initialze starting vector
	std::cout << "Initializing a vector of size " << size << " with random 1-digit integers...\n\n";
	for (int i = 0; i < size; i++)
=======
	SimpleVector<int> list (size);

	// Initialze starting vector
	std::cout << "Initializing a vector of size " << size << " with random 1-digit integers...\n\n";
	for ( int i = 0; i < size; i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
	{
		list[i] = rand() % 9 + 2;
	}

	// Print starting vector to show its contents
<<<<<<< HEAD
	for (int i = 0; i < list.size(); i++)
=======
	for ( int i = 0; i < list.size(); i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
	{
		std::cout << list.getElementAt(i) << " ";
	}

	std::cout << endl << endl;

	std::cout << "==================================\n"
<<<<<<< HEAD
		<< "Demonstrating SimpleVector::push()\n"
		<< "==================================\n\n";

	// Push howManyToPush number of elements into the vector
	for (int i = 0; i < howManyToPush; i++)
=======
			  << "Demonstrating SimpleVector::push()\n"
			  << "==================================\n\n";

	// Push howManyToPush number of elements into the vector
	for ( int i = 0; i < howManyToPush; i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
	{
		// Pushing a random number into the vector
		randomNum = rand() % 200 + 2;
		std::cout << "Pushing:               " << randomNum << endl;
		list.push(randomNum);
		std::cout << "Vector's new size:     " << list.size() << endl;
		std::cout << "Vector's new capacity: " << list.capacity() << endl;
		std::cout << "Vector's new list:     ";
<<<<<<< HEAD
		for (int i = 0; i < list.size(); i++)
=======
		for ( int i = 0; i < list.size(); i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
		{
			std::cout << list.getElementAt(i) << " ";
		}

		std::cout << endl << endl;
	}

	std::cout << endl << endl << endl;

	std::cout << "==================================\n"
<<<<<<< HEAD
		<< "Demonstrating SimpleVector::pull()\n"
		<< "==================================\n\n";

	for (int i = 0; i < list.size(); i++)
=======
			  << "Demonstrating SimpleVector::pull()\n"
			  << "==================================\n\n";

	for ( int i = 0; i < list.size(); i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
	{
		std::cout << list.getElementAt(i) << " ";
	}

	std::cout << endl << endl;

	howManyToPull = list.size();
<<<<<<< HEAD
	for (int i = 0; i < howManyToPull; i++)
=======
	for ( int i = 0; i < howManyToPull; i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
	{
		std::cout << "Pulling:               " << list.getElementAt(list.size() - 1) << endl;
		list.pull();
		std::cout << "Vector's new size:     " << list.size() << endl;
		std::cout << "Vector's new capacity: " << list.capacity() << endl;
		std::cout << "Vector's new list:     ";
<<<<<<< HEAD
		for (int i = 0; i < list.size(); i++)
=======
		for ( int i = 0; i < list.size(); i++ )
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
		{
			std::cout << list.getElementAt(i) << " ";
		}

		std::cout << endl << endl;
	}

	std::cout << endl << endl;

	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
