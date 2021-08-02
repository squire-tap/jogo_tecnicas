#pragma once

#include "stdafx.hpp"
#include "Desenhavel.hpp"
#include "vector2D.hpp"
#include <SFML/Graphics.hpp>
#include <string.h>

class Colidivel : public Desenhavel
{
protected:
	int id;
	vector2D<float> correcaoColisao;

public:
	Colidivel(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id);
	~Colidivel();
	virtual void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro) = 0;
	int getId();
};
