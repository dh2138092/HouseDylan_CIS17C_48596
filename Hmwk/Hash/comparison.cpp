#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>

#include "HashTable.h"

int linearSearch(unsigned short int integers[], int const SIZE, unsigned short int reference)
{
	for (int i = 0; i < SIZE; i++)
		if (reference == integers[i])
			return i;
	
	return -1;
}

int binarySearch(unsigned short int integers[], int const SIZE, unsigned short int reference)
{
	int low = 0;
	int high = SIZE - 1;

	while (low <= high) 
	{
		int mid = (low + high) / 2;
		if (integers[mid] > reference)
			high = mid - 1;
		else if (integers[mid] < reference)
			low = mid + 1;
		else
			return mid;
	}

	return -1;  
}

void quickSort(unsigned short int integers[], int left, int right) 
{
	int i = left, j = right;
	unsigned short int tmp;
	unsigned short int pivot = integers[(left + right) / 2];

	/* partition */
	while (i <= j) 
	{
		while (integers[i] < pivot)
			i++;

		while (integers[j] > pivot)
			j--;

		if (i <= j) 
		{
			tmp = integers[i];
			integers[i] = integers[j];
			integers[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quickSort(integers, left, j);
	if (i < right)
		quickSort(integers, i, right);
}

void linearSearchDemo()
{
	clock_t start, finish = 0;
	int const SIZE = 1000000;
	int searchResult = 0;
	unsigned short int *integers = new unsigned short int[SIZE];
	unsigned short int reference = rand() % 900000 + 100000;

	std::cout << "Reference value is " << reference << "\n\n";

	
	// Each element in the array is a 3-digit unsigned short integer
	for (int i = 0; i < SIZE; i++)
	{
		integers[i] = rand() % 900000 + 100000;
	}

	start = clock();
	searchResult = linearSearch(integers, SIZE, reference);
	finish = clock();

	std::cout << "*****Total LINEAR SEARCH time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s*****\n";

	if (searchResult >= 0)
		std::cout << "     Match found at index[" << searchResult << "]!\n\n";
	else
		std::cout << "     No match!\n\n";
		

	delete[] integers;
}

void binarySearchDemo()
{
	clock_t start, finish = 0;
	int const SIZE = 1000000;
	int searchResult = 0;
	unsigned short int integers[SIZE] = { 0 };
	unsigned short int reference = rand() % 900 + 100;

	// Each element in the array is a 3-digit unsigned short integer
	for (int i = 0; i < SIZE; i++)
	{
		integers[i] = rand() % 900 + 100;
	}

	quickSort(integers, 0, SIZE - 1);

	std::cout << "Sort complete.\n\n"
			  << "Now performing BINARY SEARCH. . .\n\n";

	start = clock();
	searchResult = binarySearch(integers, SIZE, reference);
	finish = clock();

	std::cout << "*****Total BINARY SEARCH time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s*****\n";

	if (searchResult >= 0)
		std::cout << "     Match found at index[" << searchResult << "]!\n\n";
	else
		std::cout << "     No match!\n\n";
}

void hashTableDemo()
{
	HashTable table;
	clock_t start, finish = 0;
	int const SIZE = 1000000;
	unsigned short int integers[SIZE] = { 0 };
	unsigned short int reference = rand() % 900 + 100;

	// Each element in the array is a 3-digit unsigned short integer
	for (int i = 0; i < SIZE; i++)
	{
		integers[i] = rand() % 900 + 100;
	}
}

int main(int argc, char *argv[])
{	
	srand((unsigned int)time(0));

	std::cout << "First up is LINEAR SEARCH.\n\n";

	linearSearchDemo();

	std::cout << "Next is BINARY SEARCH.\n\n";

	//binarySearchDemo();

	std::cout << "Last, but not least - HASH TABLE.\n\n";

	//hashTableDemo();
	
	return 0;
}
