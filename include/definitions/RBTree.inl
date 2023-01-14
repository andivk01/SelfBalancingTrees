/**
 * @file RBTree.inl
 * @brief This file contains the implementation of the RBTree class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "RBTree.hpp"
#include "RBTreeNode.hpp"

const RBTreeNode::Color COL_RED = RBTreeNode::Color::RED;
const RBTreeNode::Color COL_BLACK = RBTreeNode::Color::BLACK;

// constuctors and destructors
template <bool CMP(const int& key1, const int& key2)>
RBTree<CMP>::RBTree() {
    nil = std::make_shared<RBTreeNode>(nullptr);
    nil->setColor(COL_BLACK);
    this->root = nil;
    this->nullValue = nil;
}

template <bool CMP(const int& key1, const int& key2)>
RBTree<CMP>::RBTree(sptr_RBTreeNode root) : RBTree() {
    insert(root);
}

template <bool CMP(const int& key1, const int& key2)>
RBTree<CMP>::~RBTree() {}

// getters
template <bool CMP(const int& key1, const int& key2)>
sptr_RBTreeNode RBTree<CMP>::getRoot() const {
    return std::static_pointer_cast<RBTreeNode>(this->root);
}

template <bool CMP(const int& key1, const int& key2)>
sptr_RBTreeNode RBTree<CMP>::getNil() const {
    return std::static_pointer_cast<RBTreeNode>(this->nil);
}

// core functionalities
template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::insert(sptr_RBTreeNode&& node) {
    BinarySearchTree<CMP>::insert(node);
    if (this->numOfNodes == 1) {
        node->setParent(this->nil);
    }
    node->setColor(COL_RED);
    node->setRight(this->nil);
    node->setLeft(this->nil);
    insFixUp(node);
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::insert(sptr_TreeNodeObject&& obj) { 
    this->insert(std::make_shared<RBTreeNode>(obj));
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::insert(TreeNodeObject* obj) {
    this->insert(std::shared_ptr<TreeNodeObject>(obj));
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::remove(sptr_RBTreeNode node) {
    sptr_RBTreeNode tmp = node;
    RBTreeNode::Color tmpOriginalColor = tmp->getColor();
    sptr_RBTreeNode tmp2;
    if (node->getLeft() == nil) {
        tmp2 = node->getRight();
        transplant(node, node->getRight());
    } else if (node->getRight() == nil) {
        tmp2 = node->getLeft();
        transplant(node, node->getLeft());
    } else {
        removeWithTwoChildren(node, tmp, tmp2, tmpOriginalColor);
    }
    if (tmpOriginalColor == COL_BLACK) {
        delFixUp(tmp2);
    }
    --(this->numOfNodes);
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::removeWithTwoChildren(sptr_RBTreeNode& node, sptr_RBTreeNode& tmp, sptr_RBTreeNode& tmp2, RBTreeNode::Color& tmpOriginalColor) {
    tmp = minimum(node->getRight());
    tmpOriginalColor = tmp->getColor();
    tmp2 = tmp->getRight();
    if (tmp->getParent() == node) {
        tmp2->setParent(tmp);
    } else {
        transplant(tmp, tmp->getRight());
        tmp->setRight(node->getRight());
        tmp->getRight()->setParent(tmp);
    }
    transplant(node, tmp);
    tmp->setLeft(node->getLeft());
    tmp->getLeft()->setParent(tmp);
    tmp->setColor(node->getColor());
}


template <bool CMP(const int& key1, const int& key2)>
sptr_RBTreeNode RBTree<CMP>::search(int key) {
    sptr_TreeNode node = BinarySearchTree<CMP>::search(key);
    return std::static_pointer_cast<RBTreeNode>(node);
}

template <bool CMP(const int& key1, const int& key2)>
sptr_RBTreeNode RBTree<CMP>::minimum(sptr_RBTreeNode root) const {
    return std::static_pointer_cast<RBTreeNode>(BinarySearchTree<CMP>::minimum(root));
}
template <bool CMP(const int& key1, const int& key2)>
inline sptr_RBTreeNode RBTree<CMP>::minimum() const {
    return std::static_pointer_cast<RBTreeNode>(BinarySearchTree<CMP>::minimum());
}
template <bool CMP(const int& key1, const int& key2)>
sptr_RBTreeNode RBTree<CMP>::maximum(sptr_RBTreeNode root) const {
    return std::static_pointer_cast<RBTreeNode>(BinarySearchTree<CMP>::maximum(root));
}
template <bool CMP(const int& key1, const int& key2)>
inline sptr_RBTreeNode RBTree<CMP>::maximum() const {
    return std::static_pointer_cast<RBTreeNode>(BinarySearchTree<CMP>::maximum());
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::transplant(sptr_RBTreeNode curr_node, sptr_RBTreeNode new_node) {
    if (curr_node->getParent() == nil) {
        this->root = new_node;
    } else if (curr_node == curr_node->getParent()->getLeft()) {
        curr_node->getParent()->setLeft(new_node);
    } else {
        curr_node->getParent()->setRight(new_node);
    }
    new_node->setParent(curr_node->getParent());
}

// fixers
template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::insFixUp(sptr_RBTreeNode node) {
    while (node->getParent()->getColor() == COL_RED) {
        if (!insFixUpRedUncle(node)) {
            if (!insFixUpBlackUncleLeft(node)) {
                insFixUpBlackUncleRight(node);
            }
        }
    }
    
    this->getRoot()->setColor(COL_BLACK);
}

template <bool CMP(const int& key1, const int& key2)>
bool RBTree<CMP>::insFixUpRedUncle(sptr_RBTreeNode& node) {
    sptr_RBTreeNode grandparent = node->getParent()->getParent(); 
    sptr_RBTreeNode uncle = grandparent->getLeft(); 
    if (node->getParent() == grandparent->getLeft()) { 
        uncle = grandparent->getRight(); 
    }
    if (uncle->getColor() == COL_RED) { // common code that would be executed regardless of which case we are in (left or right)
        node->getParent()->setColor(COL_BLACK);
        uncle->setColor(COL_BLACK);
        grandparent->setColor(COL_RED);
        node = grandparent;
        return true;
    }
    return false; // execute the insFixUpBlackUncleLeft or insFixUpBlackUncleRight next
}

template <bool CMP(const int& key1, const int& key2)>
bool RBTree<CMP>::insFixUpBlackUncleLeft(sptr_RBTreeNode& node) {
    sptr_RBTreeNode grandparent = node->getParent()->getParent();
    if (node->getParent() == grandparent->getLeft()) {
        if (node == node->getParent()->getRight()) {
            node = node->getParent();
            rotateLeft(node);
        }
        node->getParent()->setColor(COL_BLACK);
        grandparent->setColor(COL_RED);
        rotateRight(grandparent);
        return true;
    }
    return false;
}

template <bool CMP(const int& key1, const int& key2)>
bool RBTree<CMP>::insFixUpBlackUncleRight(sptr_RBTreeNode& node) {
    sptr_RBTreeNode grandparent = node->getParent()->getParent();
    if (node->getParent() == grandparent->getRight()) {
        if (node == node->getParent()->getLeft()) {
            node = node->getParent();
            this->rotateRight(node);
        }
        node->getParent()->setColor(COL_BLACK);
        grandparent->setColor(COL_RED);
        this->rotateLeft(grandparent);
        return true;
    }
    return false;
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::delFixUp(sptr_RBTreeNode node) {
    while (node != getRoot() && node->getColor() == COL_BLACK) {
        if (node == node->getParent()->getLeft()) {
            delFixUpLeft(node);
        } else {
            delFixUpRight(node);
        }
    }
    node->setColor(COL_BLACK);
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::delFixUpLeft(sptr_RBTreeNode& node) {
    sptr_RBTreeNode sibling = node->getParent()->getRight();
    if (sibling->getColor() == COL_RED) {
        sibling->setColor(COL_BLACK);
        node->getParent()->setColor(COL_RED);
        this->rotateLeft(node->getParent());
        sibling = node->getParent()->getRight();
    }
    if (sibling->getLeft()->getColor() == COL_BLACK && sibling->getRight()->getColor() == COL_BLACK) {
        sibling->setColor(COL_RED);
        node = node->getParent();
    } else {
        if (sibling->getRight()->getColor() == COL_BLACK) {
            sibling->getLeft()->setColor(COL_BLACK);
            sibling->setColor(COL_RED);
            this->rotateRight(sibling);
            sibling = node->getParent()->getRight();
        }
        sibling->setColor(node->getParent()->getColor());
        node->getParent()->setColor(COL_BLACK);
        sibling->getRight()->setColor(COL_BLACK);
        this->rotateLeft(node->getParent());
        node = getRoot();
    }
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::delFixUpRight(sptr_RBTreeNode& node) {
    sptr_RBTreeNode sibling = node->getParent()->getLeft();
    if (sibling->getColor() == COL_RED) {
        sibling->setColor(COL_BLACK);
        node->getParent()->setColor(COL_RED);
        this->rotateRight(node->getParent());
        sibling = node->getParent()->getLeft();
    }
    if (sibling->getRight()->getColor() == COL_BLACK && sibling->getLeft()->getColor() == COL_BLACK) {
        sibling->setColor(COL_RED);
        node = node->getParent();
    } else {
        if (sibling->getLeft()->getColor() == COL_BLACK) {
            sibling->getRight()->setColor(COL_BLACK);
            sibling->setColor(COL_RED);
            this->rotateLeft(sibling);
            sibling = node->getParent()->getLeft();
        }
        sibling->setColor(node->getParent()->getColor());
        node->getParent()->setColor(COL_BLACK);
        sibling->getLeft()->setColor(COL_BLACK);
        this->rotateRight(node->getParent());
        node = getRoot();
    }
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::rotateLeft(sptr_RBTreeNode node) {
    SelfBalancingTree<CMP>::rotateLeft(node);
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::rotateRight(sptr_RBTreeNode node) {
    SelfBalancingTree<CMP>::rotateRight(node);
}

// print tree structure
template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::prettyPrint(const std::string& prefix, sptr_RBTreeNode node, bool isLeft) const {
    if (node != nullptr && node != nil) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->getObjKey() << ((node->getColor() == COL_RED) ? "R":"B")<< std::endl;
        // enter the next tree level - left and right branch
        prettyPrint( prefix + (isLeft ? "│   " : "    "), node->getRight(), true);
        prettyPrint( prefix + (isLeft ? "│   " : "    "), node->getLeft(), false);
    } else if (node == nil) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << "NIL" << std::endl;
    }
}

template <bool CMP(const int& key1, const int& key2)>
void RBTree<CMP>::prettyPrint() const {
    prettyPrint("", getRoot(), false);
}
