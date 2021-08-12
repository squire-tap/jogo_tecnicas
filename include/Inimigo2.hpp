#pragma once

#include "Inimigo.hpp"

class Inimigo2: public Inimigo
{
public:
	Inimigo2(vector2D<float> pos, Heroi* pH);
	~Inimigo2();

	void atualizar(float t);
};

