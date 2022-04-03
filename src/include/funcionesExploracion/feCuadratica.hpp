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