#include "Atirador.hpp"

Atirador::Atirador(/* args */): podeAtirar(false)
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

void Atirador::atirar()
{
    Municao* p = new Municao();
    lista->inserir(p);
}