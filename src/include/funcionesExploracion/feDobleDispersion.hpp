#ifndef DOBLEDISPERSION_H
#define DOBLEDISPERSION_H

#include "../funcionesDispersion/funcionDispersion.hpp"
#include "funcionExploracion.hpp"

template <class Key>
class feDobleDispersion : public FuncionExploracion<Key>
{
public:
    feDobleDispersion(FuncionDispersion<Key> *fd)
    {
        fd_ = fd;
    }
    unsigned operator()(const Key &k, unsigned i) const
    {
        return (fd_->operator()(k) + i);
    }

private:
    FuncionDispersion<Key> *fd_;
};

#endif