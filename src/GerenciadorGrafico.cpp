#include "GerenciadorGrafico.hpp"

GerenciadorGrafico::GerenciadorGrafico() : janela{new sf::RenderWindow(sf::VideoMode(800, 600), "jogo")},
                                           camera{sf::Vector2f(1000 , 1000), sf::Vector2f(1000 , 1000)}
{
    /* liga a janela com o view ultilizado (no caso camera) */
    janela->setView(camera);
}
GerenciadorGrafico::~GerenciadorGrafico()

{
    delete janela;

    for (auto i = textures.begin(); i != textures.end(); ++i)
    {
        delete i->second;
    }
}
void GerenciadorGrafico::desenhar(const string caminho, const vector2D<float> posicao , const vector2D<float> dimensao , bool ori)

{
    if (!textures.count(caminho))
    {
        cerr << "Imagem em " << caminho << " nao carregada " << endl;
        carregarTextura(caminho);
        cout << "Carregada" << endl;
    }
    /* Retorna o valor correspondente á chave caminho */
    sf::Texture *text = textures[caminho];

    sf::Sprite sprite;
    
    sprite.setTexture(*text);

    sprite.setScale(dimensao.x / sprite.getLocalBounds().width, dimensao.y / sprite.getLocalBounds().height);

    /* Rotaciona a sprite conforme o booleano */
    if(!ori)
        sprite.scale(sf::Vector2f(-1.0f , 1.0f));

    /*introdução do getSize() para centralizar a origem em relação à sprite redimensionada*/
    sprite.setOrigin(sf::Vector2f(text->getSize().x/2, text->getSize().y/2));
    
    sprite.setPosition(posicao.x, posicao.y);

    janela->draw(sprite);
}
void GerenciadorGrafico::limpar(int r, int g, int b)

{
    /* Deixa a tela preta */
    janela->clear(sf::Color(r, g, b));
}
bool GerenciadorGrafico::carregarTextura(const string caminho)

{
    /* Caso o caminho da textura esteja no mapa, não é necessario carrega-la novamente 
    "evita sobrecarga de processamento" */
    if (textures.count(caminho))
        return true;

    sf::Texture *text = new sf::Texture();
    text->loadFromFile(caminho);

    textures.insert(pair<const string, sf::Texture *>(caminho, text));
    return true;
}
void GerenciadorGrafico::centralizar(const vector2D<float> centro)
{
    camera.setCenter(sf::Vector2f(centro.x, centro.y));
    janela->setView(camera);
}
void GerenciadorGrafico::mostrar()

{
    janela->display();
}

sf::RenderWindow *GerenciadorGrafico::getJanela() const 
{
    return janela;
}
