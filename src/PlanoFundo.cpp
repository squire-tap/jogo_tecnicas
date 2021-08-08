#include "PlanoFundo.hpp"

PlanoFundo::PlanoFundo(vector2D<float> dimensao):
Desenhavel(vector2D<float>(0.0f, 0.0f), vector2D<float>(0.0f, 0.0f), dimensao, "assets/PlanoFundo.png")
{
}

PlanoFundo::~PlanoFundo()
{
}

void PlanoFundo::setPosicao(vector2D<float> pos)
{
	posicao = pos;
}
