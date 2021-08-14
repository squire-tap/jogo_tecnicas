#pragma once

#include "Heroi.hpp"

class Jogador1: public Heroi
{
public:
	Jogador1(vector2D<float> pos, int v);
	~Jogador1();

	void tratarEvento(const sf::Event& e);
};

