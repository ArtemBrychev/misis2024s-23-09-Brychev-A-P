#pragma once
#ifndef STACKARRT_HPP
#define STACKARRT_HPP
#include <iostream>
#include <cstddef>
#include <stdexcept>


template <typename T>
class StackArrT {
public:
	StackArrT();
	~StackArrT();
	StackArrT(std::ptrdiff_t rhs);//
	StackArrT(const StackArrT<T>& other);//
	StackArrT(StackArrT<T>&& other);
	///StackArrT(const std::initializer_list<T>& list);

	void push(const T& value);//
	void pop();//
	T& top() const;//
	void swap(StackArrT<T>& other);
	void merge(StackArrT<T>& other);

	bool empty() const;//
	std::ptrdiff_t size() const;//

	bool operator==(const StackArrT<T>& rhs) const;//
	bool operator!=(const StackArrT<T>& rhs) const;//

	StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;//
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
StackArrT<T>::StackArrT(const StackArrT<T>& other) {
	this->size_ = other.size();
	this->data_ = new T[other.size()];
	for (int i = 0; i <= other.i_top_; ++i) {
		this->push(other.data_[i]);
	}
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

template <typename T>
bool StackArrT<T>::empty() const{
	if (i_top_ == -1) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) noexcept {
	if (this->empty() == true) {
		for (int i = 0; i <= rhs.i_top_; ++i) {
			this->push(rhs.data_[i]);
		}
		return *this;
	}
	else if (this->size() == rhs.size()) {
		for (int i = 0; i <= rhs.i_top_; ++i) {
			std::cout << data_[i] << ' ' << rhs.data_[i] << std::endl;;
			this->data_[i] = rhs.data_[i];
		}
		this->i_top_ = rhs.i_top_;
		return *this;
	}
}

template <typename T>
void StackArrT<T>::merge(StackArrT<T>& other) {
	StackArrT<T> temp(this->size() + other.size());
}

template <typename T>
bool StackArrT<T>::operator==(const StackArrT<T>& other) const {
	if (this->i_top_ == other.i_top_) {
		for (int i = 0; i <= i_top_; i++) {
			if (data_[i] != other.data_[i]) {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}

template <typename T>
bool StackArrT<T>::operator!=(const StackArrT<T>& other) const {
	if (*this == other) {
		return false;
	}
	else {
		return true;
	}
}

template <typename T>
void StackArrT<T>::swap(StackArrT<T>& other) {
	T* temp = new T[i_top_];
	for (int i = 0; i <= i_top_; i++) {
		temp[i] = data_[i];
	}

}

#endif
