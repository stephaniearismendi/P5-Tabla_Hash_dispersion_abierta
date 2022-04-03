/**
 * @file fdSuma.hpp
 * @author stephanie arismendi (alu0101351728)
 * @brief Función dispersión suma
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "funcionDispersion.hpp"

#ifndef FUNCIONSUMA_H
#define FUNCIONSUMA_H

template <class Key>
class fdSuma : public FuncionDispersion<Key>
{
public:
    fdSuma(const unsigned n) : tableSize(n) {}
    unsigned operator()(const Key &k) const
    {
        unsigned d = 0, y = 0;
        unsigned x = k;
        while (x > 0)
        {
            y = x % 10;
            d = d + y;
            x = x / 10;
        }
        return (d % tableSize);
    }

private:
    unsigned tableSize;
};

#endif