#ifndef _PERSONAGEM_HPP_
#define _PERSONAGEM_HPP_
#include "stdafx.hpp"
#include <SFML/Graphics.hpp>


class Personagem
{
private:
    sf::Texture *text;
    sf::RectangleShape corpo;
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    Personagem(sf::Vector2f pos = sf::Vector2f(0.0f , 0.0f) , sf::Vector2f vel = sf::Vector2f(0.0f , 0.0f) , const char* caminhoTextura = nullptr);
    ~Personagem();
    void atualizar(float t);
    void desenhar(sf::RenderWindow* janela);

};

#endif