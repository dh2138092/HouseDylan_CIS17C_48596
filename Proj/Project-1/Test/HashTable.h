#ifndef HASHTABLE
#define HASHTABLE

#include <list>
#include <array>
#include <fstream>
#include <iostream>
#include <string>

#include <algorithm>

class HashTable
{
private:
	std::list<std::string> *table;
	int size;

public:
	HashTable();
	HashTable(int size);
	~HashTable();

	void insert(std::string key);
	void remove(std::string key);
	void find(std::string key);
	int getHashIndex(std::string key);
	void printData();
	void printStats();
};

#endif