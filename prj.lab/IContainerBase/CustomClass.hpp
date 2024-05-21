#pragma once
#include "IContainerBase.hpp"
#include "iostream"

class CustomContainer : public IContainerBase {
public:
	CustomContainer() {
		head = nullptr;
		tail = nullptr;
		nodeCapacity = 5;
	}
	CustomContainer(size_t size) {
		head = nullptr;
		tail = nullptr;
		nodeCapacity = size;
	}
	~CustomContainer() = default;
	virtual void add(const int& rhs);
	//virtual void remove(int& rhs);
	virtual bool contains(const int& rhs);
private:
	struct Node {
		int* data;
		size_t size;
		Node* next;
		Node* prev;

		Node(size_t& nodecop) {
			size = 0;
			data = new int[nodecop];
			next = nullptr;
			prev = nullptr;
		}
	};
	Node* head;
	Node* tail;
	size_t nodeCapacity;
};

void CustomContainer::add(const int& rhs) {
	if (head == nullptr) {
		Node* adding = new Node(nodeCapacity);
		adding->data[0] = rhs;
		adding->size += 1;
		head = adding;
		tail = adding;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		if (temp->size != nodeCapacity) {
			temp->data[temp->size + 1] = rhs;
			temp->size += 1;
		}
	}
}

bool CustomContainer::contains(const int& rhs) {
	Node* temp = head;
	for (int i = 0; i < temp->size; ++i) {
		if (temp->data[i] == rhs) {
			return true;
		}
	}
	while (temp->next != nullptr) {
		for (int i = 0; i < temp->size; ++i) {
			if (temp->data[i] == rhs) {
				return true;
			}
		}
		temp = temp->next;
	}
	return false;
}