#pragma once

#include <iostream>

template <typename T>
class  IStakBase{
public:
    virtual void push(const T& value) = 0;
    //virtual void pop() = 0;
    virtual T& top() const = 0;
    virtual void swap(IStakBase<T>& rhs);
    //virtual void merge() = 0;

    //virtual bool empty() const = 0;
    virtual std::ptrdiff_t size() const = 0;

    //virtual bool operator==(const IStakBase& rhs) const = 0;
    //virtual bool operator!=(const IStakBase& rhs) const = 0;

    //virtual IStakBase<T>& operator=(const IStakBase& rhs) noexcept = 0;
    //virtual IStakBase<T>& operator=(const IStakBase&& rhs) = 0;
};

