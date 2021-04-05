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
public:
    Lista();
    bool Buscar(Clave &X) const;
    bool Insertar(const Clave &X);
};

#endif
