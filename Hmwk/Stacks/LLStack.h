#ifndef LINKED_LIST_STACK
#define LINKED_LIST_STACK

#include "SLList.h"

template <class T>
class LLStack
{
public:
	LLStack(){ }
	~LLStack(){ }

	void clear(){ }

	bool isEmpty()
	{
		return list.isEmpty();
	}

	void push(T element)
	{
		list.append(element);
	}

	T pop()
	{
		return list.deleteFromTail();
	}

	T peek()
	{
		return list.peekLast();
	}

private:
	SLList<T> list;
};

#endif