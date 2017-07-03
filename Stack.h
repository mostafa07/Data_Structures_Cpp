/*
 * Stack.h
 *
 *  Created on: Apr 22, 2017
 *      Author: Mostafa Mahmoud
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "LinkedList.h"

template <class Type>
class Stack : protected LinkedList<Type> {

public:

	//Constructors & Destructors
	explicit Stack();
	explicit Stack(const unsigned long &pushedData);
	~Stack();

	//Member Methods
	void push(const unsigned long &pushedData);
	void pop();
	Type peek() const;
	void display() const;

};


/////////////////////////////////////////////////////////////////////////////////

//Stack Class Implementation

//Constructors and Destructor

template <class Type>
Stack<Type>::Stack() : LinkedList<Type>() {}

template <class Type>
Stack<Type>::Stack(const unsigned long &pushedData) : LinkedList<Type>(pushedData) {}

template <class Type>
Stack<Type>::~Stack() {
	LinkedList<Type>::~LinkedList();
}


template <class Type>
void Stack<Type>::push(const unsigned long &pushedData) {
	LinkedList<Type>::push_front(pushedData);
}

template <class Type>
void Stack<Type>::pop() {
	if( !(LinkedList<Type>::isEmpty()) )
		LinkedList<Type>::pop_front();
}

template <class Type>
Type Stack<Type>::peek() const {
	return LinkedList<Type>::front();
}

template <class Type>
void Stack<Type>::display() const {
	LinkedList<Type>::display();
}


#endif /* STACK_H_ */
