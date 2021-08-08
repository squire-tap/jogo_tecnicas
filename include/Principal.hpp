#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_
#include "Principal.hpp"
#include "Heroi.hpp"
#include "Inimigo.hpp"
#include "Municao.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaDesenhaveis.hpp"
#include "Heroi.hpp"
#include "DadosFase.hpp"
#include "DiretorMapa.hpp"
#include "Fase1Builder.hpp"
#include "PlanoFundo.hpp"
                


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

    Heroi* jogador;
    PlanoFundo pf;

public:
    Principal();
    ~Principal();               
    void executar();
    void janelaFechada(const sf::Event& e);
    void criarProjeteis(ListaDesenhaveis);
};

#endif