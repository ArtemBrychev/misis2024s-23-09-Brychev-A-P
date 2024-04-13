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
    void pop();//
    T& top() const;//
    void swap(StackLstT<T>& other);
    void merge(StackLstT<T>& other);

    //don't forget to delete this function-*
    void display();
    //for test purpose only.

    bool empty() const;//
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

//but i really want to keep it.
template <typename T>
void StackLstT<T>::display() {
    std::cout << "Stack size is: " << size() << ". And it contains: ";
    Node* temp = head_;
    while (temp->next != nullptr) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << temp->value << std::endl;
}
//I won't.

template <typename T>
void StackLstT<T>::pop() {
    Node* temp = head_;
    while (temp->next != tail_) {
        temp = temp->next;
    }
    delete tail_;
    size_ -= 1;
    temp->next = nullptr;
    tail_ = temp;
}

template <typename T>
bool StackLstT<T>::empty() const {
    if(size_ == 0){
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
bool StackLstT<T>::operator==(const StackLstT<T>& other) const{
}

#endif 
