/**
 * @file SelfBalancingTree.inl
 * @brief This file contains the implementation of the SelfBalancingTree class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SelfBalancingTree.hpp"
// constructors and destructor
template <bool CMP(const int& key1, const int& key2)>
SelfBalancingTree<CMP>::SelfBalancingTree() {}


template <bool CMP(const int& key1, const int& key2)>
SelfBalancingTree<CMP>::SelfBalancingTree(sptr_TreeNode root)
    : BinarySearchTree<CMP>(root) {}

template <bool CMP(const int& key1, const int& key2)>
SelfBalancingTree<CMP>::~SelfBalancingTree() {};

// rotation methods
template <bool CMP(const int& key1, const int& key2)>
void SelfBalancingTree<CMP>::rotateLeft(sptr_TreeNode node) {
    sptr_TreeNode ptr = node->getRight();
    node->setRight(ptr->getLeft());
    if (ptr->getLeft().get() != this->nullValue.get()) {
        ptr->getLeft()->setParent(node);
    }

    ptr->setParent(node->getParent());
    if (node->getParent().get() == this->nullValue.get()) {
        this->root = ptr;
    } else if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(ptr);
    } else {
        node->getParent()->setRight(ptr);
    }
    ptr->setLeft(node);
    node->setParent(ptr);
}

template <bool CMP(const int& key1, const int& key2)>
void SelfBalancingTree<CMP>::rotateRight(sptr_TreeNode node) {
    sptr_TreeNode ptr = node->getLeft();
    node->setLeft(ptr->getRight());

    if (ptr->getRight().get() != this->nullValue.get()) {
        ptr->getRight()->setParent(node);
    }
    ptr->setParent(node->getParent());
    if (node->getParent().get() == this->nullValue.get()) {
        this->root = ptr;
    } else if (node == node->getParent()->getRight()) {
        node->getParent()->setRight(ptr);
    } else {
        node->getParent()->setLeft(ptr);
    }
    ptr->setRight(node);
    node->setParent(ptr);
}

