#pragma once

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
#include "Fase2Builder.hpp"
#include "PlanoFundo.hpp"
#include "Estado.hpp"

class Fase1 : public Estado
{
private:

    sf::Clock relogio;
    GerenciadorGrafico gg;
    GerenciadorEventos ge;
    GerenciadorColisoes gc;
    ListaDesenhaveis listaAmigos;
    unsigned int IDjanelaFechada;
    unsigned int IDmenuPausa;
    bool terminar;
    bool pausado;

    Heroi* jogador;
    PlanoFundo pf;

public:
    Fase1();
    ~Fase1();
    int executar();
    void janelaFechada(const sf::Event& e);
    void menuPausa(const sf::Event& e);

    bool termino();
};

