#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>

using namespace std;

template <class Key>
class Sequence
{
public:
    Sequence(){};
    ~Sequence(){};
    virtual bool Search(const Key &k) const = 0;
    virtual bool Insert(const Key &k) = 0;
    virtual bool isFull() const = 0;
};

#endif
