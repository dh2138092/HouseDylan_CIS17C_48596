#ifndef _TRIANGULARMATRIX_H_
#define _TRIANGULARMATRIX_H_

#include <cstdlib>
#include <iostream>
#include <ctime>

template <class T>
class TriangularMatrix
{
private:

public:
	TriangularMatrix();
	~TriangularMatrix();

	// 1-D array
	T* FillArray(int columns);
	void PrintArray(T *array1d, int columns, int columnsPerLine);
	void DestroyArray(T *array1d);

	// Tri array
	T** FillArray(int rows, T *array1d);
	void PrintArray(T **arrayTriangular, T *array1d, int rows);
	void DestroyArray(T **arrayTriangular, int rows);
};

template <class T>
TriangularMatrix<T>::TriangularMatrix()
{

}

template <class T>
TriangularMatrix<T>::~TriangularMatrix()
{

}

/////////////////////////////////
////////// 1-D Array ////////////
/////////////////////////////////

template <class T>
T* TriangularMatrix<T>::FillArray(int columns)
{
	T *array = new T[columns];

	for (int column = 0; column < columns; column++)
	{
		array[column] = rand() % 9 + 2;
	}

	return array;
}

template <class T>
void TriangularMatrix<T>::PrintArray(T *array, int columns, int columnsPerLine)
{
	std::cout << std::endl;

	for (int column = 0; column < columns; column++)
	{
		std::cout << array[column] << " ";

		if (column % columnsPerLine == (columnsPerLine - 1))
		{
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
}

template <class T>
void TriangularMatrix<T>::DestroyArray(T *array)
{
	delete[] array;
	array = NULL;
}

/////////////////////////////////
////// Triangular Matrix ////////
/////////////////////////////////

template <class T>
T** TriangularMatrix<T>::FillArray(int rows, T *array_1D)
{
	// Declare the 2-D array and establish the desired number of rows
	T **array = new T*[rows];

	// # of columns in row i = value at array_1D[i]
	for (int row = 0; row < rows; row++)
	{
		array[row] = new T[array_1D[row]];
	}

	// Fill each entry of the array with random 2-digit numbers
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < array_1D[row]; column++)
		{
			array[row][column] = rand() % 90 + 10;
		}
	}

	return array;
}

template <class T>
void TriangularMatrix<T>::PrintArray(T **array, T *array_1D, int rows)
{
	std::cout << std::endl;

	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < array_1D[row]; column++)
		{
			std::cout << array[row][column] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

template <class T>
void TriangularMatrix<T>::DestroyArray(T **array, int rows)
{
	// Destroy columns.
	for (int row = 0; row < rows; row++)
	{
		delete[] array[row];
	}

	// Destroy row pointers.
	delete[] array;
	array = NULL;
}

#endif
