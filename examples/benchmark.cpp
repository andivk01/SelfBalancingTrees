/**
 * @file benchmark.cpp

 * @brief 
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "benchmark.hpp"
#include "BinarySearchTree.hpp"
#include "AVLTree.hpp"
#include "RBTree.hpp"
#include "TreeNodeObject.hpp"

bool comparator(const int& key1, const int& key2) {
    return key1 < key2;
}

class Intero : public TreeNodeObject {
    private:
        int value{0};

    public:
        Intero() {}
        Intero(const int value) : value{value} {}
        ~Intero() = default;

    inline int getKey() const override {
        return value;
    }

};


int main(int argc, char** argv) {
    const uint iterations = 25000;

    std::cout << "Benchmark dei tre diversi alberi (BST, AVL, RB) con " << iterations << " iterazioni" << std::endl;

    BinarySearchTree<comparator> binarySearchTree = BinarySearchTree<comparator>();
    AVLTree<comparator> avlTree = AVLTree<comparator>();
    RBTree<comparator> rbTree = RBTree<comparator>();

    std::cout << "1.\t--| Binary Search Tree |---" << std::endl;
    benchmark<BinarySearchTree<comparator>, sptr_TreeNode, Intero>(binarySearchTree, iterations);
    std::cout << "2.\t--| AVL Tree |---" << std::endl;
    benchmark<AVLTree<comparator>, sptr_AVLTreeNode, Intero>(avlTree, iterations);
    std::cout << "3.\t--| Red Black Tree |---" << std::endl;
    benchmark<RBTree<comparator>, sptr_RBTreeNode, Intero>(rbTree, iterations);

    return 0;
}
