#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

template <class T>
void bubbleSort(T arr[], int n)
{
	bool swapped = true;
	int j = 1;
	T tmp;

	while (swapped)  
	{
		swapped = false;
		j++;

		for (int i = 0; i < n - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;

				swapped = true;
			}
		}
	}
}

template <class T>
void selectSort(T arr[], int n)
{
	int pos_min;
	T temp;

	for (int i = 0; i < n - 1; i++)
	{
		pos_min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[pos_min])
				pos_min = j;
		}

		if (pos_min != i)
		{
			temp = arr[i];
			arr[i] = arr[pos_min];
			arr[pos_min] = temp;
		}
	}
}

int main(int argv, char *argc[])
{
	
	srand((unsigned int)time(0));
	clock_t start, finish = 0;
	int searchResult = 0;
	int const numOfCharacters = 8;
	int const SIZE = 20;
	std::string *sArray = new std::string[SIZE];
	std::string sComparable = "";

	for (int i = 0; i < numOfCharacters; i++)
	{
		char mChar = 'A' + rand() % 26;
		sComparable += mChar;
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < numOfCharacters; j++)
		{
			char mChar = 'A' + rand() % 26;
			sArray[i] += mChar;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << sArray[i] << '\n';
	}

	std::cout << '\n';

	bubbleSort(sArray, SIZE + 1);

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << sArray[i] << '\n';
	}

	std::cout << '\n';

	delete [] sArray;
	

	return 0;
}
