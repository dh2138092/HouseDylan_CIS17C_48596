#include <iostream>
#include <algorithm>

void bubble_sort(int arr[], int size)
{
	bool not_sorted = true;
	int j = 1, tmp;

	while (not_sorted)  
	{
		not_sorted = false;
		j++;

		for (int i = 0; i < size - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;

				not_sorted = true;
			}
		}
	}
}

void selectSort(int arr[], int n)
{
	int pos_min, temp;

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

	return 0;
}