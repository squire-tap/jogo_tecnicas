#include "Fase1.hpp"

Fase1::Fase1():
IDjanelaFechada {ge.adicionarOuvinteOutro([this](const sf::Event& e) { janelaFechada(e); })}, 
IDmenuPausa{ ge.adicionarOuvinteTeclado([this](const sf::Event& e) { menuPausa(e); })},
terminar{ false }, pausado{ false }
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
        
        DadosFase* mp = NULL;
        FB1 = new Fase1Builder();

        DM = new DiretorMapa(FB1);
        mp = DM->criarMapa(jogador, 1);
        mp->registrarEntidades(&gc, &listaAmigos);

        /* Atribui as condições iniciais para as entidades , tanto na parte gráfica como nos eventos */
        listaAmigos.inicializarDesenhavel(gg, ge);

        ge.setJanela(gg.getJanela());
}

Fase1::~Fase1()
{
    listaAmigos.destruirDesenhavel();
}

int Fase1::executar()
{
    /* Enquanto terminar for false */
    while (!terminar)
    {
        if (jogador->getDerrotado())
        {
            listaAmigos.destruirDesenhavel();
            gc.removerTodos();
            return 2;
        }
        if (termino())
        {
            listaAmigos.destruirDesenhavel();
            gc.removerTodos();
            return 3;
        }
        if (pausado)
        {
            return 1;
        }
        
        
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

void Fase1::janelaFechada(const sf::Event& e)
{
    if (e.type == sf::Event::Closed)
        terminar = true;
}

void Fase1::menuPausa(const sf::Event& e)
{
    if (e.key.code == sf::Keyboard::Key::Escape)
        pausado = true;
}

bool Fase1::termino()
{
    if (fabs(jogador->getPosicao().y - vector2D<float>(5600.0f, 600.0f).y) < vector2D<float>(100.0f, 100.0f).y &&
        fabs(jogador->getPosicao().x - vector2D<float>(5600.0f, 600.0f).x) < vector2D<float>(100.0f, 100.0f).x)
        return true;
    else
        return false;
}
