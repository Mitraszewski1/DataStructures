#pragma once
#include <iostream>
template<typename t>
class Stack
{
	t* arr;
	int top;
	size_t Capacity;
public:
	Stack(size_t n=7);
	~Stack();
	void push(t);
	t Top()const;
	void pop();
	bool empty()const;
	int size()const;
	size_t capacity()const;
};

template<typename t>
Stack<t>::Stack(size_t n)
{
	if (n < 0) {
		arr = new t[7];
		Capacity = 7;
	}
	else {
		arr = new t[n];
		Capacity = n;
	}
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
	if (top >= Capacity) {
		Capacity *= 2;
		t* arr2 = new t[Capacity];
		for (size_t i = 0; i < top; ++i) {
			arr2[i] = arr[i];
		}
		delete[]arr;
		arr = arr2;
	}
	arr[top] = a;
}

template<typename t>
t Stack<t>::Top() const
{
	if (empty()) {
		std::cout << "Stack is empty.\n"; 
		return -1;
	}
	return arr[top];
}

template<typename t>
inline void Stack<t>::pop()
{
	if (top >= 0)top--;
	else std::cout << "Stack is empty\n";
}

template<typename t>
inline bool Stack<t>::empty() const
{
	return top<0;
}

template<typename t>
inline int Stack<t>::size() const
{
	return top+1;
}

template<typename t>
inline size_t Stack<t>::capacity() const
{
	return Capacity;
}
