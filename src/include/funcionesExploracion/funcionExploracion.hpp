/**
 * @file funcionExploracion.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief clase abstracta para las funciones de exploración
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EXPLORACION_H
#define EXPLORACION_H

#include "funcionExploracion.hpp"

template <class Key>
class FuncionExploracion
{
public:
    virtual unsigned operator()(const Key &k, unsigned i) const = 0;
};

#endif