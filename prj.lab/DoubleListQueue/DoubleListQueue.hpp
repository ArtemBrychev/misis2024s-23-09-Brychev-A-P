#pragma once
#ifndef DOUBLELISTQUEUE_HPP
#define DOUBLELISTQUEUE_HPP
#include <stdexcept>

/*Вариант 2, Очередь на двусвязном списке(нодах)*/

template <typename T>
class DoubleListQueue {
public:
	DoubleListQueue() = default;
	T top();
	void push(T);
	int getSize();
	T getFront();
	T getBack();

private:
	int size_ = 0;
	struct Node {
		T value;
		Node* prev;
		Node* next;
	};
	Node* frontNode;
	Node* backNode;

};

/*Реализвция класса начинается здесь: */

template <typename T>
void DoubleListQueue<T>::push(T rhs) {
	if (size_ == 0) {
		Node* temp = new Node;
		temp->value = rhs;
		frontNode = temp;
		backNode = frontNode;
	}
	else {
		Node* temp = new Node;
		Node* fuck = new Node;
		temp->value = rhs;
		backNode->next = temp;
		fuck = backNode;
		backNode = temp;
		backNode->prev = fuck;
	}
	size_ += 1;
}

template <typename T>
int DoubleListQueue<T>::getSize() {
	return size_;
}

template <typename T>
T DoubleListQueue<T>::getFront() {
	return frontNode->value;
}

template <typename T>
T DoubleListQueue<T>::getBack() {
	return backNode->value;
}

template <typename T>
T DoubleListQueue<T>::top() {
	T rtd = frontNode->value;
	Node* temp = new Node;
	temp = frontNode;
	frontNode = frontNode->next;
	delete temp;
	size_ -= 1;
	return rtd;
}

#endif
