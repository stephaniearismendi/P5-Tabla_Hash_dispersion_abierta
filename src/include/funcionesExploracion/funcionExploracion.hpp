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