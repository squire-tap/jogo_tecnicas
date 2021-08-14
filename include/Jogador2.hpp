#pragma once

#include "Heroi.hpp"

class Jogador2: public Heroi
{
public:
	Jogador2(vector2D<float> pos, int v);
	~Jogador2();
	void tratarEvento(const sf::Event& e);
};

