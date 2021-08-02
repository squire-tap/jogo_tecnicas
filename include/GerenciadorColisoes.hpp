#pragma once

#pragma once

#include "Colidivel.hpp"
//#include "Personagem.hpp"
#include "stdafx.hpp"
#include <iterator>

class GerenciadorColisoes
{
private:
	set<Colidivel*> colidiveis;
	int estadoColidindo(Colidivel* p1, Colidivel* p2);

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void adicionarColidivel(Colidivel* pC);
	void removerColidivel(Colidivel* pC);
	void removerTodos();

	void verificarColisoes();

};
