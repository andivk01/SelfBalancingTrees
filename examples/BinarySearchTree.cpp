/**
 * @file BinarySearchTree.cpp

 * @brief Example file for the BinarySearchTree class
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <memory>

#include "BinarySearchTree.hpp"
#include "TreeNodeObject.hpp"

bool comparator(const int& key1, const int& key2) {
    return key1 < key2;
}

class Persona : public TreeNodeObject {

    private:
        const std::string nome;
        const int anno;

    public:
        Persona(const std::string nome, const int anno)
        : nome(nome), anno{anno}
        {}

        ~Persona(){}


        inline int getKey() const {
            return anno;
        }

};

int main() {
    std::cout << "Test della classe BinarySearchTree" << std::endl;

    BinarySearchTree<comparator> tree = BinarySearchTree<comparator>();

    tree.insert(new Persona("Gabriele", 10));
    tree.insert(new Persona("Andrea", 11));
    tree.insert(new Persona("Marta", 7));
    tree.insert(new Persona("Giancarlo", 71));
    tree.insert(new Persona("Carla", 37));
    tree.insert(new Persona("Gianfranco", 64));
    tree.insert(new Persona("Gianpaolo", 60));
    tree.insert(new Persona("Maurizia", 1));
    
    std::cout << "Stampa albero" << std::endl;
    tree.prettyPrint();
    std::cout << std::endl << "ORA RIMUOVO" << std::endl;

    tree.remove(tree.search(10));
    std::cout << "Stampa albero - rimosso il 10" << std::endl;
    tree.prettyPrint();
    tree.remove(tree.search(11));
    std::cout << "Stampa albero - rimosso il 11" << std::endl;
    tree.prettyPrint();
    tree.remove(tree.search(7));
    std::cout << "Stampa albero - rimosso il 7" << std::endl;
    tree.prettyPrint();
    return 0;
}
