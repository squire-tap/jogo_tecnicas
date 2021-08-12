#pragma once

#include "Inimigo.hpp"

class Chefe: public Inimigo
{
public:
	Chefe(vector2D<float> pos, Heroi* pH);
	~Chefe();

	void atualizar(float t);
};

