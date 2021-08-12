#include "Inimigo1.hpp"

Inimigo1::Inimigo1(vector2D<float> pos, Heroi* pH): Inimigo(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.0f), "assets/inimigo_atirador.png", 2, pH)
{
}

Inimigo1::~Inimigo1()
{
}

void Inimigo1::atualizar(float t)
{
	posicao += (velocidade + correcaoColisao) * t;
	correcaoColisao = vector2D<float>(0.0f, 0.0f);

	velocidade.y = velocidade.y + 2000 * t;

	if (abs(pHeroi->getPosicao().x - posicao.x) < 600.0f && esperaTiro < 0)
	{
		atirar();
		esperaTiro = 1.5;
	}
	else
	{
		esperaTiro -= 1 * t;
	}
}
