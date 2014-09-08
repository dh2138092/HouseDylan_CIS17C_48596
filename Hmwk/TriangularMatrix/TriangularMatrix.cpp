/*
	Title: Triangular, 2-Dimensional, and 1-Dimensional Arrays/Matrices
	Author: Dylan R. House
	Date: August 28, 2014
*/

#include <cstdlib>
#include <iostream>
#include <ctime>


int*  FillArray(int);                // 1-D Array
int** FillArray(int, int);           // 2-D Array
int** FillArray(int, int *);         // Tri Array

void PrintArray(int *, int, int);    // 1-D Array
void PrintArray(int **, int, int);   // 2-D Array
void PrintArray(int **, int, int *); // Tri Array

void DestroyArray(int *);            // 1-D Array
void DestroyArray(int **, int);      // 2-D & Tri Arrays


int main(int argc, char *argv[])
{
	srand((unsigned int) time(0));
	int rows = 10;
	//int columns = 10;
	int cls = rows;
	int columns_per_line = 10;

	int *array_1D = FillArray(cls);
	//int **array_2D = FillArray(rows, columns);
	int **array_triangular = FillArray(rows, array_1D);

	//PrintArray(array_2D, rows, columns);
	PrintArray(array_1D, cls, columns_per_line);
	PrintArray(array_triangular, rows, array_1D);

	//DestroyArray(array_2D, rows);
	DestroyArray(array_triangular, rows);
	DestroyArray(array_1D);

	return 0;
}

/////////////////////////////////
////////// 1-D Array ////////////
/////////////////////////////////

int* FillArray(int columns)
{
	int *array = new int[columns];

	// Fill the array with random numbers 1 thru 10.
	for ( int column = 0; column < columns; column++ ) 
	{
		array[column] = rand() % 9 + 2; 
	}

	return array;
}

void PrintArray(int *array, int columns, int columns_per_line)
{
	std::cout << std::endl;

	for ( int column = 0; column < columns; column++ )
	{
		std::cout << array[column] << " ";

		if ( column % columns_per_line == (columns_per_line - 1) )
		{
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
}

void DestroyArray(int *array)
{
	delete[] array;
	array = NULL;
}

/////////////////////////////////
/////////// 2-D Array ///////////
/////////////////////////////////

int** FillArray(int rows, int columns)
{
	// Declare the 2-D array by establishing the desired number of rows in it.
	int **array = new int*[rows]; 

	// Add desired number of columns to each row in the array.
	for ( int row = 0; row < rows; row++ ) 
	{
		array[row] = new int[columns]; 
	}

	// Fill the array with random 2-digit numbers.
	for ( int row = 0; row < rows; row++ ) 
	{
		for ( int column = 0; column < columns; column++ )
		{
			array[row][column] = rand() % 90 + 10; 
		}
	}

	return array;
}

void PrintArray(int **array, int rows, int columns)
{
	std::cout << std::endl;

	for ( int row = 0; row < rows; row++ )
	{
		for ( int column = 0; column < columns; column++ )
		{
			std::cout << array[row][column] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

/////////////////////////////////
/////// Triangular Array ////////
/////////////////////////////////

int** FillArray(int rows, int *array_1D)
{
	// Declare the 2-D array and establish the desired number of rows
	int **array = new int*[rows]; 

	// # of columns in row i = value at array_1D[i]
	for ( int row = 0; row < rows; row++ )
	{
		array[row] = new int[array_1D[row]]; 
	}

	// Fill each entry of the array with random 2-digit numbers
	for ( int row = 0; row < rows; row++ ) 	
	{
		for ( int column = 0; column < array_1D[row]; column++ )
		{
			array[row][column] = rand() % 90 + 10;
		}
	}

	return array;
}

void PrintArray(int **array, int rows, int *array_1D)
{
	std::cout << std::endl;

	for ( int row = 0; row < rows; row++ )
	{
		for ( int column = 0; column < array_1D[row]; column++ )
		{
			std::cout << array[row][column] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

//////////////////////////////////
// 2-D Array & Triangular Array //
//////////////////////////////////

void DestroyArray(int **array, int rows)
{
	// Destroy columns.
	for ( int row = 0; row < rows; row++ ) 
	{
		delete[] array[row];
	}

	// Destroy row pointers.
	delete[] array; 
	array = NULL;
}
