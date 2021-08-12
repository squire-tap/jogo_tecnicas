#include "Tile.hpp"

Tile::Tile(vector2D<float> pos, const char* caminho, int id) : Colidivel(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.0f), caminho, id)
{
}

Tile::~Tile()
{
}

void Tile::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
}
