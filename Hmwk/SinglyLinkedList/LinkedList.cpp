#include "LinkedList.h"

int main(int argc, char **argv)
{

	return 0;
}

LinkedList::LinkedList()
{
	head = tail = NULL;
}

LinkedList::~LinkedList()
{
	Node *p;
	
	while ( !isEmpty() )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

int LinkedList::first()
{
	return head->data;
}

int LinkedList::last()
{
	return tail->data;
}

void LinkedList::insertBefore(int reference, int data)
{
	if (isEmpty())
		return;

	Node *currentNode = head;

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

void LinkedList::insertAfter(int reference, int data)
{
	Node *currentNode = head;

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

int LinkedList::isEmpty()
{
	return head == NULL;
}

void LinkedList::addToHead(int newEntry)
{
	head = new Node(newEntry, head);
	
	if ( tail == NULL )
	{
		tail = head;
	}
}

void LinkedList::addToTail(int newEntry)
{
	if ( tail != NULL)
	{
		tail->next = new Node(newEntry);
		tail = tail->next;
	}
	else
	{
		head = tail = new Node(newEntry);
	}
}

int LinkedList::deleteFromHead()
{
	int entry = head->data;
	Node *tmp = head;
	
	if ( head == tail )
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

int LinkedList::deleteFromTail()
{
	int entry = tail->data;

	if ( head == tail )
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		Node *tmp;

		for ( tmp = head; tmp->next != tail; tmp = tmp->next );

		delete tail;
		tail = tmp;
		tail->next = NULL;
	}

	return entry;
}

void LinkedList::deleteNode(int entry)
{
	if ( head != NULL )
	{
		if ( head == tail && entry == head->data )
		{
			delete head;
			head = tail = NULL;
		}
		else if ( entry == head->data )
		{
			Node *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			Node *pred, *tmp;

			for ( pred = head, tmp = head->next; 
				  tmp != NULL && !(tmp->data == entry);
				  pred = pred->next, tmp = tmp->next );

			if ( tmp != NULL )
			{
				pred->next = tmp->next;
				if ( tmp == tail )
				{
					tail = pred;
				}
				
				delete tmp;
			}
		}
	}
}

bool LinkedList::contains(int entry)
{
	Node *tmp;

	for ( tmp = head; tmp != NULL && !(tmp->data == entry); tmp = tmp->next );

	return tmp != NULL;
}