#include "GerenciadorEventos.hpp"
#include "Colidivel.hpp"

unsigned int GerenciadorEventos::proximoID{0};

GerenciadorEventos::GerenciadorEventos()
{
}
GerenciadorEventos::~GerenciadorEventos()
{
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

void GerenciadorEventos::setColidiveis(set<Colidivel*> c)
{
    colidiveis = c;
}

void GerenciadorEventos::adicionarOuvinteMouse(function<void(const sf::Event &)> chamada , int id)
{
    ouvintesMouse.emplace(id, chamada);
}
void GerenciadorEventos::removerOuvinteMouse(int id)
{
    ouvintesMouse.erase(id);
}

void GerenciadorEventos::adicionarOuvinteTeclado(function<void(const sf::Event &)> chamada  , int id)
{
    ouvintesTeclado.emplace(id, chamada);

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

//Percorre o map de ouvintes e retira os setados com false e retira
void GerenciadorEventos::removerOuvintes()
{
    Colidivel* pAux = NULL;

    for(auto iterador = colidiveis.begin(); iterador != colidiveis.end(); iterador++)
    {
        pAux = *iterador;
        /* Caso existe for false */
        if (!pAux->getExiste())
        {
            for(auto iterador1 = ouvintesMouse.begin() ; iterador1 != ouvintesMouse.end() ; iterador1++)
            {                       //id
                if(pAux->getId() == iterador1->first)
                {
                    removerOuvinteMouse(pAux->getId());
                }
            }
            for(auto iterador1 = ouvintesTeclado.begin() ; iterador1 != ouvintesTeclado.end() ; iterador++)
            {
                if(pAux->getId() == iterador1->first)
                    removerOuvinteTeclado(pAux->getId());
            }
        }

    }

}