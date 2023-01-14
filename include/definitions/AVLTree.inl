/**
 * @file AVLTree.inl

 * @brief This file contains the implementation of the AVLTree class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "AVLTree.hpp"

// constuctors and destructors
template <bool CMP(const int& key1, const int& key2)>
AVLTree<CMP>::AVLTree() {}

template <bool CMP(const int& key1, const int& key2)>
AVLTree<CMP>::AVLTree(sptr_AVLTreeNode root)
: SelfBalancingTree<CMP>{root} {}

template <bool CMP(const int& key1, const int& key2)>
AVLTree<CMP>::~AVLTree() = default;

// getters
template <bool CMP(const int& key1, const int& key2)>
sptr_AVLTreeNode AVLTree<CMP>::getRoot() const {
    return std::static_pointer_cast<AVLTreeNode>(this->root);
}

// core functions
template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::insert(sptr_AVLTreeNode&& node) {
    BinarySearchTree<CMP>::insert(node); 
    while (node != this->nullValue) { // fix after insertion
        updateHeight(node);
        if (balance(node)) { // the tree requires rebalancing only once
            break;
        }
        node = node->getParent();
    }
}
template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::insert(sptr_TreeNodeObject&& obj) {
    insert(std::make_shared<AVLTreeNode>(obj));
}

template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::insert(TreeNodeObject* obj) {
    insert(std::shared_ptr<TreeNodeObject>(obj));
}

template <bool CMP(const int& key1, const int& key2)>
sptr_AVLTreeNode AVLTree<CMP>::search(int key) {
    sptr_TreeNode node = BinarySearchTree<CMP>::search(key);
    return std::static_pointer_cast<AVLTreeNode>(node);
}

template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::remove(sptr_AVLTreeNode node) {
    sptr_AVLTreeNode deletedNodeAncestor = std::static_pointer_cast<AVLTreeNode>(BinarySearchTree<CMP>::remove(node));
    while (deletedNodeAncestor != this->nullValue) { // fix after deletion
        updateHeight(deletedNodeAncestor);
        balance(deletedNodeAncestor);
        deletedNodeAncestor = deletedNodeAncestor->getParent();
    }
}

// fixers 
template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::updateHeight(sptr_AVLTreeNode& node) {
    int leftHeight = (node->getLeft() == this->nullValue) ? -1 : node->getLeft()->getHeight();
    int rightHeight = (node->getRight() == this->nullValue) ? -1 : node->getRight()->getHeight();
    node->setHeight(std::max(leftHeight, rightHeight) + 1);
}

template <bool CMP(const int& key1, const int& key2)>
int AVLTree<CMP>::balanceFactor(sptr_AVLTreeNode node) { 
    if (node == this->nullValue)
        return 0;
    int leftHeight = (node->getLeft() == this->nullValue) ? -1 : node->getLeft()->getHeight();
    int rightHeight = (node->getRight() == this->nullValue) ? -1 : node->getRight()->getHeight();
    
    return leftHeight - rightHeight;
}

template <bool CMP(const int& key1, const int& key2)>
bool AVLTree<CMP>::balance(sptr_AVLTreeNode& node) { 
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->getLeft()) == -1) { 
            rotateLeft(node->getLeft());
            rotateRight(node);
        } else {
            rotateRight(node);
        }
        return true;
    } else if (balanceFactor(node) == -2) {
        if (balanceFactor(node->getRight()) == 1) {
            rotateRight(node->getRight());
            rotateLeft(node);
        } else {
            rotateLeft(node);
        }
        return true;
    }
    return false;
}

template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::updateOnRotation(sptr_AVLTreeNode& node) {
    sptr_AVLTreeNode parent = node->getParent();
    updateHeight(node);
    updateHeight(parent);
}

// rotation methods
template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::rotateLeft(sptr_AVLTreeNode node) {
    SelfBalancingTree<CMP>::rotateLeft(node);
    updateOnRotation(node);
}
template <bool CMP(const int& key1, const int& key2)>
void AVLTree<CMP>::rotateRight(sptr_AVLTreeNode node) {
    SelfBalancingTree<CMP>::rotateRight(node);
    updateOnRotation(node);
}