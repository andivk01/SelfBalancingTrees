/**
 * @file BinarySearchTree.hpp
 * @brief Implementation and management of a Binary Search Tree
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 */


#ifndef __BINARYSEARCHTREE_HPP__
#define __BINARYSEARCHTREE_HPP__

#include <iostream>
#include <string>
#include "TreeNode.hpp"
#include "TreeNodeObject.hpp"

/**
 * @brief This class implements a Binary Search Tree 
 * 
 * @tparam CMP the compare function to use
 */

template <bool CMP(const int& key1, const int& key2)>
class BinarySearchTree {
    typedef unsigned int uint;

    protected:
        sptr_TreeNode root{nullptr};
        sptr_TreeNode nullValue{nullptr};
        uint numOfNodes{0};

        void insert(sptr_TreeNode&& node);
        void insert(sptr_TreeNodeObject&& obj);
        sptr_TreeNode search(sptr_TreeNode root, int key) const;
        sptr_TreeNode minimum(const sptr_TreeNode& root) const;
        sptr_TreeNode maximum(const sptr_TreeNode& root) const;
        uint findNumLeaves(const sptr_TreeNode& root) const;
        void transplant(const sptr_TreeNode& curr_node, sptr_TreeNode&& new_node);

    public:
        /**
         * @brief Construct a new empty Binary Tree object
         * 
         */
        BinarySearchTree();

        /**
         * @brief Construct a new Binary Tree object with defined root
         * 
         * @param root root of the new Binary Tree
         */

        BinarySearchTree(sptr_TreeNode root);
        /**
         * @brief Destroy the Binary Tree object
         * 
         */
        ~BinarySearchTree();

        /**
         * @brief Check if the tree has no nodes
         * 
         * @return true if there are no nodes
         */
        virtual inline bool isEmpty() const final;

        /**
         * @brief Get the number of nodes
         * 
         * @return uint the number of nodes
         */
        virtual inline uint getNumOfNodes() const final;

        /**
         * @brief Get the root of the tree
         * 
         * @return sptr_TreeNode the root of the tree
         */
        inline sptr_TreeNode getRoot() const;

        /**
         * @brief Insert a TreeNodeObject in the tree (pointer version)
         * 
         * @param obj the object to insert
         */
        void insert(TreeNodeObject* obj);

        /**
         * @brief Remove a node from the tree
         * 
         * @param node the node to remove
         * @return sptr_TreeNode the child of the node that was actually removed, if it exists, the parent otherwise
         */
        sptr_TreeNode remove(sptr_TreeNode node);

        /**
         * @brief Search for a node in the tree
         * 
         * @param key the key to search
        */
        inline sptr_TreeNode search(int key) const;

        /**
         * @brief Find the successor of a node
         * 
         * @param node the node to find the successor
         * @return sptr_TreeNode the successor of the node
        */
        sptr_TreeNode successor(sptr_TreeNode node) const;

        /**
         * @brief Find minumum node in the tree
         * 
         * @return sptr_TreeNode the minimum node
        */
        inline sptr_TreeNode minimum() const;

        /**
         * @brief Find maximum node in the tree
         * 
         * @return sptr_TreeNode the maximum node
        */  
        inline sptr_TreeNode maximum() const;

        /**
         * @brief Calculate the number of leaves in the tree
         * 
         * @return uint return the number of leaves in the tree
         */
        inline uint findNumLeaves() const;

        /**
         * @brief Walk the tree in preorder
         * 
         */
        virtual void preorder_walk(const sptr_TreeNode& node) const final;

        /**
         * @brief Walk the tree in inorder
         * 
         */
        virtual void inorder_walk(const sptr_TreeNode& node) const final;

        /**
         * @brief Walk the tree in postorder
         * 
         */
        virtual void postorder_walk(const sptr_TreeNode& node) const final;

        /**
         * @brief Print the tree
         * 
         */
        void prettyPrint() const;        


    private:
        void prettyPrint(const std::string& prefix, const sptr_TreeNode node, bool isLeft) const;
        
};


#include "../definitions/BinarySearchTree.inl"

#endif // __BINARYSEARCHTREE_HPP__