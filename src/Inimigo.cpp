#include "Inimigo.hpp"

Inimigo::Inimigo(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim , const string caminhoText, int id) : Atirador(pos , vel , dim ,caminhoText, 2) 
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



