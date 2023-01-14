/**
 * @file RBTreeNode.inl
 * @brief This file contains the implementation of the RBTreeNode class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "RBTreeNode.hpp"


// constructor
RBTreeNode::RBTreeNode(sptr_TreeNodeObject obj) : TreeNode{obj} {}

// getters and setters
int RBTreeNode::getKey() const {
    return obj->getKey();
}
RBTreeNode::Color RBTreeNode::getColor() const {
    return color;
}
void RBTreeNode::setColor(RBTreeNode::Color color) {
    this->color = color;
}
sptr_RBTreeNode RBTreeNode::getLeft() const {
    return std::static_pointer_cast<RBTreeNode>(left);
}
sptr_RBTreeNode RBTreeNode::getRight() const {
    return std::static_pointer_cast<RBTreeNode>(right); 
}
sptr_RBTreeNode RBTreeNode::getParent() const {
    return std::static_pointer_cast<RBTreeNode>(parent); 
}
