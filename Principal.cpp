#include "Principal.hpp"

Principal::Principal() : janela{new sf::RenderWindow(sf::VideoMode(800, 600), "jogo")}, terminar{false}
{
    /* Criando o primeiro personagem */
    Personagem *p1 = new Personagem(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(5, 5), "assets/caveira.png");
    listaAmigos.inserir(p1);
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
        janela->display();

        listaAmigos.atualizaPersonagens(t.asSeconds());
        listaAmigos.desenharPersonagens(janela);

        relogio.restart();
    }
    /* Nao entrou no loop da janela, algo errado */
    

}