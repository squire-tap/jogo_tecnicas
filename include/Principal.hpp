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
#include "Fase1.hpp"
#include "Fase2.hpp"

                


class Principal
{
private:
    
    /* sf::Clock relogio; */
    /* GerenciadorGrafico gg; */
    /* GerenciadorColisoes gc; */
    /* ListaDesenhaveis listaAmigos; */
    GerenciadorEventos gerenciadorEventos; 
    GerenciadorEstado gerenciadorEstado;
    unsigned int IDjanelaFechada;
    bool terminar;

    MenuFase menu_fase;
    MenuPause menu_pause;
    MenuTransicao menu_transicao;

    Fase1 fase1;
    Fase2 fase2;

    Heroi jogador1;
    


public:
    Principal();
    ~Principal();               
    void executar();
    void janelaFechada(const sf::Event& e);
    void inicializaFases();
};

#endif