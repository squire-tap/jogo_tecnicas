#ifndef GERENCIADOREVENTOS_HPP
#define GERENCIADOREVENTOS_HPP
#include "stdafx.hpp"

class Colidivel;

class GerenciadorEventos
{
private:
    static unsigned int proximoID;
    sf::RenderWindow *janela;
    map<unsigned int , function<void(const sf::Event &)>> ouvintesMouse;
    map<unsigned int , function<void(const sf::Event &)>> ouvintesTeclado;
    map<unsigned int , function<void(const sf::Event &)>> ouvintesOutros;
    sf::Event evento;
    set<Colidivel*> colidiveis;


public:
    GerenciadorEventos();
    ~GerenciadorEventos();
    void tratarEventos();
    void setJanela(sf::RenderWindow* j);
    void setColidiveis(set<Colidivel*> c);

    void adicionarOuvinteMouse(function<void(const sf::Event&)> chamada , int id);
    void removerOuvinteMouse(int id);

    void adicionarOuvinteTeclado(function<void(const sf::Event&)> chamada , int id);
    void removerOuvinteTeclado(int id);

    unsigned int adicionarOuvinteOutro(function<void(const sf::Event&)> chamada);
    void removerOuvinteOutro(int id);

    void removerOuvintes();


};

#endif