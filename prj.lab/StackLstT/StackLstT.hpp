#pragma once
#ifndef STACKLSTT_HPP
#define STACKLSTT_HPP
#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T>
class StackLstT {
public:
    StackLstT() = default;
    ~StackLstT() = default;
    StackLstT(const StackLstT<T>& other);
    StackLstT(StackLstT<T>&& other);
    StackLstT(const std::initializer_list<T>& list);

    void push(const T& value);//
    void pop();
    T& top() const;//
    void swap(StackLstT<T>& other);
    void merge(StackLstT<T>& other);

    bool empty() const;
    std::ptrdiff_t size() const;//

    bool operator==(const StackLstT<T>& rhs) const;
    bool operator!=(const StackLstT<T>& rhs) const;

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept;
    StackLstT<T>& operator=(StackLstT<T>&& other);

private:
    std::ptrdiff_t size_ = 0;
    struct Node {
        T value;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

template <typename T>
void StackLstT<T>::push(const T& value) {
    if (this->size() == 0) {
        Node* temp = new Node;
        temp->value = value;
        head_ = temp;
        tail_ = temp;
        size_ += 1;
    }
    else {
        Node* temp = new Node;
        tail_->next = temp;
        temp->value = value;
        tail_ = temp;
        size_ += 1;
    }
}

template <typename T>
std::ptrdiff_t StackLstT<T>::size() const {
    return size_;
}

template <typename T>
T& StackLstT<T>::top() const {
    T top = tail_->value;
    return top;
}

template <typename T>
void StackLstT<T>::pop() {
    int i = 0;
    T temp;
    Node* pointer_index = head_;
    while (i <= size_ - 2) {
        if (i != size_ - 2) {
            Node* temp = pointer_index->next;
            Node* prev = 
            pointer_index = temp;
        }
        else {
            tail_ = pointer_index;
            tail_->next = nullptr;
        }
    }
}

#endif 
