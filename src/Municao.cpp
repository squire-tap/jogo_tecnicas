#include "Municao.hpp"

Municao::Municao(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id) : 
Projetil(pos, vel, dim, caminhoText, id)
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

void Municao::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
    /* Se a municao for do heroi*/
    if (id == -1)
    {
            /* Heroi */     /* Ela mesma */   /* A bala inimiga */
        if (idOutro != 1 && idOutro != -1 && idOutro != -2)
            existe = false;
    }

    /* Se a municao for do inimigo */
    else
            /* Inimigo */   /* Ela mesma */   /* Bala Heroi */
        if (idOutro != 2 && idOutro != -2 && idOutro != -1)
            existe = false;


}