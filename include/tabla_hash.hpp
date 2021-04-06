
#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "lista.hpp"
#include "funciones.hpp"

template <class Clave>
class TablaHash
{
private:
    unsigned nDatos_;              // Tamaño de la tabla
    vector<Lista<Clave>> vDatos_;  // vector de datos
    FuncionDispersion<Clave> *fd_; // Puntero a la clase base FuncionDispersion<Clave>

public:
    TablaHash(unsigned nDatos, FuncionDispersion<Clave> *fd);
    bool Buscar(const Clave &X) const;
    bool Insertar(const Clave &X);
};

/**
 * @brief Construct a new Tabla Hash< Clave>:: Tabla Hash object
 * 
 * @tparam Clave 
 * @param nDatos 
 * @param fd 
 */
template <class Clave>
TablaHash<Clave>::TablaHash(unsigned nDatos, FuncionDispersion<Clave> *fd)
{
    nDatos_ = nDatos;
    fd_ = fd;
    vDatos_.resize(nDatos_);
}

/**
 * @brief Método público que retorna el valor booleano true si el valor X 
 * del tipo Clave está guardado en la tabla hash. En otro caso retorna el valor 
 * booleano false
 * 
 * @tparam Clave 
 * @param X 
 * @return true 
 * @return false 
 */
template <class Clave>
bool TablaHash<Clave>::Buscar(const Clave &X) const
{
    return vDatos_.at(fd_->operator()(X)).Buscar(X);
}

/**
 * @brief Método bool Insertar(const Clave& X), retorna el valor booleano true si puede
insertar el valor X del tipo Clave en la tabla hash. En otro caso, si el valor 
ya está guardado en la tabla, se retorna el valor booleano false.
 * 
 * @tparam Clave 
 * @param X 
 * @return true 
 * @return false 
 */
template <class Clave>
bool TablaHash<Clave>::Insertar(const Clave &X)
{
    if (Buscar(X) == false)
    {
        return vDatos_.at(fd_->operator()(X)).Insertar(X);
    }else{
        return false;
    }
}

#endif
