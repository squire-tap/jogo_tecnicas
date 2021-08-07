#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "Colidivel.hpp"
#include "Atirador.hpp"
#include "Heroi.hpp"

class Inimigo : public Atirador
{
private:
    /* Ponteiro para saber onde esta o heroi */
    Heroi* pHeroi;
    
public:
    Inimigo(vector2D<float> pos = (0.0f , 0.0f) , vector2D<float> vel = (0.0f , 0.0f) , vector2D<float> dim = (0.0f , 0.0f) , const string caminhoText = " " , int id = 0 , Heroi* p = NULL);
    ~Inimigo();

    void inicializar(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
    void tratarEvento(const sf::Event &e);
    void atirar();
    void desenhar(GerenciadorGrafico& gg);
};


#endif