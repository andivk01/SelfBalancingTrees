/**
 * @file BinarySearchTree.inl
 * @brief This file contains the implementation of the BinarySearchTree class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "BinarySearchTree.hpp"
#include "TreeNodeObject.hpp"
#include "TreeNode.hpp"

// constructors and destructor
template <bool CMP(const int& key1, const int& key2)>
BinarySearchTree<CMP>::BinarySearchTree() {}

template <bool CMP(const int& key1, const int& key2)>
BinarySearchTree<CMP>::BinarySearchTree(sptr_TreeNode root)
    : root{root} {
    ++numOfNodes;
}

template <bool CMP(const int& key1, const int& key2)>
BinarySearchTree<CMP>::~BinarySearchTree() {} // no need to delete nodes because they are shared_ptr
 
template <bool CMP(const int& key1, const int& key2)>
inline bool BinarySearchTree<CMP>::isEmpty() const {
    return numOfNodes == 0;
}

// getters
template <bool CMP(const int& key1, const int& key2)>
inline uint BinarySearchTree<CMP>::getNumOfNodes() const {
    return numOfNodes;
}

template <bool CMP(const int& key1, const int& key2)>
inline sptr_TreeNode BinarySearchTree<CMP>::getRoot() const {
    return root;
}

// core functionalities
template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::insert(sptr_TreeNode&& node) {
    sptr_TreeNode prev = nullValue;
    sptr_TreeNode curr = root;
    
    while (curr != nullValue) {
        prev = curr;
        curr = CMP(node->getObjKey(), curr->getObjKey()) ? curr->getLeft() : curr->getRight(); // choose left or right child
    }

    node->setParent(prev);
    if (prev == nullValue) {
        root = node;
    } else if (CMP(node->getObjKey(), prev->getObjKey())) {
        prev->setLeft(node);
    } else {
        prev->setRight(node);
    }

    ++numOfNodes;
}

template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::insert(sptr_TreeNodeObject&& object) {
    insert(std::make_shared<TreeNode>(object)); // passing a rvalue, using make_shared (calling TreeNode constructor)
}

template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::insert(TreeNodeObject* obj) {
    insert(std::shared_ptr<TreeNodeObject>(obj)); // passing a rvalue, using shared_ptr constructor
}

template <bool CMP(const int& key1, const int& key2)>
sptr_TreeNode BinarySearchTree<CMP>::remove(sptr_TreeNode node) {
    sptr_TreeNode retValue = nullValue;
    if (node->getLeft() == nullValue && node->getRight() == nullValue) {
        // If the node has no children, we can simply remove it and return the parent
        transplant(node, std::move(nullValue));
        retValue = node->getParent();
    } else if (node->getLeft() == nullValue) {
        // If the node has only one child, we can replace it with its child and return the child
        transplant(node, node->getRight());
        retValue = node->getRight();
    } else if (node->getRight() == nullValue) {
        // If the node has only one child, we can replace it with its child and return the child
        transplant(node, node->getLeft());
        retValue = node->getLeft();
    } else {
        sptr_TreeNode ptr = minimum(node->getRight());
        retValue = ptr->getRight(); // we return the right child of the successor only if the successor itself isn't the right child of the node (see next if statement)
        if (ptr->getParent() == node) {
            retValue = ptr;
        }
        if (retValue == nullValue) { // if the successor has no right child, we return the parent of the successor
            retValue = ptr->getParent();
        }
        if (ptr->getParent() != node) {
            transplant(ptr, ptr->getRight());
            ptr->setRight(node->getRight());
            ptr->getRight()->setParent(ptr);
        }
        transplant(node, std::move(ptr));
        ptr->setLeft(node->getLeft());
        ptr->getLeft()->setParent(ptr);
    }
    
    --numOfNodes;
    return retValue;
}

template <bool CMP(const int& key1, const int& key2)>
sptr_TreeNode BinarySearchTree<CMP>::search(sptr_TreeNode root, int key) const {
    while (root != nullValue && key != root->getObjKey()) {
        root = (CMP(key, root->getObjKey())) ? root->getLeft() : root->getRight();
    }
    return root;
}
template <bool CMP(const int& key1, const int& key2)>
inline sptr_TreeNode BinarySearchTree<CMP>::search(int key) const {
    return search(root, key);
}

template <bool CMP(const int& key1, const int& key2)>
inline sptr_TreeNode BinarySearchTree<CMP>::successor(sptr_TreeNode node) const { 
    if (node->getRight() != nullValue) {
        return minimum(node->getRight());
    }
    sptr_TreeNode ptr = node->getParent();
    while (ptr != nullValue && node == ptr->getRight()) {
        node = ptr;
        ptr = ptr->getParent();
    }
    return ptr;
}

template <bool CMP(const int& key1, const int& key2)>
uint BinarySearchTree<CMP>::findNumLeaves(const sptr_TreeNode& root) const {
    if (root == nullValue) {
        return 0;
    } else if (root->getLeft() == nullValue && root->getRight() == nullValue) {
        return 1;
    } else {
        return findNumLeaves(root->getLeft()) + findNumLeaves(root->getRight());
    }
}

template <bool CMP(const int& key1, const int& key2)>
inline uint BinarySearchTree<CMP>::findNumLeaves() const {
    return findNumLeaves(root);
}

template <bool CMP(const int& key1, const int& key2)>
sptr_TreeNode BinarySearchTree<CMP>::minimum(const sptr_TreeNode& root) const {
    sptr_TreeNode ptr = root;
    while (ptr->getLeft() != nullValue) {
        ptr = ptr->getLeft();
    }
    return ptr;
}
template <bool CMP(const int& key1, const int& key2)>
inline sptr_TreeNode BinarySearchTree<CMP>::minimum() const {
    return minimum(root);
}

template <bool CMP(const int& key1, const int& key2)>
sptr_TreeNode BinarySearchTree<CMP>::maximum(const sptr_TreeNode& root) const {
    sptr_TreeNode ptr = root;
    while (ptr->getRight() != nullValue) {
        ptr = ptr->getRight();
    }

    return ptr;
}

template <bool CMP(const int& key1, const int& key2)>
inline sptr_TreeNode BinarySearchTree<CMP>::maximum() const {
    return maximum(root);
}

template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::transplant(const sptr_TreeNode& curr_node, sptr_TreeNode&& new_node) {
    if (curr_node->getParent() == nullValue) {
        root = new_node;
    } else if (curr_node == curr_node->getParent()->getLeft()) {
        curr_node->getParent()->setLeft(new_node);
    } else {
        curr_node->getParent()->setRight(new_node);
    }
    if (new_node != nullValue) {
        new_node->setParent(curr_node->getParent());
    }
}

// walk methods
template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::preorder_walk(const sptr_TreeNode& node) const {
    if (node != nullValue) {
        std::cout << *node << "\t" << std::endl;
        inorder_walk(node->getLeft());
        inorder_walk(node->getRight());
    }
}
template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::inorder_walk(const sptr_TreeNode& node) const {
    if (node != nullValue) {
        inorder_walk(node->getLeft());
        std::cout << *node << "\t" << std::endl;
        inorder_walk(node->getRight());
    }
}
template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::postorder_walk(const sptr_TreeNode& node) const {
    if (node != nullValue) {
        inorder_walk(node->getLeft());
        inorder_walk(node->getRight());
        std::cout << *node << "\t" << std::endl;
    }
}

// print tree structure
template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::prettyPrint(const std::string& prefix, sptr_TreeNode node, bool isLeft) const {
    if (node != nullValue) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->getObjKey() << std::endl;
        // enter the next tree level - left and right branch
        prettyPrint( prefix + (isLeft ? "│   " : "    "), node->getRight(), true);
        prettyPrint( prefix + (isLeft ? "│   " : "    "), node->getLeft(), false);
    }
}

template <bool CMP(const int& key1, const int& key2)>
void BinarySearchTree<CMP>::prettyPrint() const {
    prettyPrint("", root, false);
}