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