#include "Tile.hpp"

Tile::Tile(vector2D<float> pos, const char* caminho) : Colidivel(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(50.0f, 50.0f), caminho, 3)
{
}

Tile::~Tile()
{
}

void Tile::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
}