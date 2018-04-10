#pragma once
#include <iostream>
template<typename t>
class Stack
{
	t* arr;
	int top;
	size_t capacity;
public:
	Stack(size_t n=7);
	~Stack();
	void push(t);
	t Top()const;
	void pop();
	bool empty()const;
	int size()const;
	int Capacity()const;
};

template<typename t>
Stack<t>::Stack(size_t n)
{
	if (n < 0)throw std::string("Array size can't be negative!\n");
	arr = new t[n];
	capacity = n;
	top = -1;
}
template<typename t>
inline Stack<t>::~Stack()
{
	delete[]arr;
}

template<typename t>
void Stack<t>::push(t a)
{
	top++;
	if (top >= capacity) {
		capacity *= 2;
		t* arr2 = new t[capacity];
		for (size_t i = 0; i < top; ++i) {
			arr2[i] = arr[i];
		}
		delete[]arr;
		arr = arr2;
		delete arr2;
	}
	arr[top] = a;
}

template<typename t>
inline t Stack<t>::Top() const
{
	return arr[top];
}

template<typename t>
inline void Stack<t>::pop()
{
	if (top >= 0)top--;
	else cout << "Stack is empty\n";
}

template<typename t>
inline bool Stack<t>::empty() const
{
	return top>=0;
}

template<typename t>
inline int Stack<t>::size() const
{
	return top;
}

template<typename t>
inline int Stack<t>::Capacity() const
{
	return capacity;
}
