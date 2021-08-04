#ifndef PROJETIL_HPP
#define PROJETIL_HPP
#include "Colidivel.hpp"

class Projetil: public Colidivel
{
protected:
    Desenhavel* atirador;

public:
    Projetil(vector2D<float> pos = (0.0f , 0.0f));
    ~Projetil();
    virtual void atualizar(float t);
    void desenhar(GerenciadorGrafico& gg);
    virtual void inicializar(GerenciadorGrafico& gg , GerenciadorEventos& ge) = 0;
    /* Liga o projetil ao personagem */
    virtual void colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro) = 0;
};





#endif