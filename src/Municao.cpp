#include "Municao.hpp"

Municao::Municao(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim , const string caminhoText , int id ): Projetil(pos , vel , dim , caminhoText , id)
{
}

Municao::~Municao()
{
}

void Municao::atualizar(float t)
{
    posicao += velocidade * t;
    
}
void Municao::desenhar(GerenciadorGrafico &gg)
{
    gg.desenhar(caminho, posicao, dimensao , true);
}
void Municao::inicializar(GerenciadorGrafico &gg, GerenciadorEventos &ge)
{
    gg.carregarTextura(caminho);
}

void Municao::colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro)
{
    if(idOutro  !=  1 && idOutro != 0)
        existe = false; 
}