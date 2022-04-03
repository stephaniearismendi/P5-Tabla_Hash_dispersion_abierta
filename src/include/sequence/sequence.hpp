/**
 * @file sequence.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief clase abstracta sequence de la que dependerán la clase block y list.
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>

using namespace std;

template <class Key>
class Sequence
{
public:
    Sequence(){};
    ~Sequence(){};
    virtual bool Search(const Key &k) const = 0;
    virtual bool Insert(const Key &k) = 0;
    virtual bool isFull() const = 0;
};

#endif
