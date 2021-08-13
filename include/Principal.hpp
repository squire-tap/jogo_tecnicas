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
    /* GerenciadorColisoes gc; */
    GerenciadorGrafico gerenciadorGrafico;
    GerenciadorEventos gerenciadorEventos; 
    GerenciadorEstado gerenciadorEstado;
    unsigned int IDjanelaFechada;
    bool terminar;


public:
    Principal();
    ~Principal();               
    void executar();
    void janelaFechada(const sf::Event& e);
    void inicializaFases();
};

#endif