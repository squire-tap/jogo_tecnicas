#include "Inimigo.hpp"

Inimigo::Inimigo(vector2D<float> pos, vector2D<float> vel) : Desenhavel(pos , vel , vector2D<float>(10.0f,10.5f),"assets/caveira.png") 
{

}
Inimigo::~Inimigo()
{

}
