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
<<<<<<< HEAD
	T *_buffer;          // To point to the allocated array
	int _size;           // Number of elements in the array
	int _capacity;
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	// Default constructor
	SimpleVector()
	{
		_buffer = 0; _size = 0;
	}

	// Constructor declaration
	SimpleVector(int);

	// Copy constructor declaration
	SimpleVector(const SimpleVector &);

	// Destructor declaration
	~SimpleVector();

	// Add element T to the top of the array
=======
   T *_buffer;          // To point to the allocated array
   int _size;           // Number of elements in the array
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
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
	void push(const T &element);

	// Remove element that's at the top of the array
	void pull();
<<<<<<< HEAD

	// Accessor to return the array size
	int size() const
	{
		return _size;
	}

	int capacity() const
	{
		return _capacity;
	}

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T &operator[](const int &);
=======
   
   // Accessor to return the array size
   int size() const
      { return _size; }

   int capacity() const
      { return _capacity; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
<<<<<<< HEAD
	_size = s;
	_capacity = s;
	// Allocate memory for the array.
	try
	{
		_buffer = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < _size; count++)
		*(_buffer + count) = 0;
=======
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
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
<<<<<<< HEAD
	// Copy the array size.
	_size = obj._size;

	// Allocate memory for the array.
	_buffer = new T[_size];
	if (_buffer == 0)
		memError();

	// Copy the elements of obj's array.
	for (int count = 0; count < _size; count++)
		*(_buffer + count) = *(obj._buffer + count);
=======
   // Copy the array size.
   _size = obj._size;
   
   // Allocate memory for the array.
   _buffer = new T [_size];
   if (_buffer == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < _size; count++)
      *(_buffer + count) = *(obj._buffer + count);
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
<<<<<<< HEAD
	if (_size > 0)
		delete[] _buffer;
=======
   if (_size > 0)
      delete [] _buffer;
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
<<<<<<< HEAD
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
=======
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
<<<<<<< HEAD
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
=======
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
}

template <class T>
void SimpleVector<T>::push(const T &element)
{
	// If the size of the array = its capacity... We need to expand its capacity by 1. So...
<<<<<<< HEAD
	if (_size == _capacity)
	{
		// ... expand array's capacity by 1
		int newCapacity = _capacity + 1;
=======
	if ( _size == _capacity ) 
	{
		// ... expand array's capacity by 1
		int newCapacity = _capacity + 1; 
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676

		// Create a temp array with capacty = new capacity
		// i.e.
		//      old array = [][][][][]
		//                  capacity = 5
		//      new array = [][][][][][] 
		//                  new capacity = capacity + 1 = 6
<<<<<<< HEAD
		T *newBuffer = new T[newCapacity];
=======
		T *newBuffer = new T[newCapacity]; 
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676

		// Copy data from the old array into the temp array
		// i.e.
		//      old array = [7][2][3][1][5]
		//      new array = [7][2][3][1][5][]
<<<<<<< HEAD
		std::copy(_buffer, _buffer + _size, newBuffer);

=======
		std::copy(_buffer, _buffer + _size, newBuffer); 
		
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
		_capacity = newCapacity;

		// Swap data between old array and temp array
		// i.e.
		//      old array = [7][2][3][1][5][]
		//      new array = [7][2][3][1][5]
		std::swap(_buffer, newBuffer);
<<<<<<< HEAD

=======
		
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
		// Temp array is no longer needed, so free up that space of memory
		delete[] newBuffer;
	}

	// Add the new element onto the top of the array
	// i.e.
	//      old array = [7][2][3][1][5][]
	//      new array = [7][2][3][1][5][new element]
	_buffer[_size++] = element;
}

template <class T>
void SimpleVector<T>::pull()
{
	// Create a new temporary array with new capacity = capacity -1
	int newCapacity = _capacity - 1;
	T *newBuffer = new T[newCapacity];

	// Define for the vector that its capacity and size are decreasing by 1
	_capacity = newCapacity;
	_size--;

	// Copy data from old buffer to new buffer
	std::copy(_buffer, _buffer + _size, newBuffer);
	std::swap(_buffer, newBuffer);

	delete[] newBuffer;
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
<<<<<<< HEAD
	if (sub < 0 || sub >= _size)
		subError();
	return _buffer[sub];
=======
   if (sub < 0 || sub >= _size)
      subError();
   return _buffer[sub];
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
<<<<<<< HEAD
	if (sub < 0 || sub >= _size)
		subError();
	return _buffer[sub];
}
#endif
=======
   if (sub < 0 || sub >= _size)
      subError();
   return _buffer[sub];
}
#endif
>>>>>>> fa4ac3ccc94bc1a2788d3dffa0bf8d09b8b7d676
