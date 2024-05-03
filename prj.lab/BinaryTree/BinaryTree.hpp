#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stdexcept>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    // Конструктор
    BinarySearchTree() = default;

    // Деструктор
    ~BinarySearchTree() = default;

    // Метод для получения корневого узла дерева
    TreeNode* root();

    // Метод для добавления узла в дерево
    void add(int data);

    // Метод для проверки наличия узла в дереве
    bool has(int data);

    // Метод для поиска узла в дереве
    TreeNode* find(int data);

    // Метод для удаления узла из дерева
    void remove(int data);
    //найти ноду
    // если лист - просто удалить
    // если у ноду есть один из потомков
    // если есть оба - минимальный узел в правом поддереве заменяет текущую

    // Метод для нахождения минимального значения в дереве
    int min();

    // Метод для нахождения максимального значения в дереве
    int max();

private:
    TreeNode* root_;
    bool root_added = false;
};

TreeNode* BinarySearchTree::root() {
    return root_;
}

void BinarySearchTree::add(int rhs) {
    if (root_added == false) {
        TreeNode* temp = new TreeNode(rhs);
        root_ = temp;
        root_added = true;
    }
    else {
        TreeNode* temp = root_;
        bool addvalue = false;
        while (addvalue == false) {
            if (rhs > temp->data){
                if ((temp->right == nullptr)) {
                    TreeNode* adding = new TreeNode(rhs);
                    temp->right = adding;
                    addvalue = true;
                }
                else if (temp->right != nullptr) {
                    temp = temp->right;
                }
            }
            else if (rhs < temp->data) {
                if (temp->left == nullptr) {
                    TreeNode* adding = new TreeNode(rhs);
                    temp->left = adding;
                    addvalue = true;
                }
                else if (temp->left != nullptr) {
                    temp = temp->left;
                }
            }
            else {
                throw(std::invalid_argument("Adding an existing node"));
            }
        }
    }
}

#endif
