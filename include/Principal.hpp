#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_
#include "GerenciadorGrafico.hpp"
#include "ListaDesenhaveis.hpp"
                


class Principal
{
private:
    
    sf::Clock relogio;
    GerenciadorGrafico gg;
    GerenciadorEventos ge;
    ListaDesenhaveis listaAmigos;
    unsigned int IDjanelaFechada;
    bool terminar;

public:
    Principal();
    ~Principal();               
    void executar();
    void janelaFechada(const sf::Event& e);
};

#endif