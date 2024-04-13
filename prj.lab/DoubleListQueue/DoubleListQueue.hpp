//#pragma once
//#ifndef DOUBLELISTQUEUE_HPP
//#define DOUBLELISTQUEUE_HPP
//#include <stdexcept> 
//
//class DoubleListQueue {
//public:
//	DoubleListQueue() = default;
//	int top();
//	void push(int);
//	int getSize();
//	int getFront();
//	int getBack();
//
//private:
//	int size = 0;
//	struct Node {
//		int value;
//		Node* prev;
//		Node* next;
//		Node(int val) {
//			value = val;
//			prev = nullptr;
//			next = nullptr;
//		}
//	};
//	Node* frontNode;
//	Node* backNode;
//
//};
//
///*Реализвция класса начинается здесь: */
//
//void DoubleListQueue::push(int rhs) {
//	Node* newNode = new Node(rhs);
//	if (frontNode == nullptr) {
//		frontNode = backNode = newNode;
//	}
//	else {
//		backNode->next = newNode;
//		newNode->prev = backNode;
//		backNode = newNode;
//	}
//	size += 1;
//}
//
//int DoubleListQueue::getSize() {
//	return size;
//}
//
//int DoubleListQueue::getFront() {
//	return frontNode->value;
//}
//
//int DoubleListQueue::getBack() {
//	return backNode->value;
//}
//
//#endif
