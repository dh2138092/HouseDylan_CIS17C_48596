/*
	Copy Constructor and Assignment Operator
	Extract
*/

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <string>

class LinkedList 
{
public:
	LinkedList();
	~LinkedList();

	int first();
	int last();
	void insertBefore(int, int);
	void insertAfter(int, int);

	int isEmpty();
	void addToHead(int); // Prepend()
	void addToTail(int); // Append()
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool contains(int);
	//std::string toString();

private:
	class Node
	{
	public:
		int data;
		Node *next;

		Node()
		{
			data = 0;
			next = NULL;
		}

		Node(int dataPortion, Node *nextNode = 0)
		{
			data = dataPortion;
			next = nextNode;
		}
	};

	Node *head;
    Node *tail;
};

#endif

