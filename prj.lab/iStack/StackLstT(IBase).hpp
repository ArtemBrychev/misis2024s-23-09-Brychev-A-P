#ifndef STACKLSTT_HPP
#define STACKLSTT_HPP
#include "iStack/IStackBase.hpp"
#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T>
class StackLstT : public IStakBase<T> {
public:
    StackLstT() = default;
    ~StackLstT() = default;
    StackLstT(const StackLstT<T>& other);
    StackLstT(StackLstT<T>&& other);
    StackLstT(const std::initializer_list<T>& list);

    void push(const T& value);
    void pop();
    T& top() const;
    virtual void swap(IStakBase<T>& other) override;
    virtual void merge(IStakBase<T>& other) override;

    bool empty() const;
    std::ptrdiff_t size() const;

    bool operator==(const StackLstT<T>& rhs) const ;
    bool operator!=(const StackLstT<T>& rhs) const ;

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept ;
    StackLstT<T>& operator=(StackLstT<T>&& other) ;

    virtual void printToStream(std::ostream& os) const override {
        Node* node = head_;
        while (node != nullptr) {
            os << node->value << " ";
            node = node->next;
        }
    }
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
    T& top = tail_->value;
    return top;
}

template <typename T>
void StackLstT<T>::pop() {
    if (size_ > 1) {
        Node* temp = head_;
        while (temp->next != tail_) {
            temp = temp->next;
        }
        delete tail_;
        size_ -= 1;
        temp->next = nullptr;
        tail_ = temp;
    }
    else if (size_ == 1) {
        size_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
    }
    else {
        throw std::invalid_argument("Error");
    }
}

template <typename T>
bool StackLstT<T>::empty() const {
    if (size_ == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
bool StackLstT<T>::operator==(const StackLstT<T>& rhs) const {
    bool t = true;
    Node* node_1 = rhs.head_;
    Node* node_2 = head_;
    while (node_1 != nullptr && node_2 != nullptr)
    {
        if (node_1->value != node_2->value)
        {
            t = false;
            break;
        }
        node_1 = node_1->next;
        node_2 = node_2->next;
    }
    return (node_1 == nullptr && node_2 == nullptr && t);
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
void StackLstT<T>::swap(IStakBase<T>& other) {
    StackLstT<T> stack_one, stack_two;
    while (empty() == 0) {
        stack_one.push(top());
        pop();
    }
    while (other.empty() == 0) {
        stack_two.push(other.top());
        other.pop();
    }
    while (stack_two.empty() == 0) {
        push(stack_two.top());
        stack_two.pop();
    }
    while (stack_one.empty() == 0) {
        other.push(stack_one.top());
        stack_one.pop();
    }
}

template <typename T>
void StackLstT<T>::merge(IStakBase<T>& other) {
    StackLstT<T> stack;
    while (!other.empty())
    {
        stack.push(other.top());
        other.pop();
    }
    while (!stack.empty())
    {
        push(stack.top());
        stack.pop();
    }
}



#endif

