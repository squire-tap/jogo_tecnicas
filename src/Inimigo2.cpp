#include "Inimigo2.hpp"

Inimigo2::Inimigo2(vector2D<float> pos, Heroi* pH) : Inimigo(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.0f), "assets/Inimigo_atirador.png", 2, pH)
{
}

Inimigo2::~Inimigo2()
{
}

void Inimigo2::atualizar(float t)
{
	posicao += (velocidade + correcaoColisao) * t;
	correcaoColisao = vector2D<float>(0.0f, 0.0f);

	velocidade.y = velocidade.y + 2000 * t;

	if (abs(pHeroi->getPosicao().x - posicao.x) < 600.0f && esperaTiro < 0)
	{
		atirar();
		esperaTiro = 0.5;
	}
	else
	{
		esperaTiro -= 1 * t;
	}
}
