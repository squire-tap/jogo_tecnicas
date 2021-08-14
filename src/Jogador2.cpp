#include "Jogador2.hpp"

Jogador2::Jogador2(vector2D<float> pos, int v = 30): 
Heroi(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(195.0f, 195.0f), "assets/heroi2.png")
{
    vida = v;
}

Jogador2::~Jogador2()
{
}

void Jogador2::tratarEvento(const sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed)
    {
        switch (e.key.code)
        {
            case sf::Keyboard::Key::D:
                velocidade.x += 500;
                orientacao = true;
                break;
            case sf::Keyboard::Key::A:
                velocidade.x += -500;
                orientacao = false;
                break;
            case sf::Keyboard::Key::W:
                if (noChao)
                {
                    velocidade.y = -1600;
                    noChao = false;
                }
                break;
            case sf::Keyboard::Space:
                atirar(orientacao);
                break;
            default:
                break;
        }

    }
    else if (e.type == sf::Event::KeyReleased)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Key::D:
                velocidade.x += -500;
                break;
        case sf::Keyboard::Key::A:
                velocidade.x += 500;
                break;
            default:
                break;
        }
    }
        /*
        else if (e.type == sf::Event::MouseButtonPressed)
        {
            switch (e.mouseButton.button)
            {
            case sf::Mouse::Left:
                atirar();
                break;

            default:
                break;
            }
        }
        */
}