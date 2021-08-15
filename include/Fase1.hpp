#pragma once

#include "Heroi.hpp"
#include "Inimigo.hpp"
#include "Municao.hpp"
#include "GerenciadorGrafico.hpp"
#include "GerenciadorColisoes.hpp"
#include "ListaDesenhaveis.hpp"
#include "Heroi.hpp"
#include "Jogador1.hpp"
#include "Jogador2.hpp"
#include "DadosFase.hpp"
#include "DiretorMapa.hpp"
#include "Fase1Builder.hpp"
#include "Fase2Builder.hpp"
#include "PlanoFundo.hpp"
#include "Estado.hpp"
#include "stdafx.hpp"

class Fase1 : public Estado
{
private:

    sf::Clock relogio;
    GerenciadorGrafico* gg;
    GerenciadorEventos* ge;
    GerenciadorColisoes gc;
    ListaDesenhaveis listaAmigos;
    unsigned int IDjanelaFechada;
    unsigned int IDmenuPausa;
    bool terminar;
    bool pausado;

    Jogador1* jogador1;
    Jogador2* jogador2;
    PlanoFundo pf;

public:
    Fase1(GerenciadorGrafico* GG , GerenciadorEventos* GE);
    ~Fase1();
    int executar();
    void janelaFechada(const sf::Event& e);
    void menuPausa(const sf::Event& e);

    void salvar();
    void recuperar();
    int getPontuacao();

    bool termino();
};

