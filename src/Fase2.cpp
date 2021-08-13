#include "Fase2.hpp"

Fase2::Fase2(GerenciadorGrafico* GG , GerenciadorEventos* GE):
relogio(),
gg(GG),
ge(GE),
gc(),
listaAmigos(),
IDjanelaFechada{ge->adicionarOuvinteOutro([this](const sf::Event& e) { janelaFechada(e); })},
IDmenuPausa{ge->adicionarOuvinteTeclado([this](const sf::Event& e) { menuPausa(e); })},
terminar{ false }, 
pausado{ false },
//jogador(jog),
pf()

{
        /* Criando os primeiros personagem */

        gc.setListaDesenhaveis(&listaAmigos);

        jogador = new Heroi(vector2D<float>(200.0f, 200.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(195.0f, 195.0f), "assets/heroi.png");
        jogador->setListaDesenhaveis(&listaAmigos);
        jogador->setGerenciadorColisao(&gc);

        listaAmigos.inserir(jogador);
        gc.adicionarColidivel(jogador);

        DiretorMapa* DM = NULL;
        Fase2Builder* FB2 = NULL;

        DadosFase* mp = NULL;
        FB2 = new Fase2Builder();

        DM = new DiretorMapa(FB2);
        mp = DM->criarMapa(jogador, 1);
        mp->registrarEntidades(&gc, &listaAmigos);

        /* Atribui as condi��es iniciais para as entidades , tanto na parte gr�fica como nos eventos */
        listaAmigos.inicializarDesenhavel(gg, ge);

        ge->setJanela(gg->getJanela());
}

Fase2::~Fase2()
{
    listaAmigos.destruirDesenhavel();
}

int Fase2::executar()
{
    /* Enquanto terminar for false */
    while (!terminar)
    {
        if (jogador->getDerrotado())
        {
            listaAmigos.destruirDesenhavel();
            gc.removerTodos();
            //ge->~GerenciadorEventos();
            return 2;
        }
        if (termino())
        {
            listaAmigos.destruirDesenhavel();
            gc.removerTodos();
            //ge->~GerenciadorEventos();
            return 3;
        }
        if (pausado)
        {
            return 1;
        }


        sf::Time t = relogio.getElapsedTime();
        relogio.restart();

        ge->tratarEventos();

        gg->limpar();
        /* limpo os que n�o existem mais */

        listaAmigos.atualizaDesenhavel(t.asSeconds());
        gc.verificarColisoes();

        gg->centralizar(jogador->getPosicao());
        pf.setPosicao(jogador->getPosicao());

        pf.desenhar(gg);
        listaAmigos.desenharDesenhavel(gg);

        gg->mostrar();
    }
}

void Fase2::janelaFechada(const sf::Event& e)
{
    if (e.type == sf::Event::Closed)
        terminar = true;
}

void Fase2::menuPausa(const sf::Event& e)
{
    if (e.key.code == sf::Keyboard::Key::P)
        pausado = true;
}

bool Fase2::termino()
{
    if (fabs(jogador->getPosicao().y - vector2D<float>(5400.0f, 400.0f).y) < vector2D<float>(100.0f, 100.0f).y&&
        fabs(jogador->getPosicao().x - vector2D<float>(5400.0f, 400.0f).x) < vector2D<float>(100.0f, 100.0f).x)
        return true;
    else
        return false;
}
