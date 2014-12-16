#ifndef HASHENTRY
#define HASHENTRY

template <class T>
class LinkedHashEntry 
{
private:
      int key;
	  T value;
      LinkedHashEntry *next;

public:
	LinkedHashEntry(int key, T value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
 
	int getKey() 
	{
		return key;
	}

	T getValue()
	{
		return value;
	}

	void setValue(T value)
	{
		this->value = value;
	}

	LinkedHashEntry *getNext() 
	{
		return next;
	}

	void setNext(LinkedHashEntry *next) 
	{
		 this->next = next;
	}
};

#endif
