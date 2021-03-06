#include "Colidivel.hpp"

Colidivel::Colidivel(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id) : Desenhavel(pos, vel, dim, caminhoText), id(id), correcaoColisao(0.0f, 0.0f), existe(true), vida(0)
{
}

Colidivel::~Colidivel()
{
}

int Colidivel::getId()
{
	return id;
}

bool Colidivel::getExiste()
{
	return existe;
}

void Colidivel::setVida(int v)
{
	vida = v;
}

int Colidivel::getVida()
{
	return vida;
}
