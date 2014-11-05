#ifndef STACK
#define STACK

#include <list>

template <class T>
class Stack
{
public:
	void Stack()
	{

	}

	void clear()
	{
		mList.clear();
	}

	bool isEmpty() const
	{
		return mList.empty();
	}

	T& peek()
	{
		return mList.back();
	}

	T pop()
	{
		T element = mList.back();
		mList.pop_back();
		return element;
	}

	void push(const T& element)
	{
		mList.push_back(element);
	}
private:
	list<T> mList;
};

#endif