#ifndef GERENCIADORCOLISOES_HPP
#define GERENCIADORCOLISOES_HPP
#include "Colidivel.hpp"
#include "ListaDesenhaveis.hpp"
#include "vector2D.hpp"

class Heroi;


class GerenciadorColisoes
{
private:
	set<Colidivel*> colidiveis;
	int estadoColidindo(Colidivel* p1, Colidivel* p2);
	int pontuacao;
	ListaDesenhaveis* lista;

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void adicionarColidivel(Colidivel* pC);
	void removerColidivel(Colidivel* pC);
	void removerTodos();
	void setListaDesenhaveis(ListaDesenhaveis* l);
	int getPontuacao();

	void verificarColisoes();
	void limpaDesenhaveis();

	void salvar();
	void recuperar(Heroi* j1, Heroi* j2);
	void recuperarJogadores(Heroi* j1, Heroi* j2);
	void recuperarInimigos(Heroi* j1, Heroi* j2);
	void recuperarTiles();
	void recuperarMunicao();
	void recuperarPontuacao();
};


#endif