#include "TileMap.hpp"

#include "json.hpp"
using namespace nlohmann;
#include <fstream>

TileMap::LinhaTileMap::LinhaTileMap(unsigned short* l, unsigned int c) :
linha(l), comprimento(c)
{
}

TileMap::LinhaTileMap::~LinhaTileMap()
{
}

const TileMap::LinhaTileMap TileMap::operator[](unsigned int i) const
{
	return { matriz[i], dimensoesMapa.x };
}


unsigned short TileMap::LinhaTileMap::operator[](unsigned int i) const
{
	if (i >= comprimento)
	{
		cout << "erro LinhaTileMap" << endl;
	}
	return linha[i];
}

void TileMap::carregarMapa()
{
	std::ifstream arquivo(caminho);

	if (!arquivo.is_open())
	{
		cout << "Erro: arquivo no caminho | " << caminho << " | não pode ser aberto!" << endl;
		exit(109);
	}

	json json;
	arquivo >> json;

	json = json.at("layers").at(0);

	dimensoesMapa = vector2D<unsigned>(json["width"], json["height"]);

	json = json["data"];

	matriz = new unsigned short* [dimensoesMapa.y];

	for (unsigned int i = 0; i < dimensoesMapa.y; i++)
		matriz[i] = new unsigned short[dimensoesMapa.x];

	unsigned short i = 0;
	unsigned short j = 0;

	for (unsigned short s : json)
	{
		if (j >= dimensoesMapa.x)
		{
			j = 0;
			i++;
		}
		if (i >= dimensoesMapa.y)
			break;
		matriz[i][j++] = s;
	}
}

TileMap::TileMap(const char* c):
matriz(NULL), caminho(c)
{
	if (caminho)
		carregarMapa();
}

TileMap::~TileMap()
{
	if (matriz)
	{
		for (unsigned i = 0; i < dimensoesMapa.y; i++)
			delete matriz[i];
		delete matriz;
	}
}

const vector2D<unsigned> TileMap::getDimensoesMapa() const
{
	return dimensoesMapa;
}

void TileMap::imprimirMapa()
{
	for (unsigned short i = 0; i < dimensoesMapa.y; i++)
	{
		for (unsigned short j = 0; j < dimensoesMapa.x; j++)
		{
			cout << matriz[i][j] << " ";

		}
		cout << endl;
	}
}
