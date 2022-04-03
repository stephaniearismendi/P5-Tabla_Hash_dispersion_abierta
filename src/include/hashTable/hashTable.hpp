#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../funcionesDispersion/fdModulo.hpp"
#include "../funcionesDispersion/fdPseudoaleatoria.hpp"
#include "../funcionesDispersion/fdSuma.hpp"
#include "../funcionesExploracion/feCuadratica.hpp"
#include "../funcionesExploracion/feLineal.hpp"
#include "../funcionesExploracion/feDobleDispersion.hpp"
#include "../funcionesExploracion/feRedispersion.hpp"
#include "../sequence/list.hpp"
#include "../sequence/block.hpp"

template <class Key>
class HashTable
{
public:
    HashTable(unsigned tableSize, FuncionDispersion<Key> *fd, FuncionExploracion<Key> *fe, unsigned blockSize)
    {
        tableSize_ = tableSize;
        fd_ = fd;
        fe_ = fe;
        if (fe != nullptr)
        {
            blockSize_ = blockSize;
            for (unsigned i = 0; i < tableSize; i++)
            {
                table_.push_back(new Block<Key>(blockSize));
            }
        }
        else
        {
            for (unsigned i = 0; i < tableSize; i++)
            {
                table_.push_back(new List<Key>());
            }
        }
    }
    bool Search(const Key &k) const
    {
        unsigned j = 0;
        int index = fd_->operator()(k);
        bool encontrado = true;
        if (fe_ != nullptr)
        {

            if (table_[index]->Search(k) == false)
            {
                do
                {
                    encontrado = table_[(index + fe_->operator()(k, j)) % tableSize_]->Search(k);
                    j++;
                } while ((encontrado == false) && (tableSize_ >= j));
            }
            return encontrado;
        }
        if (table_[index]->Search(k))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Insert(const Key &k)
    {
        int index = fd_->operator()(k);
        if (fe_ != nullptr)
        {
            for(unsigned i = 0; i < tableSize_; i++)
            {
                unsigned aux = fe_->operator()(k, i);
                if(!table_[(index + aux) % tableSize_]->isFull() || !table_[(index + aux) % tableSize_]->Search(k))
                {
                    table_[(index + aux) % tableSize_]->Insert(k);
                    return true;
                }else{
                    return false;
                }
            }
        }
        if (table_[index]->Search(k))
        {
            return false;
        }
        else
        {
            table_[index]->Insert(k);
            return true;
        }
    }

private:
    unsigned tableSize_;                    // Tamaño de la tabla
    unsigned blockSize_ = 0;                // Tamaño del bloque con valor 0 por defecto
    vector<Sequence<Key> *> table_;         // vector de datos
    FuncionDispersion<Key> *fd_;            // Puntero a la clase base FuncionDispersion<Key>
    FuncionExploracion<Key> *fe_ = nullptr; // Puntero a la clase base FuncionExploracion<Key>
};

#endif
