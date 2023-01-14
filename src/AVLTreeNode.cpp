/**
 * @file AVLTreeNode.inl
 * @brief This class implements AVLTreeNode
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <memory>
#include "AVLTreeNode.hpp"


// constructors and destructor
AVLTreeNode::AVLTreeNode(sptr_TreeNodeObject obj) : TreeNode(obj) {}
AVLTreeNode::~AVLTreeNode() = default;

// getters
sptr_AVLTreeNode AVLTreeNode::getLeft() const {
    return std::static_pointer_cast<AVLTreeNode>(left);
}

sptr_AVLTreeNode AVLTreeNode::getRight() const{
    return std::static_pointer_cast<AVLTreeNode>(right);
}

sptr_AVLTreeNode AVLTreeNode::getParent() const {
    return std::static_pointer_cast<AVLTreeNode>(parent);
}

int AVLTreeNode::getHeight() const {
    return height;
}

// setters
void AVLTreeNode::setHeight(int h) {
    height = h;
}

