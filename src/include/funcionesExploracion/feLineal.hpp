/**
 * @file feLineal.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief función de exploración lineal
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LINEAL_H
#define LINEAL_H

#include "funcionExploracion.hpp"

template <class Key>
class feLineal : public FuncionExploracion<Key>
{
public:
    unsigned operator()(const Key &k, unsigned i) const
    {
        return i;
    }
};

#endif