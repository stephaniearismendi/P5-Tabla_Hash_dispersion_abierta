#ifndef DISPERSION_H
#define DISPERSION_H

template <class Key>
class FuncionDispersion
{
public:
    virtual unsigned operator()(const Key &k) const = 0;
};

#endif
