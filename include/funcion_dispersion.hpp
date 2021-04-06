#ifndef DISPERSION_H
#define DISPERSION_H

template <class Clave>
class FuncionDispersion
{
public:
    unsigned operator()(const Clave &k) const = 0;
};

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

#endif
