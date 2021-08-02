#include "Colidivel.hpp"

Colidivel::Colidivel(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id = -1) : Desenhavel(pos, vel, dim, caminhoText), id(id)
{
}

Colidivel::~Colidivel()
{
}

int Colidivel::getId()
{
	return id;
}