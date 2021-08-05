#ifndef PROJETIL_HPP
#define PROJETIL_HPP
#include "Colidivel.hpp"

class Projetil: public Colidivel
{
protected:

public:
    Projetil(vector2D<float> pos = (0.0f , 0.0f), vector2D<float> vel = (0.0f , 0.0f), vector2D<float> dim = (0.0f , 0.0f), const string caminhoText = "assets/png", int id = 0);
    ~Projetil();
    virtual void atualizar(float t);
    virtual void desenhar(GerenciadorGrafico& gg) = 0;
    virtual void inicializar(GerenciadorGrafico& gg , GerenciadorEventos& ge) = 0;
    /* Liga o projetil ao personagem */
    virtual void colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro) = 0;
};





#endif