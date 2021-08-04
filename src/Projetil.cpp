#include "Projetil.hpp"
                                                          //Velocidade iniciada            //Dimensao iniciada
Projetil::Projetil(vector2D<float> pos) : Colidivel(pos , vector2D<float>(100.0f , 100.0f) , vector2D<float>(20.0f,20.0f), "assets/bala.png", 1) , atirador(NULL)
{
    
}

Projetil::~Projetil()
{
}

void Projetil::atualizar(float t)
{
    posicao = velocidade * t;
}

void Projetil::desenhar(GerenciadorGrafico& gg)
{
    gg.desenhar(caminho,posicao,dimensao);
}

void Projetil::inicializar(GerenciadorGrafico& gg , GerenciadorEventos& ge)
{

}

void Projetil::colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro) 
{
    
}