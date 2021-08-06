#pragma once

#include "Colidivel.hpp"
#include "stdafx.hpp"
#include "vector2D.hpp"

class Tile : public Colidivel
{
public:
	Tile(vector2D<float> pos, const char* caminho);
	~Tile();

	void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
};

