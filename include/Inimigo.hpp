#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "Desenhavel.hpp"

class Inimigo : public Desenhavel
{
private:
    /* data */
public:
    Inimigo(vector2D<float> pos , vector2D<float> vel);
    ~Inimigo();
};


#endif