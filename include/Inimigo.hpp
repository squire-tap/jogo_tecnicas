#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "Colidivel.hpp"
#include "Atirador.hpp"

class Inimigo : public Colidivel , public Atirador
{
private:
    
public:
    Inimigo(vector2D<float> pos , vector2D<float> vel);
    ~Inimigo();

    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
    
};


#endif