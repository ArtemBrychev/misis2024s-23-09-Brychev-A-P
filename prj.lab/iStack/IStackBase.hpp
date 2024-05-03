#pragma once

#include <iostream>

template <typename T>
class  IStakBase{
public:
	IStakBase() = default;//
	~IStakBase();//
	IStakBase(const IStakBase<T>& other);//
	IStakBase(IStakBase<T>&& other);//
	IStakBase(const std::initializer_list<T>& list);//

	void virtual push(const T& value);//
	void pop();//
	T& top() const;//
	void swap(IStakBase<T>& other);
	void merge(IStakBase<T>& other);

	bool empty() const;//
	std::ptrdiff_t size() const;//

	bool operator==(const IStakBase<T>& rhs) const;//
	bool operator!=(const IStakBase<T>& rhs) const;//

	IStakBase<T>& operator=(const IStakBase<T>& rhs) noexcept;//
	IStakBase<T>& operator=(IStakBase<T>&& other);
};
