#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "Colidivel.hpp"
#include "Atirador.hpp"
#include "Heroi.hpp"

class Inimigo : public Atirador
{
protected:
    /* Ponteiro para saber onde esta o heroi */
    Heroi* pJog1;
    Heroi* pJog2;
    float esperaTiro;
    
public:
    Inimigo(vector2D<float> pos = (0.0f , 0.0f) , vector2D<float> vel = (0.0f , 0.0f) , vector2D<float> dim = (0.0f , 0.0f) , const string caminhoText = " " , int id = 0 , Heroi* p = NULL);
    ~Inimigo();

    virtual void atualizar(float t) ;
    void setJogador2(Heroi* jog2);
    void inicializar(GerenciadorGrafico* gg , GerenciadorEventos* ge) ;
    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
    void atirar(bool dir);
    void desenhar(GerenciadorGrafico* gg);
};


#endif