#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "Colidivel.hpp"

class Inimigo : public Colidivel
{
private:
    /* data */
public:
    Inimigo(vector2D<float> pos , vector2D<float> vel);
    ~Inimigo();

    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
    
};


#endif