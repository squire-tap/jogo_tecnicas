#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include "ListaPersonagens.hpp"


class Principal
{
private:
    sf::RenderWindow *janela;
    sf::Clock relogio;

    ListaPersonagens listaAmigos;

public:
    Principal();
    ~Principal();
    void executar();
};

#endif