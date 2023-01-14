/**
 * @file TreeNode.cpp
 * @brief This file contains the implementation of the TreeNode class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "TreeNode.hpp"

// constructor and destructor
TreeNode::TreeNode(sptr_TreeNodeObject obj) : obj(obj) {}
TreeNode::~TreeNode() = default;


// getters
int TreeNode::getObjKey() const { return obj->getKey(); }
sptr_TreeNodeObject TreeNode::getObj() const { return obj; }
sptr_TreeNode TreeNode::getLeft() const { return left; }
sptr_TreeNode TreeNode::getRight() const { return right; }
sptr_TreeNode TreeNode::getParent() const { return parent; }

// setters
void TreeNode::setObj(sptr_TreeNodeObject obj) { this->obj = obj; }
void TreeNode::setLeft(sptr_TreeNode left) { this->left = left; }
void TreeNode::setRight(sptr_TreeNode right) { this->right = right; }
void TreeNode::setParent(sptr_TreeNode parent) { this->parent = parent; }

// operators
std::ostream& operator<<(std::ostream &s, const TreeNode &node) {
    return s << (&node)->getObjKey();
}
