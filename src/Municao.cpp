#include "Municao.hpp"

Municao::Municao(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim , const string caminhoText , int id ): 
Projetil(pos , vel , dim , caminhoText , id)
{
}

Municao::~Municao()
{
}

void Municao::atualizar(float t)
{
    posicao += velocidade * t;
    
}
void Municao::desenhar(GerenciadorGrafico *gg)
{
    gg->desenhar(caminho, posicao, dimensao , true);
}
void Municao::inicializar(GerenciadorGrafico *gg, GerenciadorEventos *ge)
{
    gg->carregarTextura(caminho);
}

void Municao::colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro)
{
    /* Se a municao for do heroi*/
    if (id == 31)
    {
                       /* Heroi */        /* Ela mesma */   /* A bala inimiga */
        if (idOutro != 1 && idOutro != 2 && idOutro != 31 && idOutro != 32 && idOutro != 24 && idOutro != 25)
            existe = false;
    }

    /* Se a municao for do inimigo */
    else
            /* Inimigo */   /* Ela mesma */   /* Bala Heroi */
        if (idOutro != 11 && idOutro != 12 && idOutro != 13 && idOutro != 32 && idOutro != 31 && idOutro != 24 && idOutro != 25)
        {
            existe = false;
        }
}