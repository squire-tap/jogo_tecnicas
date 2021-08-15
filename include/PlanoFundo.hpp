#pragma once

#include "Desenhavel.hpp"

class PlanoFundo : public Desenhavel
{
public:
	PlanoFundo(vector2D<float> dimensao = vector2D<float>(1920.0f, 1080.0f) , const string caminho = "");
	~PlanoFundo();

	void setPosicao(vector2D<float> pos);
};

