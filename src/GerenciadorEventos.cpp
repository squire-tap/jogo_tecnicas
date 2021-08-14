#include "GerenciadorEventos.hpp"

unsigned int GerenciadorEventos::proximoID{0};

GerenciadorEventos::GerenciadorEventos()
{
}
GerenciadorEventos::~GerenciadorEventos()
{
    janela = NULL;
}
void GerenciadorEventos::tratarEventos()
{
    while (janela->pollEvent(evento))
    {
        /* Eventos do mouse */
        if (evento.type == sf::Event::MouseButtonPressed || evento.type == sf::Event::MouseWheelScrolled || evento.type == sf::Event::MouseButtonReleased || evento.type == sf::Event::MouseMoved)
        {
            for (auto it : ouvintesMouse)
            {
                /* Encaminha o parâmetro 'evento' para o segundo argumento do map , que é uma function da STL
                a qual sera responsável por tratar esse 'evento' de alguma forma */
                it.second(evento);
            }
        }
        /* Eventos de teclado */
        else if (evento.type == sf::Event::KeyPressed || evento.type == sf::Event::KeyReleased)
        {
            for (auto it : ouvintesTeclado)
            {
                it.second(evento);
            }
        }
        else
        {
            for (auto it : ouvintesOutros)
            {
                it.second(evento);
            }
        }
    }
}
void GerenciadorEventos::setJanela(sf::RenderWindow *j)
{
    janela = j;

    /* Faz com que ao soltar os botões o desenhavel não mova */
    janela->setKeyRepeatEnabled(false);
}

unsigned int GerenciadorEventos::adicionarOuvinteMouse(function<void(const sf::Event &)> chamada)
{
    ouvintesMouse.emplace(proximoID, chamada);

    return proximoID++;
}
void GerenciadorEventos::removerOuvinteMouse(int id)
{
    ouvintesMouse.erase(id);
}

unsigned int  GerenciadorEventos::adicionarOuvinteTeclado(function<void(const sf::Event &)> chamada)
{
    ouvintesTeclado.emplace( proximoID , chamada);

    return proximoID++;

}
void GerenciadorEventos::removerOuvinteTeclado(int id)
{
    ouvintesTeclado.erase(id);
}

unsigned int GerenciadorEventos::adicionarOuvinteOutro(function<void(const sf::Event &)> chamada)
{
    ouvintesOutros.emplace(proximoID, chamada);

    return proximoID++;
}
void GerenciadorEventos::removerOuvinteOutro(int id)
{
    ouvintesOutros.erase(id);
}

void GerenciadorEventos::removerOuvintes()
{
    ouvintesMouse.clear();
    ouvintesTeclado.clear();
    ouvintesOutros.clear();
}