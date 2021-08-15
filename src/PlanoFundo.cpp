#include "PlanoFundo.hpp"

PlanoFundo::PlanoFundo(vector2D<float> dimensao , const string Caminho):
Desenhavel(vector2D<float>(0.0f, 0.0f), vector2D<float>(0.0f, 0.0f), dimensao, Caminho)
{
}

PlanoFundo::~PlanoFundo()
{
}

void PlanoFundo::setPosicao(vector2D<float> pos)
{
	posicao = pos;
}
