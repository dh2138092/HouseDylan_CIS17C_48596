#ifndef LINKED_LIST_QUEUE
#define LINKED_LIST_QUEUE

template <class T>
class LLQueue
{
public:
	LLQueue(){ }
	~LLQueue(){ }

	void clear(){ }

	bool isEmpty()
	{
		return list.isEmpty();
	}

	void enqueue(T element)
	{
		list.append(element);
	}

	T dequeue()
	{
		return list.deleteFromHead();
	}

	T peek()
	{
		return list.peekFirst();
	}

private:
	SLList<T> list;
};

#endif