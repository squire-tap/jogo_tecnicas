#include "Principal.hpp"

/* inicialização da adicionarOuvinteOutro com a função lambda */
Principal::Principal():
gerenciadorGrafico(),
gerenciadorEventos(),
gerenciadorEstado( &gerenciadorGrafico, &gerenciadorEventos) ,
IDjanelaFechada {gerenciadorEventos.adicionarOuvinteOutro([this](const sf::Event& e) { janelaFechada(e); })},
terminar(false)
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