/*
 * Queue.h
 *
 *  Created on: Apr 23, 2017
 *      Author: Mostafa Mahmoud
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "LinkedList.h"

template <class Type>
class Queue : protected LinkedList<Type> {

public:

	//Constructors & Destructors
	explicit Queue();
	explicit Queue(const unsigned long &data);
	~Queue();

	//Member Methods
	void enqueue(const unsigned long &data);
	void dequeue();
	Type front() const;
	Type back() const;
	bool isEmpty() const;
	unsigned long size() const;
	void display() const;

};


/////////////////////////////////////////////////////////////////////////////////

//Queue Class Implementation

//Constructors and Destructor

template <class Type>
Queue<Type>::Queue() : LinkedList<Type>() {}

template <class Type>
Queue<Type>::Queue(const unsigned long &data) : LinkedList<Type>(data) {}

template <class Type>
Queue<Type>::~Queue() {
	LinkedList<Type>::~LinkedList();
}


template <class Type>
void Queue<Type>::enqueue(const unsigned long &data) {
	LinkedList<Type>::push_back(data);
}

template <class Type>
void Queue<Type>::dequeue() {
	if( !(LinkedList<Type>::isEmpty()) )
		LinkedList<Type>::pop_front();
}

template <class Type>
Type Queue<Type>::front() const {
	return LinkedList<Type>::front();
}

template <class Type>
Type Queue<Type>::back() const {
	return LinkedList<Type>::back();
}

template <class Type>
bool Queue<Type>::isEmpty() const {
	return LinkedList<Type>::isEmpty();
}

template <class Type>
unsigned long Queue<Type>::size() const {
	return LinkedList<Type>::size();
}

template <class Type>
void Queue<Type>::display() const {
	LinkedList<Type>::display();
}



#endif /* QUEUE_H_ */
