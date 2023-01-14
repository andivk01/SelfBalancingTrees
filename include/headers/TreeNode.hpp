/**
 * @file TreeNode.hpp
 * @brief Implementation of a TreeNode
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
*/

#ifndef __TreeNode_HPP__
#define __TreeNode_HPP__

#include <memory>
#include "TreeNodeObject.hpp"

/**
 * @brief This class implements a TreeNode
 */
class TreeNode {
    typedef std::shared_ptr<TreeNode> sptr_TreeNode;
    protected:
        sptr_TreeNode left{nullptr};
        sptr_TreeNode right{nullptr};
        sptr_TreeNode parent{nullptr};
        sptr_TreeNodeObject obj{nullptr};

    public:
        /**
         * @brief Construct a new Tree Node
         * 
         * @param obj object to store in the node
        */
        TreeNode(sptr_TreeNodeObject obj);
        
        /**
         * @brief Destroy the Tree Node 
         * 
         */
        ~TreeNode();

        /**
         * @brief Get the key of the object stored in the node
         * 
         * @return int the key of the object stored in the node
         */
        int getObjKey() const;

        /**
         * @brief Get the object stored in the node
         * 
         * @return sptr_TreeNodeObject the object stored in the node
         */
        sptr_TreeNodeObject getObj() const;

        /**
         * @brief Get the left child of the node
         * 
         * @return sptr_TreeNode the left child of the node
         */
        sptr_TreeNode getLeft() const;

        /**
         * @brief Get the right child of the node
         * 
         * @return sptr_TreeNode the right child of the node
         */
        sptr_TreeNode getRight() const;

        /**
         * @brief Get the parent of the node
         * 
         * @return sptr_TreeNode the parent of the node
         */
        sptr_TreeNode getParent() const;

        /**
         * @brief Set the Object of the node
         * 
         * @param obj the new object of the node
        */
        void setObj(sptr_TreeNodeObject obj);

        /**
         * @brief Set the left child of the node
         * 
         * @param left the new left child of the node
        */
        void setLeft(sptr_TreeNode left);

        /**
         * @brief Set the right child of the node
         * 
         * @param right the new right child of the node
        */
        void setRight(sptr_TreeNode right);

        /**
         * @brief Set the parent of the node
         * 
         * @param parent the new parent of the node
        */
        void setParent(sptr_TreeNode parent);

        /**
         * @brief Overload of the << operator, provide a print function to the class
         * 
         * @param s the stream
         * @param node the node to print
         * @return std::ostream& the key of the object stored in the node in the output stream
        */

        friend std::ostream& operator<<(std::ostream &s, const TreeNode &node);
        
};

typedef std::shared_ptr<TreeNode> sptr_TreeNode;

#endif // __TreeNode_HPP__