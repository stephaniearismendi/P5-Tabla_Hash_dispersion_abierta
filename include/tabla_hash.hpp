#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "lista.hpp"
#include "funcion_dispersion.hpp"

template <class Clave>
class TablaHash
{
private:
    unsigned nDatos_;              // Tamaño de la tabla
    vector<Clave> vDatos_;         // vector de datos
    FuncionDispersion<Clave> *fd_; // Puntero a la clase base FuncionDispersion<Clave>

public:
    TablaHash(unsigned nDatos, int fd);
    bool Buscar(Clave &X) const;
    bool Insertar(const Clave &X);
};

#endif
