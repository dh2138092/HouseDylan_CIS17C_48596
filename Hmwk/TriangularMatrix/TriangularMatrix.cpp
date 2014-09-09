/*
	Title: Triangular, 2-Dimensional, and 1-Dimensional Matrices
	Author: Dylan R. House
	Date: September 9, 2014
*/

#include "TriangularMatrix.h"

int main(int argc, char *argv[])
{
	srand((unsigned int)time(0));

	// Initialize the dimensions of the 1-d array and triangular matrix
	int rows = 10;
	int columns = rows;
	int columnsPerLine = 10;

	std::cout << "Start of the demo. \n\n\n\n";

	//////////////////////////////////////////////////////////////
	// Demo the TriangularMatrix class using INTEGER data types //
	//////////////////////////////////////////////////////////////

	// Initialize a TriangularMatrix class that handles INTEGER data types
	TriangularMatrix<int> triangularMatrixInt;

	// Fill the 1-dimensional array and triangular matrix with random numbers
	int *array1dInt = triangularMatrixInt.FillArray(columns);
	int **arrayTriangularInt = triangularMatrixInt.FillArray(rows, array1dInt);

	// Print out the arrays
	std::cout << "INTEGER 1-D array: \n";
	triangularMatrixInt.PrintArray(array1dInt, columns, columnsPerLine);
	std::cout << "INTEGER tri matrix: \n";
	triangularMatrixInt.PrintArray(arrayTriangularInt, array1dInt, rows);

	// Cleanup and get rid of the arrays
	triangularMatrixInt.DestroyArray(arrayTriangularInt, rows);
	triangularMatrixInt.DestroyArray(array1dInt);

	std::cout << "\n=============================\n\n\n";
	////////////////////////////////////////////////////////////
	// Demo the TriangularMatrix class using FLOAT data types //
	////////////////////////////////////////////////////////////

	// Initialize a TriangularMatrix class that handles FLOAT data types
	TriangularMatrix<float> triangularMatrixFloat;

	// Fill the 1-dimensional array and triangular matrix with random numbers
	float *array1dFloat = triangularMatrixFloat.FillArray(columns);
	float **arrayTriangularFloat = triangularMatrixFloat.FillArray(rows, array1dFloat);

	// Print out the arrays
	std::cout << "FLOAT 1-D array: \n";
	triangularMatrixFloat.PrintArray(array1dFloat, columns, columnsPerLine);
	std::cout << "FLOAT tri matrix: \n";
	triangularMatrixFloat.PrintArray(arrayTriangularFloat, array1dFloat, rows);

	// Cleanup and get rid of the arrays
	triangularMatrixFloat.DestroyArray(arrayTriangularFloat, rows);
	triangularMatrixFloat.DestroyArray(array1dFloat);

	std::cout << "\n\nEnd of the demo. \n\n";

	return 0;
}
