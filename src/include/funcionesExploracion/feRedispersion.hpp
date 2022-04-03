/**
 * @file feRedispersion.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief función de dispersión de redispersión
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef REDISPERSION_H
#define REDISPERSION_H

#include "funcionExploracion.hpp"
#include "../funcionesDispersion/funcionDispersion.hpp"
#include <stdlib.h>

template <class Key>
class feRedispersion : public FuncionExploracion<Key>
{
public:
    unsigned operator()(const Key &k, unsigned i) const
    {
        unsigned aux;
        srand(k);
        for(unsigned j = 0; j < i; j++)
        {
            aux = rand();
        }
        return aux;
    }
};

#endif