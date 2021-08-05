#include "Projetil.hpp"
                                                          //Velocidade iniciada            //Dimensao iniciada
Projetil::Projetil(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim , const string caminhoText , int id ): Colidivel(pos , vel , dim , caminhoText , id)
{
    
}

Projetil::~Projetil()
{
}

void Projetil::atualizar(float t)
{

}

void Projetil::desenhar(GerenciadorGrafico& gg)
{

}

void Projetil::inicializar(GerenciadorGrafico& gg , GerenciadorEventos& ge)
{

}

void Projetil::colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro) 
{
    
}