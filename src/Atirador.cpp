#include "Atirador.hpp"


Atirador::Atirador(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id) : 
Colidivel(pos, vel, dim, caminhoText, id), podeAtirar(false) , orientacao(true) , vida(0)
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

void Atirador::atirar(bool dir)
{    
}
