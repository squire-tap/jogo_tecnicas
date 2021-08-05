#include "Principal.hpp"

/* inicialização da adicionarOuvinteOutro com a função lambda */
Principal::Principal() : IDjanelaFechada{ge.adicionarOuvinteOutro([this](const sf::Event &e)
                                                                  { janelaFechada(e); })},
                         terminar{false}
{
    /* Criando os primeiros personagem */
    gc.setListaDesenhaveis(&listaAmigos);

    Inimigo *ini1 = new Inimigo(vector2D<float>(850.0f, 550.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.f), "assets/inimigo.png");
    Inimigo *ini2 = new Inimigo(vector2D<float>(800.0f, 600.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.f), "assets/inimigo.png");
    Heroi *heroi = new Heroi(vector2D<float>(1000.0f, 1000.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.0f), "assets/heroi.png");
    heroi->setListaDesenhaveis(&listaAmigos);
    heroi->setGerenciadorColisao(&gc);

    listaAmigos.inserir(ini1);
    gc.adicionarColidivel(ini1);

    listaAmigos.inserir(ini2);
    gc.adicionarColidivel(ini2);

    listaAmigos.inserir(heroi);
    gc.adicionarColidivel(heroi);

    /* Atribui as condições iniciais para as entidades , tanto na parte gráfica como nos eventos */
    listaAmigos.inicializarDesenhavel(gg, ge);

    ge.setJanela(gg.getJanela());
}

Principal::~Principal()
{
    listaAmigos.destruirDesenhavel();
}

void Principal::executar()
{
    /* Enquanto terminar for false */
    while (!terminar)
    {
        sf::Time t = relogio.getElapsedTime();
        relogio.restart();

        ge.tratarEventos();

        gc.verificarColisoes();

        gg.limpar();

        listaAmigos.atualizaDesenhavel(t.asSeconds());
        listaAmigos.desenharDesenhavel(gg);

        gg.mostrar();
    }
}

void Principal::janelaFechada(const sf::Event &e)
{
    if (e.type == sf::Event::Closed)
        terminar = true;
}
