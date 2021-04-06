#ifndef DISPERSION_H
#define DISPERSION_H

template <class Clave>
class FuncionDispersion
{
public:
    virtual unsigned operator()(const Clave &k) const = 0;
};

#endif
