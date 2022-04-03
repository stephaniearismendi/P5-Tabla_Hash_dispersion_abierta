/**
 * @file feCuadratica.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief Función de exploración cuadrática
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CUADRATICA_H
#define CUADRATICA_H

#include "funcionExploracion.hpp"

template <class Key>
class feCuadratica : public FuncionExploracion<Key>
{
public:
    unsigned operator()(const Key &k, unsigned i) const
    {
        return (i * i);
    }
};

#endif