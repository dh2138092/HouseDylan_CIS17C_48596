#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "HashTable.h"

template <class T>
int linearSearch(T data[], int const SIZE, T reference)
{
	for (int i = 0; i < SIZE; i++)
		if (reference == data[i])
			return i;

	return -1;
}

template <class T>
int binarySearch(T data[], int const SIZE, T reference)
{
	int low = 0;
	int high = SIZE - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (data[mid] > reference)
			high = mid - 1;
		else if (data[mid] < reference)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

template <class T>
void quickSort(T data[], int left, int right)
{
	int i = left, j = right;
	T tmp;
	T pivot = data[(left + right) / 2];

	/* partition */
	while (i <= j)
	{
		while (data[i] < pivot)
			i++;

		while (data[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quickSort(data, left, j);
	if (i < right)
		quickSort(data, i, right);
}

void linearSearchDemo()
{
	clock_t start, finish = 0;
	int const SIZE = 100000000;
	int *integers = new int[SIZE];
	int reference = 0;

	std::cout << "Reference value is " << reference << "\n\n";


	// Each element in the array is a 3-digit unsigned short integer
	for (int i = 0; i < SIZE; i++)
	{
		integers[i] = rand() % 900000 + 100000;
	}

	start = clock();
	linearSearch(integers, SIZE, reference);
	finish = clock();

	std::cout << "*****Total LINEAR SEARCH time: " 
			  << (double)(finish - start) / CLOCKS_PER_SEC 
			  << "s*****\n";

	delete[] integers;
}

void binarySearchDemo()
{
	clock_t start, finish = 0;
	int const SIZE = 100000000;
	int *integers = new int[SIZE];
	int reference = 0;

	std::cout << "Reference value is " << reference << "\n\n";


	// Each element in the array is a 3-digit unsigned short integer
	for (int i = 0; i < SIZE; i++)
	{
		integers[i] = rand() % 900000 + 100000;
	}

	std::cout << "First I have to sort this data. . .\n\This may take a few seconds. . .\n";

	quickSort(integers, 0, SIZE - 1);

	std::cout << "Sort complete.\n\n"
			  << "Now performing BINARY SEARCH. . .\n\n";

	start = clock();
	binarySearch(integers, SIZE, reference);
	finish = clock();

	std::cout << "*****Total BINARY SEARCH time: " 
			  << (double)(finish - start) / CLOCKS_PER_SEC 
			  << "s*****\n";

	delete[] integers;
}

void hashTableDemo()
{
	HashTable table;
	clock_t start, finish = 0;
	int const SIZE = 1000000;
	int *integers = new int[SIZE];
	int reference = 0;

	std::cout << "Reference value is " << reference << "\n\n";
	
	// Each element in the array is a 3-digit unsigned short integer
	for (int i = 0; i < SIZE; i++)
	{
		integers[i] = rand() % 900000 + 100000;
	}

	for (int i = 0; i < SIZE; i++)
	{
		table.put(i, integers[i]);
	}

	start = clock();
	table.get(reference);
	finish = clock();

	std::cout << "*****Total HASH SEARCH time: "
		<< (double)(finish - start) / CLOCKS_PER_SEC
		<< "s*****\n";

	delete[] integers;
}

int main(int argc, char** argv)
{
	srand(time(NULL));

	std::cout << "I'm going to compare worst case scenarios\n"
		<< "for linear search, binary search, and hash table.\n"
		<< "Worst case meaning no match is found, so each search\n"
		<< "function will have to run from end to end with its data set.\n"
		<< "Data table size is 1000000 integers.\n";

	std::cout << "\n===============\nFirst up is LINEAR SEARCH.\n===============\n";

	linearSearchDemo();

	std::cout << "\n===============\nNext is BINARY SEARCH.\n===============\n";

	binarySearchDemo();

	std::cout << "\n===============\nLast, but not least - HASH TABLE.\n===============\n";

	hashTableDemo();

	std::cout << "\n\n";

	return 0;
}