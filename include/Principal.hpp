#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_
#include "Principal.hpp"
#include "Heroi.hpp"
#include "Inimigo.hpp"
#include "Municao.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaDesenhaveis.hpp"
                


class Principal
{
private:
    
    sf::Clock relogio;
    GerenciadorGrafico gg;
    GerenciadorEventos ge;
    GerenciadorColisoes gc;
    ListaDesenhaveis listaAmigos;
    unsigned int IDjanelaFechada;
    bool terminar;

public:
    Principal();
    ~Principal();               
    void executar();
    void janelaFechada(const sf::Event& e);
    void criarProjeteis(ListaDesenhaveis);
};

#endif