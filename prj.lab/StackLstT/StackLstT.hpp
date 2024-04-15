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

    void push(const T& value);
    void pop();
    T& top() const;
    void swap(StackLstT<T>& other);
    void merge(StackLstT<T>& other);

    //don't forget to delete this function
    void display();
    //for test purpose only.

    bool empty() const;
    std::ptrdiff_t size() const;

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
StackLstT<T>::StackLstT(const StackLstT<T>& other) {
    Node* temp = other.head_;
    while (temp) {
        push(temp->value);
        temp = temp->next;
    }
}

template <typename T>
StackLstT<T>::StackLstT(StackLstT<T>&& other) {
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
}
template <typename T>
StackLstT<T>::StackLstT(const std::initializer_list<T>& list) {
    for (auto x : list) {
        push(x);
    }
}

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
    return tail_->value;
}

//I really want to keep this function.
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
//And I will.

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
bool StackLstT<T>::operator==(const StackLstT<T>& rhs) const {
    if (size_ != rhs.size_) {
        return false;
    }

    Node* curr_lhs = head_;
    Node* curr_rhs = rhs.head_;
    while (curr_lhs) {
        if (curr_lhs->value != curr_rhs->value) {
            return false;
        }
        curr_lhs = curr_lhs->next;
        curr_rhs = curr_rhs->next;
    }

    return true;
}

template <typename T>
bool StackLstT<T>::operator!=(const StackLstT<T>& rhs) const {
    return !(*this == rhs);
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& rhs) noexcept {
    if (this != &rhs) {
        Node* curr = head_;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        size_ = 0;

        curr = rhs.head_;
        while (curr) {
            push(curr->value);
            curr = curr->next;
        }
    }
    return *this;
}

template <typename T>
void StackLstT<T>::swap(StackLstT<T>& other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
}

template <typename T>
void StackLstT<T>::merge(StackLstT<T>& other) {
    if (other.size_ == 0) {
        return;
    }

    if (size_ == 0) {
        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
    }
    else {
        tail_->next = other.head_;
        tail_ = other.tail_;
        size_ += other.size_;
    }

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}
#endif 
