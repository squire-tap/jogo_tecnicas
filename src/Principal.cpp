#include "Principal.hpp"

/* inicialização da adicionarOuvinteOutro com a função lambda */
Principal::Principal():
gerenciadorGrafico(),
gerenciadorEventos(),
gerenciadorEstado(&fase1,
                  &fase2,
                  &menu_fase,
                  &menu_pause,
                  &menu_transicao,
                  &gerenciadorGrafico,
                  &gerenciadorEventos) ,
IDjanelaFechada {gerenciadorEventos.adicionarOuvinteOutro([this](const sf::Event& e) { janelaFechada(e); })},
terminar(false),
menu_fase(),
menu_pause(),
menu_transicao(),
jogador1(vector2D<float>(200.0f, 200.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(195.0f, 195.0f), "assets/heroi.png"),
fase1(&gerenciadorGrafico , &gerenciadorEventos),
fase2(&gerenciadorGrafico , &gerenciadorEventos)

{
    
    /* inicializarFases(); */
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
    Fase1()
} 
 */