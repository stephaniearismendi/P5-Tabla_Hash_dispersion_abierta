/**
 * @file funciones.hpp
 * @author Stephanie Andreina Arismendi Escobar (alu0101351728@ull.edu.es)
 * @brief  funciones de dispersión módulo y pseudoaleatoria
 * @version 0.1
 * @date 2021-04-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "funcion_dispersion.hpp"
#include <stdlib.h>

#ifndef FUNCION_H
#define FUNCION_H

template <class Clave>
class fdModulo : public FuncionDispersion<Clave>
{
public:
    fdModulo(const unsigned n) : nDatos(n) {}
    unsigned operator()(const Clave &k) const
    {
        return k % nDatos;
    }

private:
    unsigned nDatos;
};

template <class Clave>
class fdPseudoaleatoria : public FuncionDispersion<Clave>
{
public:
    fdPseudoaleatoria(const unsigned n) : nDatos(n) {}
    unsigned operator()(const Clave &k) const
    {
        int x = k;
        srand(x);               // generamos semilla para poder generar numeros
        return rand() % nDatos; // para generar un número entre 0 y nDatos
    }

private:
    unsigned nDatos;
};

#endif