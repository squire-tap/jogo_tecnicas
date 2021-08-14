#pragma once

#include "Inimigo.hpp"

class Inimigo1: public Inimigo
{
public:
	Inimigo1(vector2D<float> pos, Heroi* pH);
	Inimigo1(vector2D<float> pos, Heroi* pH1, Heroi* pH2);
	~Inimigo1();

	void atualizar(float t);
};

