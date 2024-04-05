#pragma once
#ifndef STACKARRT_HPP
#define STACKARRT_HPP
#include <cstddef>
#include <stdexcept>


template <typename T>
class StackArrT {
public:
	StackArrT();
	~StackArrT();
	StackArrT(std::ptrdiff_t rhs);//
	StackArrT(const StackArrT<T>& other);
	StackArrT(StackArrT<T>&& other);
	///StackArrT(const std::initializer_list<T>& list);

	void push(const T& value);//
	void pop();//
	T& top() const;//
	void swap(StackArrT<T>& other);
	void merge(StackArrT<T>& other);

	bool empty() const;
	std::ptrdiff_t size() const;//

	bool operator==(const StackArrT<T>& rhs) const;
	bool operator!=(const StackArrT<T>& rhs) const;

	StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;
	StackArrT<T>& operator=(StackArrT<T>&& other);
private:
	std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
	std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
	T* data_ = nullptr;   //!< элементы стека
};

template <typename T>
StackArrT<T>::StackArrT(std::ptrdiff_t rhs) {
	this->size_ = rhs;
	this->data_ = new T[rhs];
}

template <typename T>
std::ptrdiff_t StackArrT<T>::size() const {
	return size_;
}

template <typename T>
StackArrT<T>::~StackArrT() {
	delete[] data_;
	data_ = nullptr;
}

template <typename T>
void StackArrT<T>::push(const T& value) {
	if (i_top_ + 1 < size_) {
		data_[i_top_ + 1] = value;
		i_top_ += 1;
	}
	else {
		throw std::invalid_argument("Stack overflow");
	}
}

template <typename T>
T& StackArrT<T>::top() const{
	return data_[i_top_];
}

template <typename T>
void StackArrT<T>::pop() {
	int h = i_top_;
	i_top_ -= 1;
}


#endif
