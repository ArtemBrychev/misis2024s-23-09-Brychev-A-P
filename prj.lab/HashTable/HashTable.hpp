#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <utility>

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
    hashTable() {
        for (int i = 0; i < 16; ++i) {
            table.push_back(nullptr);
        }
    }

    void insert(const KeyType& key, const ValueType& value);
    bool contains(const KeyType& key) const;
    ValueType& operator[](const KeyType& key);

        class Iterator {
        private:
            size_t index;
            Node* current;
            const std::vector<Node*>& table;

        public:
            Iterator(size_t i, Node* node, const std::vector<Node*>& tbl) :index(i), current(node), table(tbl) {};

            Iterator& operator++() {
                if (current!=nullptr && current->next != nullptr) {
                    current = current->next;
                }
                //else if(current!=nullptr && current->next == nullptr){
                //    continue;
                //}
                else{
                    size_t j(index + 1);
                    while (table[j] == nullptr && j<table.size() - 1) {
                        ++j;
                    }
                    index = j;
                    current = table[index];
                    //current = table[++index];
                }
                //std::cout << current << std::endl;
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return (current != other.current && index!=other.index);
            }

            std::pair<const KeyType&, ValueType&> operator*() const {
                if (current != nullptr) {
                    std::pair<const KeyType&, ValueType&> key_value_bundle(current->key, current->value);
                    return key_value_bundle;
                }
                else {
                    throw(std::invalid_argument("Unknown error :( "));
                }
            }
        };

        Iterator begin() const {
            int first = 0;
            while (table[first] == nullptr) {
                ++first;
            }
            if (first != 0) {
                return Iterator(first, table[first], table);
            }
            else {
                return Iterator(0, table[0], table);
            }
        }
        Iterator end() const {
            int last = 14;
            while (table[last] == nullptr) {
                --last;
            }
            if (last != 14) {
                return Iterator(15, table[last+1], table);
            }
            else {
                return Iterator(15, table[15], table);
            }
        }

};

template <typename KeyType, typename ValueType>
void hashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    if (contains(key) == false) {
        size_t index = hash_function(key) % 15;
        if (table[index] == nullptr) {
            Node* insertation = new Node(key, value);
            table[index] = insertation;
        }
        else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node* insertation = new Node(key, value);
            temp->next = insertation;
        }
    }
    else {
        throw(std::invalid_argument("Inserting a value with exsiting key"));
    }
}

template <typename KeyType, typename ValueType>
bool hashTable<KeyType, ValueType>::contains(const KeyType& key) const{
    size_t index = hash_function(key) % 15;
    if (table[index] != nullptr) {
        Node* temp = table[index];
        while (temp->next != nullptr) {
            if (temp->key == key) {
                return true;
            }
            else {
                temp = temp->next;
            }
        }
        if(temp->key == key){
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

