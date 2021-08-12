#include "Principal.hpp"

/* inicialização da adicionarOuvinteOutro com a função lambda */
Principal::Principal() : 
IDjanelaFechada{ge.adicionarOuvinteOutro([this](const sf::Event &e){ janelaFechada(e); })},
terminar{false}
{
    /* Criando os primeiros personagem */
    
    gc.setListaDesenhaveis(&listaAmigos);
    
    jogador = new Heroi(vector2D<float>(200.0f, 200.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(195.0f, 195.0f), "assets/heroi.png");
    jogador->setListaDesenhaveis(&listaAmigos);
    jogador->setGerenciadorColisao(&gc);

    listaAmigos.inserir(jogador);
    gc.adicionarColidivel(jogador);
    
    DiretorMapa* DM = NULL;
    Fase1Builder* FB1 = NULL;
    Fase2Builder* FB2 = NULL;
    DadosFase* mp = NULL;
    FB2 = new Fase2Builder();

    DM = new DiretorMapa(FB2);
    mp = DM->criarMapa(jogador, 1);
    mp->registrarEntidades(&gc, &listaAmigos);

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

        gg.limpar();
        /* limpo os que não existem mais */        

        listaAmigos.atualizaDesenhavel(t.asSeconds());
        gc.verificarColisoes();
        
        gg.centralizar(jogador->getPosicao());
        pf.setPosicao(jogador->getPosicao());
        
        pf.desenhar(gg);
        listaAmigos.desenharDesenhavel(gg);

        gg.mostrar();
    }
}

void Principal::janelaFechada(const sf::Event &e)
{
    if (e.type == sf::Event::Closed)
        terminar = true;
}
