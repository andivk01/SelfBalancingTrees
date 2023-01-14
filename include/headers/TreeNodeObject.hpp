/**
 * @file TreeNodeObject.hpp
 * @brief Implementation of a TreeNodeObject
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
*/

#ifndef __TREENODEOBJECT_HPP__
#define __TREENODEOBJECT_HPP__

#include <iostream>
#include <memory>

/**
 * @brief This class implements a TreeNodeObject
*/
class TreeNodeObject{
    public:
        /**
         * @brief Construct a new empty Tree Node Object
         * 
        */
        TreeNodeObject(){};

        /**
         * @brief Destroy the Tree Node Object 
         * 
        */
        ~TreeNodeObject(){};

        /**
         * @brief Get the key of the object 
         * 
         * @return int the key of the object
        */
        virtual inline int getKey() const = 0;
       
};

typedef std::shared_ptr<TreeNodeObject> sptr_TreeNodeObject;

#endif // __TREENODEOBJECT_HPP__