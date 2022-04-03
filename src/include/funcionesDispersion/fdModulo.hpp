/**
 * @file fdModulo.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief Función dispersión módulo
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include "funcionDispersion.hpp"

#ifndef FDMODULO_H
#define FDMODULO_H

template <class Key>
class fdModulo : public FuncionDispersion<Key>
{
public:
    fdModulo(const unsigned n) : tableSize(n) {}
    unsigned operator()(const Key &k) const
    {
        return k % tableSize;
    }

private:
    unsigned tableSize;
};

#endif