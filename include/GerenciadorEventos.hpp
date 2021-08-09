#ifndef GERENCIADOREVENTOS_HPP
#define GERENCIADOREVENTOS_HPP
#include "stdafx.hpp"


class GerenciadorEventos
{
private:
    static unsigned int proximoID;
    sf::RenderWindow *janela;
    map<unsigned int , function<void(const sf::Event &)>> ouvintesMouse;
    map<unsigned int , function<void(const sf::Event &)>> ouvintesTeclado;
    map<unsigned int , function<void(const sf::Event &)>> ouvintesOutros;
    sf::Event evento;

public:
    GerenciadorEventos();
    ~GerenciadorEventos();
    void tratarEventos();
    void setJanela(sf::RenderWindow* j);

    unsigned int adicionarOuvinteMouse(function<void(const sf::Event&)> chamada);
    void removerOuvinteMouse(int id);

    unsigned int adicionarOuvinteTeclado(function<void(const sf::Event&)> chamada);
    void removerOuvinteTeclado(int id);

    unsigned int adicionarOuvinteOutro(function<void(const sf::Event&)> chamada);
    void removerOuvinteOutro(int id);

    void removerOuvintes();


};

#endif