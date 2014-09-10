#ifndef _TRIANGULARMATRIX_H_
#define _TRIANGULARMATRIX_H_

#include <cstdlib>
#include <iostream>
#include <ctime>

template <class T>
class TriangularMatrix
{
private:
	int _rows;
	int _columns;
	int _columnsPerRow;

public:
	TriangularMatrix();
	TriangularMatrix(int rows, int columnsPerRow);
	~TriangularMatrix();

	// 1-D array
	T* FillArray();
	void PrintArray(T *array1d);
	void DestroyArray(T *array1d);

	// Tri array
	T** FillArray(T *array1d);
	void PrintArray(T **arrayTriangular, T *array1d);
	void DestroyArray(T **arrayTriangular);
};

template <class T>
TriangularMatrix<T>::TriangularMatrix()
{
	_rows = 0;
	_columns = 0;
	_columnsPerRow = 0;
}

template <class T>
TriangularMatrix<T>::TriangularMatrix(int rows, int columnsPerRow)
{
	_rows = rows;
	_columns = rows;
	_columnsPerRow = columnsPerRow;
}


template <class T>
TriangularMatrix<T>::~TriangularMatrix()
{

}

/////////////////////////////////
////////// 1-D Array ////////////
/////////////////////////////////

template <class T>
T* TriangularMatrix<T>::FillArray()
{
	T *array = new T[_columns];

	for ( int column = 0; column < _columns; column++ )
	{
		array[column] = rand() % 9 + 2;
	}

	return array;
}

template <class T>
void TriangularMatrix<T>::PrintArray(T *array)
{
	std::cout << std::endl;

	for ( int column = 0; column < _columns; column++ )
	{
		std::cout << array[column] << " ";

		if ( column % _columnsPerRow == (_columnsPerRow - 1) )
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
T** TriangularMatrix<T>::FillArray(T *array_1D)
{
	// Declare the 2-D array and establish the desired number of rows
	T **array = new T*[_rows];

	// # of columns in row i = value at array_1D[i]
	for (int row = 0; row < _rows; row++)
	{
		array[row] = new T[array_1D[row]];
	}

	// Fill each entry of the array with random 2-digit numbers
	for (int row = 0; row < _rows; row++)
	{
		for (int column = 0; column < array_1D[row]; column++)
		{
			array[row][column] = rand() % 90 + 10;
		}
	}

	return array;
}

template <class T>
void TriangularMatrix<T>::PrintArray(T **array, T *array_1D)
{
	std::cout << std::endl;

	for (int row = 0; row < _rows; row++)
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
void TriangularMatrix<T>::DestroyArray(T **array)
{
	// Destroy columns.
	for (int row = 0; row < _rows; row++)
	{
		delete[] array[row];
	}

	// Destroy row pointers.
	delete[] array;
	array = NULL;
}

#endif
