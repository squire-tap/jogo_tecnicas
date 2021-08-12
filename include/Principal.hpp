#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_
#include "Heroi.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "GerenciadorEstado.hpp"
#include "ListaDesenhaveis.hpp"
#include "MenuFase.hpp"
#include "MenuTransicao.hpp"
#include "MenuPause.hpp"
                


class Principal
{
private:
    
    sf::Clock relogio;
    GerenciadorGrafico gg;
    GerenciadorEventos ge;
    GerenciadorEstado gerenciadorEstado;
    GerenciadorColisoes gc;
    ListaDesenhaveis listaAmigos;
    unsigned int IDjanelaFechada;
    bool terminar;

    MenuFase menu_fase;
    MenuPause menu_pause;
    MenuTransicao menu_transicao;

    

    Heroi* jogador;


public:
    Principal();
    ~Principal();               
    void executar();
    void janelaFechada(const sf::Event& e);
};

#endif