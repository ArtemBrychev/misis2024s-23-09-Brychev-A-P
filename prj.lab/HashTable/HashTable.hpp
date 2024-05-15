#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>

template<typename KeyType, typename ValueType>
class hashTable {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType& k, const ValueType& v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<Node*> table;
    std::hash<KeyType> hash_function;

public:

    void insert(const KeyType& key, const ValueType& value);
    bool contains(const KeyType& key) const;
    ValueType& operator[](const KeyType& key);

        class Iterator {
        private:
            size_t index;
            Node* current;
            const std::vector<Node*>& table;

        public:
            Iterator(size_t i, Node* node, const std::vector<Node*>& tbl);
            Iterator& operator++();
            bool operator!=(const Iterator& other) const;
            std::pair<const KeyType&, ValueType&> operator*() const;


            Iterator begin() const;
            Iterator end() const;
    };
};

template <typename KeyType, typename ValueType>
void hashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    if (table.size() == 0) {
        for (int i = 0; i < 15; ++i) {
            table.push_back(nullptr);
        }
    }
    std::size_t index = hash_function(key) % 15;
    if (table[index] == nullptr) {
        Node* temp = new Node(key,  value);
        table[index] = temp;
    }
    else {
        Node* temp = table[index]->next;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        Node* adding = new Node(key,  value);
        temp->next = adding;
    }
}

template <typename KeyType, typename ValueType>
bool hashTable<KeyType, ValueType>::contains(const KeyType& key) const{
    std::size_t index = hash_function(key) % 15;
    Node* temp = table[index];
    if (temp != nullptr) {
        while (temp->key != key && temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->key == key) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

template <typename KeyType, typename ValueType>
ValueType& hashTable<KeyType, ValueType>::operator[](const KeyType& key) {
    if (contains(key) == true) {
        std::size_t index = hash_function(key) % 15;
        Node* temp = table[index];
        while (temp->key != key) {
            temp = temp->next;
        }
        return temp->value;
    }
    else {
        throw(std::invalid_argument("Returning value of non-existing key"));
    }
}