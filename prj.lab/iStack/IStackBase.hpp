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

/*Я правда не понимаю, как это должно работать. Не получается настроить, использование приватных полей в реализации.
Выдаёт ошибку на head_, tail_ в StackLStT и с data_ в StackArrT.
Почему то одна и та же реализация, не проходит одни и те же тесты в test_StackArrT  и в test_StackLstT*/

