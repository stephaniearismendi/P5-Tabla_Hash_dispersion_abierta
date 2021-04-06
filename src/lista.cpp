#include "lista.hpp"

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
bool Lista<Clave>::Buscar(Clave &X) const
{
    for (int i = 0; i < vDatos_.size(); i++)
    {
        if (X == vDatos_[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
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
    else
    {
        vDatos_.push_back(X);
        return true;
    }
}