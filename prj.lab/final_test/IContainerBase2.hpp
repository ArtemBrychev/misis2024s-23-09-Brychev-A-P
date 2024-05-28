#pragma once
#include <utility>

class IContainerBase2 {
public:
    virtual ~IContainerBase2() = default;

    virtual void add(const std::pair<int, int>& val) = 0;
    virtual void remove(const std::pair<int, int>& val) = 0;
    virtual bool contains(const std::pair<int, int>& val) const = 0;

    virtual size_t getSize() const = 0;
};
