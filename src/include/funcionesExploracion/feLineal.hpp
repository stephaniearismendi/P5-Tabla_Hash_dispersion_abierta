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