#include "Jogador1.hpp"

Jogador1::Jogador1(vector2D<float> pos, int v = 30):
Heroi(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(195.0f, 195.0f), "assets/heroi.png", 1)
{
    vida = v;
}

Jogador1::~Jogador1()
{
}

void Jogador1::tratarEvento(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Right:
            velocidade.x += 500;
            orientacao = true;
            break;
        case sf::Keyboard::Left:
            velocidade.x += -500;
            orientacao = false;
            break;
        case sf::Keyboard::Up:
            if (noChao)
            {
                velocidade.y = -1600;
                noChao = false;
            }
            break;
        default:
            break;
        }

    }
    else if (e.type == sf::Event::KeyReleased)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Right:
            velocidade.x += -500;
            break;
        case sf::Keyboard::Left:
            velocidade.x += 500;
            break;
        default:
            break;
        }
    }
    else if (e.type == sf::Event::MouseButtonPressed)
    {
        switch (e.mouseButton.button)
        {
        case sf::Mouse::Left:
            atirar(orientacao);
            break;

        default:
            break;
        }
    }
}
