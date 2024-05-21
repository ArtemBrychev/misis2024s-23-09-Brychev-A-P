#pragma once

class IContainerBase{
public:
	IContainerBase() = default;
	~IContainerBase() = default;
	virtual void add(const int& rhs) = 0;
	//virtual void remove(int& rhs) = 0;
	virtual bool contains(const int& rhs) = 0;
};