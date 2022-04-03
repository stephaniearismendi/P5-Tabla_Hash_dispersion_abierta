/**
 * @file list.hpp
 * @author stephanie arismendi (alu0101351728@ull.edu.es)
 * @brief clase list que controlará la dispersión abierta
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIST_H
#define LIST_H

#include "sequence.hpp"

template <class Key>
class List : public Sequence<Key>
{
public:
    List(){};
    ~List(){};
    /**
     * @brief Método público que retorna el valor booleano true si el valor X
     * del tipo Key está guardado en la lista. En otro caso retorna el valor false.
     *
     * @tparam Key
     * @param k
     * @return true
     * @return false
     */
    bool Search(const Key &k) const
    {
        for (unsigned i = 0; i < vDatos_.size(); i++)
        {
            if (k == vDatos_[i])
            {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Retorna el valor booleano true si puede Insert el valor X del
     * tipo Key en la lista. En otro caso, si el valor ya está guardado en la tabla, se
     * retorna el valor booleano false
     *
     * @tparam Key
     * @param k
     * @return true
     * @return false
     */
    bool Insert(const Key &k)
    {
        if (Search(k) == true)
        {
            return false;
        }
        vDatos_.push_back(k);
        return true;
    }
    /**
     * @brief Retorna el valor booleano true si la lista está llena. En otro caso,
     * retorna false.
     *
     * @tparam Key
     * @return true
     * @return false
     */
    bool isFull() const
    {
        return vDatos_.size() == vDatos_.capacity();
    }

private:
    vector<Key> vDatos_;
};

#endif
