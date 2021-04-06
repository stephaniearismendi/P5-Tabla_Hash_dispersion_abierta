#ifndef LISTA_H
#define LISTA_H

#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

template <class Clave>
class Lista
{
private:
    vector<Clave> vDatos_;

public:
    Lista(){};
    ~Lista(){};
    bool Buscar(const Clave &X) const;
    bool Insertar(const Clave &X);
};

/**
 * @brief Método público que retorna el valor booleano true si el valor X 
 * del tipo Clave está guardado en la lista. En otro caso retorna el valor false.
 * 
 * @tparam Clave 
 * @param X 
 * @return true 
 * @return false 
 */
template <class Clave>
bool Lista<Clave>::Buscar(const Clave &X) const
{
    for (unsigned i = 0; i < vDatos_.size(); i++)
    {
        if (X == vDatos_[i])
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Retorna el valor booleano true si puede insertar el valor X del 
 * tipo Clave en la lista. En otro caso, si el valor ya está guardado en la tabla, se 
 * retorna el valor booleano false
 * 
 * @tparam Clave 
 * @param X 
 * @return true 
 * @return false 
 */
template <class Clave>
bool Lista<Clave>::Insertar(const Clave &X)
{
    if (Buscar(X) == true)
    {
        return false;
    }
    vDatos_.push_back(X);
    return true;
}

#endif
