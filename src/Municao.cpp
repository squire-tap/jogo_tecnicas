#include "Municao.hpp"

Municao::Municao(vector2D<float> pos): Projetil(pos) , chaveOuvinte(0) , existe(false)
{
}

Municao::~Municao()
{
}

void Municao::atualizar(float t)
{
    posicao = velocidade * t;
}
void Municao::desenhar(GerenciadorGrafico &gg)
{
    gg.desenhar(caminho , posicao , velocidade);
}
void Municao::inicializar(GerenciadorGrafico &gg, GerenciadorEventos &ge)
{
    gg.carregarTextura(caminho);
}

void Municao::colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro)
{
    if (idOutro == 2)
    {

        if (direcao)
        {
            existe = false;
        }
        velocidade = (0.0f , 0.0f);
    }

}