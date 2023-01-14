/**
 * @file SelfBalancingTree.hpp
 * @brief Implementation and management of a Self-Balancing Binary Search Tree
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
*/

#ifndef __SELFBALANCINGTREE_HPP__
#define __SELFBALANCINGTREE_HPP__

#include <iostream>
#include "BinarySearchTree.hpp"

/**
 * @brief This template class implements a Self-Balancing Binary Search Tree
 * 
 * @tparam CMP the compare function to use
 */
template <bool CMP(const int& key1, const int& key2)>
class SelfBalancingTree : public BinarySearchTree<CMP> {
    public:
        /**
         * @brief Construct a new empty Self Balancing Search Tree
         *
         */
        SelfBalancingTree();

        /**
         * @brief Construct a new Binary Tree object with defined root
         *
         * @param root root of the new Binary Tree
         */
        SelfBalancingTree(sptr_TreeNode root);

        /**
         * @brief Destroy the Self Balancing Search Tree object destroying every node first
         *
         */
        virtual ~SelfBalancingTree();

        /**
         * @brief Rotates the tree to the left
         *
         * @param curr_node node on which to perform the rotation
         *
         **/
        void rotateLeft(sptr_TreeNode curr_node);

        /**
         * @brief Rotates the tree to the right
         *
         * @param curr_node node on which to perform the rotation
         *
         **/
        void rotateRight(sptr_TreeNode curr_node);
};

#include "../definitions/SelfBalancingTree.inl"

#endif
