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
    BinarySearchTree() = default;//

    // Деструктор
    ~BinarySearchTree() = default;//

    // Метод для получения корневого узла дерева
    TreeNode* root();//

    // Метод для добавления узла в дерево
    void add(int data);//

    // Метод для проверки наличия узла в дереве
    bool has(int data);//

    // Метод для поиска узла в дереве
    TreeNode* find(int data);//

    // Метод для удаления узла из дерева
    void remove(int data);
    //найти ноду
    // если лист - просто удалить
    // если у ноду есть один из потомков
    // если есть оба - минимальный узел в правом поддереве заменяет текущую

    // Метод для нахождения минимального значения в дереве
    int min();//

    // Метод для нахождения максимального значения в дереве
    int max();//

private:
    TreeNode* root_;
    bool root_added = false;
};

TreeNode* BinarySearchTree::root() {
    if (root_added == true) {
        return root_;
    }
    else {
        throw(std::invalid_argument("Doesn't have root"));
    }
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

bool BinarySearchTree::has(int rhs) {
    if (rhs == root_->data && root_added != false) {
        return true;
    }
    else if (root_->data == rhs && root_added == false){
        return false;
    }
    TreeNode* temp = root_;
    bool answer = false;
    while (temp != nullptr) {
        if (rhs == temp->data) {
            return true;
        }
        else if (rhs > temp->data) {
            temp = temp->right;
        }
        else if (rhs < temp->data) {
            temp = temp->left;
        }
    }
    return answer;
}

TreeNode* BinarySearchTree::find(int rhs) {
    if (root_->data == rhs && root_added != false) {
        return root_;
    }
    else if (root_->data == rhs && root_added == false){
        throw std::invalid_argument("There is no such node");
    }
    TreeNode* temp = root_;
    bool answer = false;
    while (temp != nullptr) {
        if (rhs == temp->data) {
            answer = true;
            return temp;
        }
        else if (rhs > temp->data) {
            temp = temp->right;
        }
        else if (rhs < temp->data) {
            temp = temp->left;
        }
    }
    if (answer == false) {
        throw std::invalid_argument("There is no such node");
    }
}

int BinarySearchTree::min() {
    TreeNode* temp = root_;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->data;
}

int BinarySearchTree::max() {
    TreeNode* temp = root_;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->data;
}

void BinarySearchTree::remove(int rhs) {
    TreeNode* needed = find(rhs);
    if (needed->left == nullptr && needed->right == nullptr) {
        /*Случай: лист*/
        TreeNode* temp = root_;
        if (needed == root_) {
            root_added = false;
        }
        else {
            while (temp->right != needed && temp->left != needed) {
                if (rhs > temp->data) {
                    temp = temp->right;
                }
                else if(rhs < temp->data){
                    temp = temp->left;
                }
            }
            if (temp->left == needed) {
                temp->left = nullptr;
                delete needed;
            }
            else if(temp->right == needed){
                temp->right = nullptr;
                delete needed;
            }
        }
    }
    else if (needed->left != nullptr && needed->right == nullptr) {
        /*Случай: есть нода слева*/
        TreeNode* temp = root_;
        if (needed == root_) {
            root_ = root_->left;
        }
        else {
            while (temp->right != needed && temp->left != needed) {
                if (rhs > temp->data) {
                    temp = temp->right;
                }
                else if (rhs < temp->data) {
                    temp = temp->left;
                }
            }
            if (temp->left == needed) {
                temp->left = needed->left;
                delete needed;
            }
            else if (temp->right == needed) {
                temp->right = needed->left;
                delete needed;
            }
        }
    }
    else if (needed->left == nullptr && needed->right != nullptr) {
        /*Случай: есть нода справа*/
        TreeNode* temp = root_;
        if (needed == root_) {
            root_ = root_->left;
        }
        else {
            while (temp->right != needed && temp->left != needed) {
                if (rhs > temp->data) {
                    temp = temp->right;
                }
                else if (rhs < temp->data) {
                    temp = temp->left;
                }
            }
            if (temp->left == needed) {
                temp->left = needed->right;
                delete needed;
            }
            else if (temp->right == needed) {
                temp->right = needed->right;
                delete needed;
            }
        }
    }
    else if (needed->left != nullptr && needed->right != nullptr) {
        /*Слечай: есть обе ноды*/
        if (needed == root_) {
            TreeNode* temp = root_->right;
            if (temp->left != nullptr) {
                while (temp->left->left != nullptr) {
                    temp = temp->left;
                }
                int fck = temp->left->data;
                remove(temp->left->data);
                root_->data = fck;
            }
            else {
                int fck = temp->data;
                remove(temp->data);
                root_->data = fck;
            }
        }
        else {
            TreeNode* temp = needed->right;
            if (temp->left != nullptr) {
                while (temp->left->left != nullptr) {
                    temp = temp->left;
                }
                int fck = temp->left->data;
                remove(temp->left->data);
                needed->data == fck;
            }
            else {
                int fck = temp->data;
                remove(temp->data);
                needed->data = fck;
            }
        }
    }
}


#endif
