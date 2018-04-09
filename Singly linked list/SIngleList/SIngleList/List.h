#pragma once
#include <iostream>

template<typename t>
class Node
{
	t data;
	Node<t>* next;
public:
	Node();
	Node(t);
	void setData(t);
	void setNext(Node<t>*);
	t Data()const;
	Node<t>* Next()const;
};

template<typename t>
class List
{
	Node<t>* head;
public:
	List();
	List(t);
	List(Node<t>*);
	void Print()const;
	void Push_back(Node<t>*);
	void Push_front(Node<t>*);
	void Delete_first();
	void Delete_last();
};

template<typename t>
inline Node<t>::Node()
{
	next = NULL;
}

template<typename t>
inline Node<t>::Node(t a)
{
	data = a;
	next = NULL;
}

template<typename t>
inline void Node<t>::setData(t a)
{
	data = a;
}

template<typename t>
inline void Node<t>::setNext(Node<t>* a)
{
	next = a;
}

template<typename t>
inline t Node<t>::Data() const
{
	return data;
}

template<typename t>
inline Node<t>* Node<t>::Next() const
{
	return next;
}

template<typename t>
inline List<t>::List()
{
	head=NULL;
}

template<typename t>
inline List<t>::List(t a)
{
	head = new Node(a);
}

template<typename t>
inline List<t>::List(Node<t>* a)
{
	head = a;
}

template<typename t>
void List<t>::Print() const
{
	if (head == NULL)std::cout << "NULL\n";
	else {
		Node<t>* temp = head;
		while (temp->Next() != NULL) {
			std::cout << temp->Data() << "-->";
			temp = temp->Next();
		}
		std::cout << temp->Data() << "-->" << "NULL\n";
	}
}

template<typename t>
void List<t>::Push_back(Node<t>* n)
{
	if (head == NULL)head = n;
	else {
		Node<t>* temp = head;
		while (temp->Next() != NULL) {
			temp = temp->Next();
		}
		temp->setNext(n);
	}
}

template<typename t>
void List<t>::Push_front(Node<t>* a)
{
	if (head == NULL)head = a;
	else {
		a->setNext(head);
		head = a;
	}
}

template<typename t>
void List<t>::Delete_first()
{
	if (head == NULL)return;
	Node<t>* temp = new Node<t>();
	temp = head;
	head = head->Next();
	delete temp;
}

template<typename t>
void List<t>::Delete_last()
{
	if (head == NULL)return;
	else if (head->Next() == NULL) {
		delete head;
		head = NULL;
		return;
	}
	else {
		Node<t>* temp = head;
		while (temp->Next()->Next() != NULL) {
			temp = temp->Next();
		}
		Node<t>* temp2 = temp->Next();
		temp->setNext(NULL);
		delete temp2;
		return;
	}
}
