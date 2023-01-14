/**
 * @file benchmark.hpp

 * @brief Implementation of the benchmark functions
 * @version 1.0
 * @date 2023-01-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BENCHMARK_HPP__
#define __BENCHMARK_HPP__

#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

typedef unsigned int uint;

template <typename T, typename T_OBJECT>
void benchmarkInsert(T& tree, const uint iterations, std::vector<T_OBJECT*> objects) {
    std::chrono::duration<double, std::micro> elapsedMicroseconds = std::chrono::duration<double, std::micro>(0.0);

    for(uint i{0}; i<iterations; ++i) {
        auto start = std::chrono::steady_clock::now();
        tree.insert( objects.at(i) );
        auto end = std::chrono::steady_clock::now();

        elapsedMicroseconds += (end-start);
    }
    std::cout << "INSERT: " << elapsedMicroseconds.count()/iterations << std::endl;
}

template <typename T, typename T_NODE, typename T_OBJECT>
void benchmarkSearch(T& tree, const uint iterations, std::vector<T_OBJECT*> objects, std::vector<T_NODE>& nodes) {
    std::chrono::duration<double, std::micro> elapsedMicroseconds = std::chrono::duration<double, std::micro>(0.0);

    for(uint i{0}; i<iterations; ++i) {
        auto start = std::chrono::steady_clock::now();
        nodes[i] = tree.search( objects.at(i)->getKey() );
        auto end = std::chrono::steady_clock::now();

        elapsedMicroseconds += (end-start);
    }
    std::cout << "SEARCH: " << elapsedMicroseconds.count()/iterations << std::endl;
}

template <typename T, typename T_NODE, typename T_OBJECT>
void benchmarkRemove(T& tree, const uint iterations, std::vector<T_NODE>& nodes) {
    std::chrono::duration<double, std::micro> elapsedMicroseconds = std::chrono::duration<double, std::micro>(0.0);

    for(uint i{0}; i<iterations; ++i) {
        auto start = std::chrono::steady_clock::now();
        tree.remove( nodes[i] );
        auto end = std::chrono::steady_clock::now();

        elapsedMicroseconds += (end-start);
    }
    std::cout << "REMOVE: " << elapsedMicroseconds.count()/iterations << std::endl;
}


template <typename T, typename T_NODE, typename T_OBJECT>
void benchmark(T& tree, const uint iterations) {
    std::vector<T_OBJECT*> objects = std::vector<T_OBJECT*>(iterations);
    std::vector<T_NODE> nodes = std::vector<T_NODE>(iterations);

    // MEMORY ALLOCATION
    for(uint i{0}; i<iterations; ++i) {
        objects[i] = new T_OBJECT(i);
    }

    // RANDOM SHUFFLE
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(std::begin(objects), std::end(objects), rng);

    benchmarkInsert<T, T_OBJECT>(tree, iterations, objects);
    benchmarkSearch<T, T_NODE, T_OBJECT>(tree, iterations, objects, nodes);
    benchmarkRemove<T, T_NODE, T_OBJECT>(tree, iterations, nodes);
}

#endif

