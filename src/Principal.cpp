#include "Principal.hpp"

/* inicialização da adicionarOuvinteOutro com a função lambda */
Principal::Principal():
gerenciadorEstado(menu_f)
{

}


Principal::~Principal()
{
    listaAmigos.destruirDesenhavel();
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
