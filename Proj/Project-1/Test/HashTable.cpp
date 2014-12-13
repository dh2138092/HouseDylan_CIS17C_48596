#include "HashTable.h"

HashTable::HashTable(int size)
{
	this->size = size;
	table = new std::list<std::string>[size];
}

HashTable::~HashTable()
{
	delete[] table;
	table = NULL;
}

void HashTable::insert(std::string key)
{
	int hashIndex = getHashIndex(key);
	table[hashIndex].push_back(key);
}

void HashTable::remove(std::string key)
{
	int hashIndex = getHashIndex(key);
	table[hashIndex].pop_back();
}

void HashTable::find(std::string key)
{
	int hashIndex = 0;

}

int HashTable::getHashIndex(std::string key)
{
	int hashIndex = 0;

	for (int i = 0; i < key.length(); i++)
	{
		hashIndex = hashIndex + int(key.at(i));
	}
	
	return hashIndex % size;
}

void HashTable::printData()
{
	for (int i = 0; i < size; i++)
	{
		if (!table[i].empty())
		{
			for (std::list<std::string>::const_iterator it = table[i].begin(); it != table[i].end(); ++it)
				std::cout << *it << '\n';
		}
	}

	std::cout << '\n';
}

void HashTable::printStats()
{
	int numOfCollisions = 0;
	int longestChain = 0;

	for (int i = 0; i < size; i++)
	{
		if (table[i].size() > 1)
			numOfCollisions += table[i].size() - 1;

		if (table[i].size() > longestChain)
			longestChain = table[i].size();
	}

	std::cout << "Size of table: " << size << '\n';
	std::cout << "Number of collisions: " << numOfCollisions << '\n';
	std::cout << "Longest chain: " << longestChain << "\n\n";
}