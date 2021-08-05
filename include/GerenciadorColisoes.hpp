#ifndef GERENCIADORCOLISOES_HPP
#define GERENCIADORCOLISOES_HPP
#include "Colidivel.hpp"
#include "ListaDesenhaveis.hpp"


class GerenciadorColisoes
{
private:
	set<Colidivel*> colidiveis;
	int estadoColidindo(Colidivel* p1, Colidivel* p2);
	ListaDesenhaveis* lista;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void adicionarColidivel(Colidivel* pC);
	void removerColidivel(Colidivel* pC);
	void removerTodos();
	void setListaDesenhaveis(ListaDesenhaveis* l);

	void verificarColisoes();
	void limpaDesenhaveis();

};

#endif