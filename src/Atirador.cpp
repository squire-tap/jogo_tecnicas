#include "Atirador.hpp"

Atirador::Atirador(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id) : 
Colidivel(pos, vel, dim, caminhoText, id), podeAtirar(false) , orientacao(true)
{

}

Atirador::~Atirador()
{

}

bool Atirador::getPodeAtirar()
{
    return podeAtirar;
}

void Atirador::setPodeAtirar(bool pode)
{
    podeAtirar = pode;
}

void Atirador::setListaDesenhaveis(ListaDesenhaveis* l)
{
    lista = l;
}
void Atirador::setGerenciadorColisao(GerenciadorColisoes *g)
{
    gc = g;
}

void Atirador::atirar()
{
    Municao* p = NULL; 
    vector2D<float> correcaoSaidaBala(85.0f , 12.5f);
    p = new Municao(posicao + correcaoSaidaBala , vector2D<float>(350.0f , 0.0f) , vector2D<float>(100.0f , 100.0f) , "assets/bala.png" , 0);  
    
    lista->inserir(p);
    gc->adicionarColidivel(p);
}