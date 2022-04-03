/**
 * @file funcionDispersion.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief Clase abstracta para la función dispersión
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DISPERSION_H
#define DISPERSION_H

template <class Key>
class FuncionDispersion
{
public:
    virtual unsigned operator()(const Key &k) const = 0;
};

#endif
