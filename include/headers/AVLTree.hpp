/**
 * @file AVLTree.hpp
 * @brief Implementation and management of an AVL Tree
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "SelfBalancingTree.hpp"
#include "AVLTreeNode.hpp"

/**
 * @brief This template class implements a Self-Balancing Binary Search Tree using the AVL algorithm
 * 
 * @tparam CMP the compare function to use
 */
template <bool CMP(const int& key1, const int& key2)>
class AVLTree : public SelfBalancingTree<CMP> { 
    protected:
        void insert(sptr_AVLTreeNode&& node);
        void insert(sptr_TreeNodeObject&& obj);
        bool balance(sptr_AVLTreeNode& node);
        int balanceFactor(sptr_AVLTreeNode node);
        void rotateLeft(sptr_AVLTreeNode node);
        void rotateRight(sptr_AVLTreeNode node);
        void updateOnRotation(sptr_AVLTreeNode& node);
        void updateHeight(sptr_AVLTreeNode& node);

    public:
        /**
         * @brief Construct a new empty AVL Tree object
         * 
         */
        AVLTree();

        /**
         * @brief Construct a new AVL Tree object with defined root
         * 
         * @param root root of the new AVL Tree
         */
        AVLTree(sptr_AVLTreeNode root);

        /**
         * @brief Destroy the AVL Tree
         * 
         */
        ~AVLTree();

        /**
         * @brief Get the root of the tree
         * 
         * @return sptr_AVLTreeNode the root of the tree
         */
        sptr_AVLTreeNode getRoot() const;

        /**
         * @brief Insert a TreeNodeObject in the tree (pointer version)
         * 
         * @param node the TreeNodeObject to insert
         */
        void insert(TreeNodeObject* node);

        /**
         * @brief Search for a node in the tree
         * 
         * @param key the key to search for
        */
        sptr_AVLTreeNode search(int key);

        /**
         * @brief Remove a node from the tree
         * 
         * @param node the node to remove
        */
        void remove(sptr_AVLTreeNode node);
};


#include "../definitions/AVLTree.inl"

#endif