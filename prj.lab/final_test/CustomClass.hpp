#pragma once
#include "IContainerBase2.hpp"
#include "iostream"

struct Node {
	std::pair<int, int> value;
	Node* prev;
	Node* next;
};

bool compareNodes(const std::pair<int, int>& a, const std::pair<int, int>& b){
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

class CustomContainer : public IContainerBase2 {
public:
	CustomContainer() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
    ~CustomContainer() override {
        while (tail) {
            Node* prev = tail->prev;
            delete tail;
            tail = prev;
        }
        head = nullptr;
        size = 0;
    }
	virtual void add(const std::pair<int, int>& value);
	virtual void remove(const std::pair<int, int>& value);
	virtual bool contains(const std::pair<int, int>& value) const;
    size_t getSize() const;
    Node* getHead() const;
    Node* getTail() const;
private:
	Node* head;
	Node* tail;
	size_t size;
};

void CustomContainer::add(const std::pair<int, int>& value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!head) {
        head = tail = newNode;
    }
    else {
        Node* temp = head;
        while (temp && compareNodes(temp->value, value)) {
            temp = temp->next;
        }
        if (!temp) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev) {
                temp->prev->next = newNode;
            }
            else {
                head = newNode;
            }
            temp->prev = newNode;
        }
    }
    ++size;
}

void CustomContainer::remove(const std::pair<int, int>& value){
    Node* temp = head;
    while (temp) {
        if (temp->value == value) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            else {
                head = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            else {
                tail = temp->prev;
            }
            delete temp;
            --size;
            return;
        }
        temp = temp->next;
    }
}

bool CustomContainer::contains(const std::pair<int, int>& value) const{
    Node* temp = head;
    while (temp) {
        if (temp->value == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

size_t CustomContainer::getSize() const{
    return size;
}

Node* CustomContainer::getHead() const {
    return head;
}

Node* CustomContainer::getTail() const {
    return tail;
}