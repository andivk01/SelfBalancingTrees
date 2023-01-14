/**
 * @file RBTreeNode.hpp
 * @brief Implementation of a TreeNode for a Red-Black Tree
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
*/

#ifndef __RBTreeNode_HPP__
#define __RBTreeNode_HPP__

#include "TreeNodeObject.hpp"
#include "TreeNode.hpp"

/**
 * @brief This class implements a TreeNode for a Red-Black Tree
*/
class RBTreeNode : public TreeNode {
    typedef std::shared_ptr<RBTreeNode> sptr_RBTreeNode;
    
    public:

        /**
         * @brief This enum represents the color of a node
         * 
         * @note The color of a node is either RED or BLACK
        */
        enum class Color {RED, BLACK};

        /**
         * @brief Construct a new RedBlackTreeNode
         * 
         * @param obj object to store in the node
        */
        RBTreeNode(sptr_TreeNodeObject obj);

        /**
         * @brief Destroy the RedBlackTreeNode 
         * 
         */
        ~RBTreeNode() = default;

        /**
         * @brief Get the key of the node
         * 
         * @return int the key of the node
        */
        inline int getKey() const;

        /**
         * @brief Get the color of the node
         * 
         * @return RBTreeNode::Color the color of the node
        */
        RBTreeNode::Color getColor() const;

        /**
         * @brief Set the color of the node
         * 
         * @param color the new color of the node
        */
        void setColor(RBTreeNode::Color color);

        /**
         * @brief Get the left child of the node
         * 
         * @return sptr_RBTreeNode the left child of the node
         */
        sptr_RBTreeNode getLeft() const;

        /**
         * @brief Get the right child of the node
         * 
         * @return sptr_RBTreeNode the right child of the node
         */
        sptr_RBTreeNode getRight() const;
        
        /**
         * @brief Get the parent of the node
         * 
         * @return sptr_RBTreeNode the parent of the node
         */
        sptr_RBTreeNode getParent() const;
        
    private:
        Color color{Color::RED};
};

typedef std::shared_ptr<RBTreeNode> sptr_RBTreeNode;

#endif // __RBTreeNode_HPP__