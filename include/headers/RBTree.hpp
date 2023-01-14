/**
 * @file RBTree.hpp
 * @brief Implementation and management of a Red-Black Tree
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 */
#ifndef __RBTree_HPP__
#define __RBTree_HPP__

#include "RBTreeNode.hpp"
#include "BinarySearchTree.hpp"
#include "SelfBalancingTree.hpp"

/**
 * @brief This template class implements a Self-Balancing Binary Search Tree using the Red-Black algorithm
 * 
 * @tparam CMP the compare function to use
 */
template <bool CMP(const int& key1, const int& key2)>
class RBTree : public SelfBalancingTree<CMP> {
    private:
        sptr_RBTreeNode nil;
        void prettyPrint(const std::string& prefix, const sptr_RBTreeNode node, bool isLeft) const;
        bool insFixUpRedUncle(sptr_RBTreeNode& node);
        bool insFixUpBlackUncleLeft(sptr_RBTreeNode& node);
        bool insFixUpBlackUncleRight(sptr_RBTreeNode& node);
        void delFixUpRight(sptr_RBTreeNode& node);
        void delFixUpLeft(sptr_RBTreeNode& node);
        void removeWithTwoChildren(sptr_RBTreeNode& node, sptr_RBTreeNode& tmp, sptr_RBTreeNode& tmp2, RBTreeNode::Color& tmpOriginalColor);
    
    protected:
        void insert(sptr_RBTreeNode&& node); 
        void insert(sptr_TreeNodeObject&& obj);
        sptr_RBTreeNode minimum(sptr_RBTreeNode root) const;
        sptr_RBTreeNode maximum(sptr_RBTreeNode root) const;
        void transplant(sptr_RBTreeNode curr_node, sptr_RBTreeNode new_node);
        void insFixUp(sptr_RBTreeNode node);
        void delFixUp(sptr_RBTreeNode node);
        void rotateLeft(sptr_RBTreeNode node);
        void rotateRight(sptr_RBTreeNode node);

    public:
        /**
         * @brief Construct a new empty RedBlackTree object
         * 
         */
        RBTree();

        /**
         * @brief Construct a new RedBlackTree object from a TreeNodeObject
         * 
         */
        RBTree(sptr_RBTreeNode root);

        /**
         * @brief Destroy the RedBlackTree.
        */
        ~RBTree();

        /**
         * @brief Get the root of the tree
         * 
         * @return sptr_RBTreeNode the root of the tree
         */
        sptr_RBTreeNode getRoot() const;

        /**
         * @brief Get the nil node of the tree
         * 
         * @return sptr_RBTreeNode the nil node of the tree
         */
        sptr_RBTreeNode getNil() const;

        /**
         * @brief Insert a TreeNodeObject in the tree 
         * 
         * @param obj pointer to the TreeNodeObject to insert
         */
        void insert(TreeNodeObject* obj);

        /**
         * @brief Remove a node from the tree
         * 
         * @param node pointer to the node to remove
        */
        void remove(sptr_RBTreeNode node);

        /**
         * @brief Search a node in the tree
         * 
         * @param key key of the node to search
         * @return sptr_RBTreeNode pointer to the node found
         */
        sptr_RBTreeNode search(int key);

        /**
         * @brief Get the minimum node of the tree
         * 
         * @return sptr_RBTreeNode pointer to the minimum node
         */
        inline sptr_RBTreeNode minimum() const;

        /**
         * @brief Get the maximum node of the tree
         * 
         * @return sptr_RBTreeNode pointer to the maximum node
         */
        inline sptr_RBTreeNode maximum() const;

        /**
         * @brief Print the tree
        */
        void prettyPrint() const;   
};

#include "../definitions/RBTree.inl"

#endif // __RBTree_HPP__