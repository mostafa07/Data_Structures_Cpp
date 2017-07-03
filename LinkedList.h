/*
 * LinkedList.h
 *
 *  Created on: Apr 3, 2017
 *      Author: Mostafa Mahmoud
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

//template <class Type> class LinkedList;	//temp line used in debugging phase

template <class Type>
class Node {
public:
	//Member variables
	Type data;
	Node *next;

public:
	//Constructors and Destrcutor
	Node();	// : data(0), next(0) {}
	Node(Type d);	//: data(d), next(0) {}
	~Node();

	//Methods
	Type getData();
	void setData(Type d);
	Node* getNext();
	void setNext(Type d);

	//Friend Classes
	//friend class LinkedList;
};

////////////////////////////////////////////////////////////////////////////

template <class Type>
class LinkedList {
private:
	//Member variables
	Node<Type> *head;

public:
	//Constructors and Destructor
	LinkedList();	// : head(0) {}
	LinkedList(Type d);		// : head(new Node<Type>(d)) {}
	~LinkedList();

	//Methods
	Node<Type>* getHead();
	void insertNode(Type d);
	void removeElement(Type d);
	void removeElementAt(int pos);
	Node<Type>* findNode(Type d);
	bool isEmpty();
	void printList();
	void printAll(Node<Type>* p);
	void insertNodeAt(Type d, int pos);
	void reverse();
	int size();
	int average();
};

////////////////////////////////////////////////////////////////////////

//Implementation of LinkedList Class

//LinkedList Constructors and Destructors

template <class Type>
LinkedList<Type>::LinkedList() {
	head = NULL;
}

template <class Type>
LinkedList<Type>::LinkedList(Type d) {
	head = new Node<Type>(d);
}

template <class Type>
LinkedList<Type>::~LinkedList() {
	if (head != NULL) {
		while (head->next != NULL) {
			Node<Type> *tmp = head->next;
			delete head;
			head = tmp;
		}
		delete head;
	}
}

//LinkedList Methods

template <class Type>
Node<Type>* LinkedList<Type>::getHead() {
	return this->head;
}

template <class Type>
void LinkedList<Type>::insertNode(Type d) {
	if (head == NULL)
		head = new Node<Type>(d);
	else {
		Node<Type> *tmp = new Node<Type>(d);
		tmp->next = head;
		head = tmp;
	}
}

template <class Type>
void LinkedList<Type>::removeElement(Type d) {
	if (head == NULL)	//in case the list is empty already
		return;

	if (head->data == d) {		//in case it is the first element to be removed
		Node<Type> *tmp = head;
		head = head->next;
		delete tmp;
		return;
	}
	else {
		Node<Type> *p = head;
		if (p->next == NULL)	//check if this is needed
			return;
		while (p->next->data != d) {
			p = p->next;
			if (p->next == NULL)
				return;
		}
		Node<Type> *p2 = p->next;
		p->next = p2->next;
		delete p2;
	}
}

template <class Type>
void LinkedList<Type>::removeElementAt(int pos) {
	if (head == NULL)	//in case the list is empty already
		return;

	Node<Type> *p = head;
	for (int i = 0; i < pos-1; ++i)
		p = p->next;

	Node<Type> *tmp = p->next;
	p->next = tmp->next;
	delete tmp;
}

template <class Type>
Node<Type>* LinkedList<Type>::findNode(Type d) {
	Node<Type> *p = head;
	while (p != NULL) {
		if (p->data == d)
			return p;
		p = p->next;
	}
	return NULL;
}

template <class Type>
bool LinkedList<Type>::isEmpty() {
	return (head == NULL? true: false);
}

template <class Type>
void LinkedList<Type>::printList() {	//The interface to be used by external user
	cout << "[";
	printAll(this->head);
	cout << "]" << endl;
}

template <class Type>
void LinkedList<Type>::printAll(Node<Type>* p) {
	if (p == NULL)
		return;
	else {
		cout << p->data;
		if (p->next != NULL)
			cout << ", ";
		printAll(p->next);
	}
}

template <class Type>
void LinkedList<Type>::insertNodeAt(Type d, int pos) {
	if (pos == 0)
		insertNode(d);
	else {
		Node<Type> *after = head;
		while (--pos && after->next != NULL)
			after = after->next;
		Node<Type> *tmp = new Node<Type>(d);
		tmp->next = after->next;
		after->next = tmp;
	}
}

template <class Type>
void LinkedList<Type>::reverse() {
	if (head == NULL)
		return;

	int len = this->size();
	Node<Type> *ptr = head;
	Type *tmpArray = new Type[len];
	for (int i = 0; i < len; ++i) {
		tmpArray[i] = ptr->data;
		ptr = ptr->next;
	}
	ptr = head;
	for (int i = len-1; i >= 0; --i) {
		ptr->data = tmpArray[i];
		ptr = ptr->next;
	}
	delete[] tmpArray;
}

template <class Type>
int LinkedList<Type>::size() {
	if (head == NULL)
		return (0);

	int i = 0;
	Node<Type> *p = head;
	while (p != NULL) {
		p = p->next;
		i++;
	}
	return i;
}

template <class Type>
int LinkedList<Type>::average() {
	if (head == NULL)
		return (0);

	int sum = 0;
	Node<Type> *ptr = head;
	while (ptr != NULL) {
		sum += ptr->data;
		ptr = ptr->next;
	}
	return (sum / this->size());
}



////////////////////////////////////////////////////////////////////////////////////

//Implementation of Node Class

//Node Class Constructors and Destructors

template <class Type>
Node<Type>::Node() {
	data = 0;
	next = NULL;
}
template <class Type>
Node<Type>::Node(Type d) {
	data = d;
	next = NULL;
}
//Node Destructor (Not needed since it deleting nodes was taken care of in LinkedList class)
template <class Type>
Node<Type>::~Node() {
	//delete this->next;
}

//Node Member Methods

template <class Type>
Type Node<Type>::getData() {
	return this->data;
}
template <class Type>
void Node<Type>::setData(Type d) {
	this->data = d;
}
template <class Type>
Node<Type>* Node<Type>::getNext() {
	return this->next;
}
template <class Type>
void Node<Type>::setNext(Type d) {
	next->data = d;
}

#endif /* LINKEDLIST_H_ */
