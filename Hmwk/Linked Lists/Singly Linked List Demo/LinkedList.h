/*
	Copy Constructor and Assignment Operator
	Extract
*/

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>
#include <string>

template <class T>
class LinkedList 
{
public:
	LinkedList();
	LinkedList(const LinkedList &o);
	~LinkedList();

	void insertBefore(T reference, T data);
	void insertAfter(T reference, T data);
	void prepend(T data);
	void append(T data);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(T data);
	bool contains(T data);
	T peekFirst();
	T peekLast();
	bool isEmpty();
	void toString();

private:
	class Node
	{
	public:
		T data;
		Node *next;

		Node()
		{
			data = NULL;
			next = NULL;
		}

		Node(T dataPortion, Node *nextNode = 0)
		{
			data = dataPortion;
			next = nextNode;
		}
	};

	Node *head;
    Node *tail;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = tail = NULL;
}

// Copy Constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList &o)
{
	for (Node *ptr = o.head; ptr != NULL; ptr = ptr->next)
		addToTail(ptr->data);
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node *p;

	while (!isEmpty())
	{
		p = head->next;
		delete head;
		head = p;
	}
}

template <class T>
T LinkedList<T>::peekFirst()
{
	return head->data;
}

template <class T>
T LinkedList<T>::peekLast()
{
	return tail->data;
}

template <class T>
void LinkedList<T>::insertBefore(T reference, T data)
{
	if (isEmpty())
		return;

	Node *currentNode = head;

	if (currentNode->data == reference)
	{
		Node *n = new Node(data);
		n->next = currentNode->next;
		currentNode->next = n;
		return;
	}

	while (currentNode->next != NULL)
	{
		if (currentNode->next->data == reference)
		{
			Node *n = new Node(data);
			n->next = currentNode->next;
			currentNode->next = n;
			return;
		}

		currentNode = currentNode->next;
	}
}

template <class T>
void LinkedList<T>::insertAfter(T reference, T data)
{
	if (isEmpty())
		return;

	Node *currentNode = head;

	if (currentNode->data == reference)
	{
		Node *n = new Node(data);
		n->next = currentNode->next;
		currentNode->next = n;
		return;
	}

	while (currentNode != NULL)
	{
		if (currentNode->data == reference)
		{
			Node *n = new Node(data);
			n->next = currentNode->next;
			currentNode->next = n;
			return;
		}

		currentNode = currentNode->next;
	}
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	return head == NULL;
}

template <class T>
void LinkedList<T>::prepend(T data)
{
	head = new Node(data, head);

	if (tail == NULL)
	{
		tail = head;
	}
}

template <class T>
void LinkedList<T>::append(T data)
{
	if (tail != NULL)
	{
		tail->next = new Node(data);
		tail = tail->next;
	}
	else
	{
		head = tail = new Node(data);
	}
}

template <class T>
int LinkedList<T>::deleteFromHead()
{
	int entry = head->data;
	Node *tmp = head;

	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		head = head->next;
	}

	delete tmp;
	return entry;
}

template <class T>
int LinkedList<T>::deleteFromTail()
{
	int entry = tail->data;

	if (head == tail)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		Node *tmp;

		for (tmp = head; tmp->next != tail; tmp = tmp->next);

		delete tail;
		tail = tmp;
		tail->next = NULL;
	}

	return entry;
}

template <class T>
void LinkedList<T>::deleteNode(T data)
{
	if (head != NULL)
	{
		if (head == tail && data == head->data)
		{
			delete head;
			head = tail = NULL;
		}
		else if (data == head->data)
		{
			Node *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			Node *pred, *tmp;

			for (pred = head, tmp = head->next;
				tmp != NULL && !(tmp->data == data);
				pred = pred->next, tmp = tmp->next);

			if (tmp != NULL)
			{
				pred->next = tmp->next;
				if (tmp == tail)
				{
					tail = pred;
				}

				delete tmp;
			}
		}
	}
}

template <class T>
bool LinkedList<T>::contains(T data)
{
	Node *tmp;

	for (tmp = head; tmp != NULL && !(tmp->data == entry); tmp = tmp->next);

	return tmp != NULL;
}

template <class T>
void LinkedList<T>::toString()
{
	Node *currentNode = head;
	int counter = 0;

	if (currentNode == NULL)
	{
		std::cout << "List is empty\n";
		return;
	}

	while (currentNode != NULL)
	{
		std::cout << "Node " << ++counter << ": " << currentNode->data << '\n';
		currentNode = currentNode->next;
	}
}

#endif

