#ifndef COLIDIVEL_HPP
#define COLIDIVEL_HPP
#include "Desenhavel.hpp"


class Colidivel : public Desenhavel
{
protected:
	int id;
	vector2D<float> correcaoColisao;

public:
	Colidivel(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id);
	~Colidivel();
	virtual void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro) = 0;
	int getId();
};

#endif
