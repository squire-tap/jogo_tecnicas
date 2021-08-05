#ifndef COLIDIVEL_HPP
#define COLIDIVEL_HPP
#include "Desenhavel.hpp"


class Colidivel : public Desenhavel
{
protected:
	int id;
	vector2D<float> correcaoColisao;
	bool existe;

public:
	Colidivel(vector2D<float> pos = (0.0f , 0.0f), vector2D<float> vel = (0.0f , 0.0f), vector2D<float> dim = (0.0f , 0.0f), const string caminhoText = " ", int id = 0);
	~Colidivel();
	virtual void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro) = 0;
	int getId();
	bool getExiste();
};

#endif
