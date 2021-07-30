#include "Desenhavel.hpp"

Desenhavel::Desenhavel(vector2D<float> pos, vector2D<float> vel,vector2D<float> dim, const string caminhoText) : 
posicao{pos}, velocidade{vel},dimensao{dim}, caminho{caminhoText}
{
    
}

Desenhavel::~Desenhavel()
{
}

/* Função virtual , na classe base 'Desenhavel' essa apenas carrega a textura
nas classes herdadas a função tratará de forma mais específica */
void Desenhavel::inicializar(GerenciadorGrafico &gg , GerenciadorEventos &ge)
{
    gg.carregarTextura(caminho);
}
void Desenhavel::atualizar(float t)
{
    posicao += velocidade * t;

    //corpo.setPosition(position);
}
void Desenhavel::desenhar(GerenciadorGrafico &gg)
{
    gg.desenhar(caminho, posicao , dimensao);
}
