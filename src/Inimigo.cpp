#include "Inimigo.hpp"

Inimigo::Inimigo(vector2D<float> pos, vector2D<float> vel) : Colidivel(pos , vel , vector2D<float>(200.0f,200.f),"assets/inimigo.png", 2) 
{
}
Inimigo::~Inimigo()
{

}

void Inimigo::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
	//if (idOutro == 1)
		//cout << "ai" << endl;
}



