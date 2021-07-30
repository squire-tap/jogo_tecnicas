#include "Inimigo.hpp"

Inimigo::Inimigo(vector2D<float> pos, vector2D<float> vel) : Desenhavel(pos , vel , vector2D<float>(200.0f,200.f),"assets/caveira.png") 
{

}
Inimigo::~Inimigo()
{

}
