/**
 * @file fdPseudoaleatoria.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief Función dispersión pseudoaleatoria
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PSEUDOALEATORIA_H
#define PSEUDOALEATORIA_H

#include "funcionDispersion.hpp"
#include <stdlib.h>

template <class Key>
class fdPseudoaleatoria : public FuncionDispersion<Key>
{
public:
    fdPseudoaleatoria(const unsigned n) : tableSize(n) {}
    unsigned operator()(const Key &k) const
    {
        int x = k;
        srand(x);                  // generamos semilla para poder generar numeros
        return rand() % tableSize; // para generar un número entre 0 y tableSize
    }

private:
    unsigned tableSize;
};

#endif
