#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>

#include "HashTable.h"

int linearSearch(std::string *sArray, int const SIZE, std::string val)
{
	for (int i = 0; i < SIZE; i++)
		if (val == sArray[i]) 
			return i;
	
	return -1;
}

int binarySearch(std::string *sArray, int const SIZE, std::string val)
{
	int low = 0;
	int high = SIZE - 1;

	while (low <= high) 
	{
		int mid = (low + high) / 2;
		if (sArray[mid] > val)
			high = mid - 1;
		else if (sArray[mid] < val)
			low = mid + 1;
		else
			return mid;
	}

	return -1;  
}

void quickSort(std::string *arr, int left, int right) 
{
	int i = left, j = right;
	std::string tmp;
	std::string pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) 
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) 
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main(int argc, char *argv[])
{	
	srand((unsigned int)time(0));
	clock_t start, finish = 0;
	int searchResult = 0;

	int const numOfCharacters = 20;
	int const SIZE = 10000;
	std::string *sArray = new std::string[SIZE];
	std::string sComparable = "";

	HashTable hash;

	// Create one random string of numOfCharacters.
	// This is going to be what we're searching for.
	for (int i = 0; i < numOfCharacters; i++)
	{
		char mChar = 'A' + rand() % 26;
		sComparable += mChar;
	}

	std::cout << "Going to search for " << sComparable << ". . .\n\n"
		      << "First I need to create a random array (of size " << SIZE << ") of strings"
			  << "\nwhere each string has " << numOfCharacters << " characters. . .\n\n";

	// Create a random array of strings. Array size = SIZE
	// and each row contains numOfCharacters.
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < numOfCharacters; j++)
		{
			char mChar = 'A' + rand() % 26;
			sArray[i] += mChar;
		}
	}

	std::cout << "Array is now filled.\n\n"
		      << "Now performing LINEAR SEARCH. . .\n\n";

	/*
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << i << " - " << sArray[i] << std::endl;
	}

	std::cout << std::endl;
	*/
	
	start = clock();
	searchResult = linearSearch(sArray, SIZE, sComparable);
	finish = clock();

	std::cout << "*****Total LINEAR SEARCH time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s*****\n";

	if (searchResult >= 0)
		std::cout << "     Match found at index[" << searchResult << "]!\n\n";
	else
		std::cout << "     No match!\n\n";

	std::cout << "Next is BINARY SEARCH.\n\n"
		      << "First need to sort. . .\n\n";

	quickSort(sArray, 0, SIZE - 1);

	std::cout << "Sort complete.\n\n"
		      << "Now performing BINARY SEARCH. . .\n\n";

	/*
	for (int i = 0; i < SIZE; i++)
	{
	std::cout << i << " - " << sArray[i] << std::endl;
	}
	*/

	start = clock();
	searchResult = binarySearch(sArray, SIZE, sComparable);
	finish = clock();

	std::cout << "*****Total BINARY SEARCH time: " << (double)(finish - start) / CLOCKS_PER_SEC << "s*****\n";

	if (searchResult >= 0)
		std::cout << "     Match found at index[" << searchResult << "]!\n\n";
	else
		std::cout << "     No match!\n\n";

	delete [] sArray;
	
	return 0;
}
