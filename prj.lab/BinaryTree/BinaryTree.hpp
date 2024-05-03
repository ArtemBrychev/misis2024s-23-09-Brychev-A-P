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
    // �����������
    BinarySearchTree() = default;

    // ����������
    ~BinarySearchTree() = default;

    // ����� ��� ��������� ��������� ���� ������
    TreeNode* root();

    // ����� ��� ���������� ���� � ������
    void add(int data);

    // ����� ��� �������� ������� ���� � ������
    bool has(int data);

    // ����� ��� ������ ���� � ������
    TreeNode* find(int data);

    // ����� ��� �������� ���� �� ������
    void remove(int data);
    //����� ����
    // ���� ���� - ������ �������
    // ���� � ���� ���� ���� �� ��������
    // ���� ���� ��� - ����������� ���� � ������ ��������� �������� �������

    // ����� ��� ���������� ������������ �������� � ������
    int min();

    // ����� ��� ���������� ������������� �������� � ������
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
