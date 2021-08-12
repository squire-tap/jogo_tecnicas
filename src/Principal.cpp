#include "Principal.hpp"

/* inicialização da adicionarOuvinteOutro com a função lambda */
Principal::Principal():
gerenciadorEventos(),
gerenciadorEstado(&fase1,
                  &fase2,
                  &menu_fase,
                  &menu_pause,
                  &menu_transicao) ,
IDjanelaFechada {gerenciadorEventos.adicionarOuvinteOutro([this](const sf::Event& e) { janelaFechada(e); })},
terminar(false),
menu_fase(),
menu_pause(),
menu_transicao(),
fase1(),
fase2(),
jogador1()

{
    //inicializarFases();
}


Principal::~Principal()
{
    /* listaAmigos.destruirDesenhavel(); */
}

void Principal::executar()
{
    /* Enquanto terminar for false */
    while (!terminar)
    {
        gerenciadorEstado.executar();
    }
}

void Principal::janelaFechada(const sf::Event &e)
{
    if (e.type == sf::Event::Closed)
        terminar = true;
}

/* void Principal::inicializaFases()
{
    Fase1.
} */
