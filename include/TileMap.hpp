#pragma once
#include "vector2D.hpp"

#include "stdafx.hpp"

class TileMap
{
public:
	class LinhaTileMap
	{
	private:
		unsigned short* linha;
		unsigned int comprimento;

	public:
		LinhaTileMap(unsigned short* l, unsigned int c);
		~LinhaTileMap();

		unsigned short operator[](unsigned int i) const;
	};

private:
	vector2D<unsigned> dimensoesMapa;
	unsigned short** matriz;
	const char* caminho;

	void carregarMapa();

public:
	TileMap(const char* c);
	~TileMap();

	const vector2D<unsigned> getDimensoesMapa() const;
	void imprimirMapa();

	const LinhaTileMap operator[](unsigned int i) const;



};

