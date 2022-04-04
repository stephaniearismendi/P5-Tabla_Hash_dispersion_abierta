/**
 * @file feDobleDispersion.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief Función de exploración de doble dispersión
 * @version 0.1
 * @date 2022-04-03
 *
 * @copyright Copyright (c) 2022
 *
 */

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
    unsigned operator()(const Key &k, unsigned i) const { return i * fd_(k); }

private:
    FuncionDispersion<Key> *fd_;
};

#endif