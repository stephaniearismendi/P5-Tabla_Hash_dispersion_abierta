/**
 * @file block.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief Clase Block que controlará la dispersión cerrada
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "sequence.hpp"

template <class Key>
class Block : public Sequence<Key>
{
public:
    Block(unsigned max_size)
    {
        maxsize_ = max_size;
        vDatos_.reserve(maxsize_);
    };
    ~Block(){};
    bool Search(const Key &k) const
    {
        for (unsigned i = 0; i < vDatos_.size(); i++)
        {
            if (k == vDatos_[i])
            {
                return true;
            }
        }
        return false;
    }
    bool Insert(const Key &k)
    {
        if (Search(k) || isFull())
        {
            return false;
        }
        vDatos_.push_back(k);
        return true;
    }
    bool isFull() const
    {
        return vDatos_.size() == maxsize_;
    }

private:
    vector<Key> vDatos_;
    unsigned maxsize_;
};

#endif
