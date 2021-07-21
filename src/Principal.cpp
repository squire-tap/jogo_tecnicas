#include "Principal.hpp"

Principal::Principal() : 
janela{new sf::RenderWindow(sf::VideoMode(800, 600), "jogo")}
{
    /* Criando o primeiro personagem */
    cout<<"oi"<<endl;
    Personagem *p1 = new Personagem(sf::Vector2f(400.0f, 400.0f) , sf::Vector2f(1000, 1000), "assets/caveira.png");
    Personagem *p2 = new Personagem(sf::Vector2f(0.0f, 0.0f) , sf::Vector2f(1000, 0), "assets/pngegg.png");
    listaAmigos.inserir(p1);
    listaAmigos.inserir(p2);
}

Principal::~Principal()
{
    delete janela;
    listaAmigos.destruirPersonagens();
}

void Principal::executar()
{
    relogio.restart();

    while (janela->isOpen())
    {
        sf::Event e;
        /* Se o evento (e) foi detectado */
        while (janela->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                janela->close();
                /* Parou o loop da janela quando a fechou , sucesso*/
            }
        }

        sf::Time t = relogio.getElapsedTime();

        janela->clear();

        listaAmigos.atualizaPersonagens(t.asSeconds());
        listaAmigos.desenharPersonagens(janela);

        janela->display();

        relogio.restart();
    }
    /* Nao entrou no loop da janela, algo errado */
    

}