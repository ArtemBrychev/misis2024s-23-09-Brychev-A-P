#pragma once

#include <iostream>
#include <cstddef>

template <typename T>
class  IStakBase{
public:
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual T& top() const = 0;
    virtual void swap(IStakBase<T>& rhs) = 0;
    virtual void merge(IStakBase<T>& rhs) = 0;

    virtual bool empty() const = 0;
    virtual std::ptrdiff_t size() const = 0;

    virtual void printToStream(std::ostream& os) const = 0;

    std::ptrdiff_t size_;
    std::ptrdiff_t i_top_;
    T* data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const IStakBase<T>& obj) {
    obj.printToStream(os);
    return os;
}

/*� ������ �� �������, ��� ��� ������ ��������. �� ���������� ���������, ������������� ��������� ����� � ����������.
����� ������ �� head_, tail_ � StackLStT � � data_ � StackArrT.
������ �� ���� � �� �� ����������, �� �������� ���� � �� �� ����� � test_StackArrT  � � test_StackLstT*/

