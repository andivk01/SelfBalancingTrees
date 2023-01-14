/**
 * @file AVLTreeNode.hpp
 * @brief Implementation of a TreeNode for an AVL Tree
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef __AVLTreeNode_HPP__
#define __AVLTreeNode_HPP__

#include "TreeNodeObject.hpp"
#include "TreeNode.hpp"

/**
 * @brief This class implements a TreeNode for an AVL Tree
*/
class AVLTreeNode : public TreeNode {
    typedef std::shared_ptr<AVLTreeNode> sptr_AVLTreeNode;

public:

    /**
     * @brief Construct a new AVL Tree Node
     * 
     * @param obj object to store in the node
    */
    AVLTreeNode(sptr_TreeNodeObject obj);

    /**
     * @brief Destroy the AVL Tree Node 
     * 
     */
    ~AVLTreeNode();

    /**
     * @brief Get the left child of the node
     * 
     * @return sptr_AVLTreeNode the left child of the node
     */
    sptr_AVLTreeNode getLeft() const;

    /**
     * @brief Get the right child of the node
     * 
     * @return sptr_AVLTreeNode the right child of the node
     */
    sptr_AVLTreeNode getRight() const;

    /**
     * @brief Get the parent of the node
     * 
     * @return sptr_AVLTreeNode the parent of the node
     */
    sptr_AVLTreeNode getParent() const;

    /**
     * @brief Get the height of the node
     * 
     * @return int the height of the node
     */
    int getHeight() const;

    /**
     * @brief Set the height of the node
     * 
     * @param height the new height of the node
    */
    void setHeight(int height);

protected:
    int height{0};
};

typedef std::shared_ptr<AVLTreeNode> sptr_AVLTreeNode;


#endif