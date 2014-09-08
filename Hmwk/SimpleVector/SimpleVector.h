// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *_buffer;          // To point to the allocated array
   int _size;    // Number of elements in the array
   int _capacity;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { _buffer = 0; _size = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
	
    // Add element T to the top of the array
	void push(const T &element);

	// Remove element that's at the top of the array
	void pull();
   
   // Accessor to return the array size
   int size() const
      { return _size; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   _size = s;
   _capacity = s;
   // Allocate memory for the array.
   try
   {
      _buffer = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < _size; count++)
      *(_buffer + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   _size = obj._size;
   
   // Allocate memory for the array.
   _buffer = new T [_size];
   if (_buffer == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < _size; count++)
      *(_buffer + count) = *(obj._buffer + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (_size > 0)
      delete [] _buffer;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void SimpleVector<T>::push(const T &element)
{
	if ( _size == _capacity )
	{
		int new_capacity = _capacity > 0 ? 2 * _capacity : 2;
		T *newBuffer = new T[new_capacity];
		std::copy(_buffer, _buffer + _size, newBuffer);
		std::swap(_capacity, new_capacity);
		std::swap(_buffer, newBuffer);
		delete[] newBuffer;
	}

	_buffer[_size++] = element;
}

template <class T>
void pull()
{

}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= _size)
      subError();
   return _buffer[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= _size)
      subError();
   return _buffer[sub];
}
#endif
