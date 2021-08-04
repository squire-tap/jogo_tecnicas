#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP
#include "Colidivel.hpp"
#include "ListaDesenhaveis.hpp"
#include "Municao.hpp"

class Atirador
{
protected:
    bool podeAtirar;
    ListaDesenhaveis* lista;

public:
    Atirador();
    ~Atirador();
    bool getPodeAtirar();
    void setPodeAtirar(bool pode);
    void atirar();
};


#endif