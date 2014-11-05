#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DLLNode
{
public:
	DLLNode()
	{
		next = prev = NULL;
	}

	DLLNode(const T& element, DLLNode *n = NULL, DLLNode *p = NULL)
	{
		info = element; next = n; prev = p;
	}

	T info;
	DLLNode *next, *prev;
};

template<class T>
class DLList
{
public:
	DLLList(){ head = tail = NULL; }

	void addToHead(const T&);
	void addToTail(const T&);
	T deleteFromHead();
	T deleteFromTail();
	void deleteNode(T);
	bool isEmpty();
	bool isInList(T) const;

private:
	DLLNode<T> *head, *tail;
};

/*
 *
 *
 *	CLASS IMPLEMENTATION
 *
 *
 */

template<class T>
void DLList<T>::addToHead(const T& element)
{
	head = new DLLNode(element, head);

	if (tail == NULL)
	{
		tail = head;
	}
}

template<class T>
void DLList<T>::addToTail(const T& element)
{
	if (tail != NULL)
	{
		tail = new DLNode<T>(element, NULL, tail);
		tail->prev->next = tail;
	}
	else
	{
		head = tail = new DLNode<T>(element);
	}
}

template<class T>
T DLList<T>::deleteFromHead()
{
	T element = head->info;
	DLLNode *tmp = head;
	if (head == tail) 
		head = tail = NULL;
	else 
		head = head->next;
	delete tmp;
	return element;
}

template<class T>
T DLList<T>::deleteFromTail()
{
	T element = tail->info;
	if (head == tail)
	{
		delete head;
		head = tail = NULL;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}

	return element;
}

template<class T>
void DLList<T>::deleteNode(T element)
{
	if (head != NULL)
	{
		if (head == tail && element == head->info)
		{
			delete head;
			head = tail = NULL;
		}
		else if (element == head->info)
		{
			DLLNode *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			DLLNode *pred, *tmp;
			for (pred = head, tmp = head->next; 
				tmp != NULL && !(tmp->info == element);
				pred = pred->next, tmp = tmp->next);
			if (tmp != NULL)
			{
				pred->next = tmp->next;
				if (tmp == tail) 
					tail = pred;
				delete tmp;
			}
		}	
	}
}

template<class T>
bool DLList<T>::isEmpty()
{
	return head == NULL;
}

template<class T>
bool DLList<T>::isInList(T element) const
{
	DLLNode *tmp;
	for (tmp = head; tmp != NULL && !(tmp->info == element); tmp = tmp->next);
	return tmp != NULL;
}

#endif