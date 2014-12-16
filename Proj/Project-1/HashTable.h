#ifndef HASHTABLE
#define HASHTABLE

#include "LinkedHashEntry.h"

const int TABLE_SIZE = 103;

template <class T>
class HashTable 
{
private:
      LinkedHashEntry<T> **table;

public:
	HashTable()
	{
		table = new LinkedHashEntry<T>*[TABLE_SIZE];

		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	~HashTable()
	{
	
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (table[i] != NULL)
			{
				LinkedHashEntry<T> *prevEntry = NULL;
				LinkedHashEntry<T> *entry = table[i];

				while (entry != NULL)
				{
					prevEntry = entry;
					entry = entry->getNext();
					delete prevEntry;
				}
			}
		}
	
		delete[] table;
	}

	T get(int key)
	{
		int hash = (key % TABLE_SIZE);

		if (table[hash] == NULL)
			return NULL;
		else 
		{
			LinkedHashEntry<T> *entry = table[hash];

			while (entry != NULL && entry->getKey() != key)
				entry = entry->getNext();

			if (entry == NULL)
				return NULL;
			else
				return entry->getValue();
		}
	}

	void put(int key, T value)
	{
		int hash = (key % TABLE_SIZE);

		if (table[hash] == NULL)
			table[hash] = new LinkedHashEntry<T>(key, value);
		else 
		{
			LinkedHashEntry<T> *entry = table[hash];

			while (entry->getNext() != NULL)
				entry = entry->getNext();

			if (entry->getKey() == key)
				entry->setValue(value);
			else
				entry->setNext(new LinkedHashEntry<T>(key, value));
		}
	}

	void remove(int key) 
	{
		int hash = (key % TABLE_SIZE);

		if (table[hash] != NULL) 
		{
			LinkedHashEntry<T> *prevEntry = NULL;
			LinkedHashEntry<T> *entry = table[hash];

			while (entry->getNext() != NULL && entry->getKey() != key) 
			{
				prevEntry = entry;
				entry = entry->getNext();
			}

			if (entry->getKey() == key) 
			{
				if (prevEntry == NULL) 
				{
					LinkedHashEntry<T> *nextEntry = entry->getNext();
					delete entry;
					table[hash] = nextEntry;
				} 
				else 
				{
					LinkedHashEntry<T> *next = entry->getNext();
					delete entry;
					prevEntry->setNext(next);
				}
			}
		}
	}
};

#endif
