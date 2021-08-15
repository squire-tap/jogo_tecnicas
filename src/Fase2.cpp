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

        jogador1 = new Jogador1(vector2D<float>(200.0f, 200.0f), 30);
        jogador1->setListaDesenhaveis(&listaAmigos);
        jogador1->setGerenciadorColisao(&gc);

        listaAmigos.inserir(jogador1);
        gc.adicionarColidivel(jogador1);

        jogador2 = new Jogador2(vector2D<float>(210.0f, 210.0f), 30);
        jogador2->setListaDesenhaveis(&listaAmigos);
        jogador2->setGerenciadorColisao(&gc);

        listaAmigos.inserir(jogador2);
        gc.adicionarColidivel(jogador2);

        DiretorMapa* DM = NULL;
        Fase2Builder* FB2 = NULL;

        DadosFase* mp = NULL;
        FB2 = new Fase2Builder();

        DM = new DiretorMapa(FB2);
        mp = DM->criarMapa(jogador1, jogador2);
        mp->registrarEntidades(&gc, &listaAmigos);

        /* Atribui as condi��es iniciais para as entidades , tanto na parte gr�fica como nos eventos */
        listaAmigos.inicializarDesenhavel(gg, ge);

        ge->setJanela(gg->getJanela());
}

Fase2::~Fase2()
{
    listaAmigos.destruirDesenhavel();
    ge->removerOuvintes();
    gc.removerTodos();
}

int Fase2::executar()
{
    /* Enquanto terminar for false */
    ge->tratarEventos();
    jogador1->setVelocidade(vector2D<float>(0.0f , 0.0f));
    if(jogador2)
        jogador2->setVelocidade(vector2D<float>(0.0f, 0.0f));
    pausado = false;
    while (!terminar)
    {
        if(jogador1->getDerrotado())
        {
            listaAmigos.destruirDesenhavel();
            gc.removerTodos();
            return 2;
        }
        if (jogador2)
            if (jogador2->getDerrotado())
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


        sf::Time t = relogio.getElapsedTime();
        relogio.restart();

        if (pausado)
        {
            pausado = false;
            return 1;
        }

        ge->tratarEventos();

        gg->limpar();
        /* limpo os que n�o existem mais */

        listaAmigos.atualizaDesenhavel(t.asSeconds());
        gc.verificarColisoes();

        if (jogador2)
        {
            gg->centralizar((jogador1->getPosicao() + jogador2->getPosicao()) / 2.0);
            pf.setPosicao((jogador1->getPosicao() + jogador2->getPosicao()) / 2.0);
        }
        else
        {
            gg->centralizar(jogador1->getPosicao());
            pf.setPosicao(jogador1->getPosicao());
        }

        pf.desenhar(gg);
        listaAmigos.desenharDesenhavel(gg);

        gg->mostrar();
    }
    return -1;
}

void Fase2::salvar()
{
    gc.salvar();
}

void Fase2::recuperar()
{
    listaAmigos.destruirDesenhavel();
    gc.limpaDesenhaveis();

    listaAmigos.inserir(jogador1);
    gc.adicionarColidivel(jogador1);

    listaAmigos.inserir(jogador2);
    gc.adicionarColidivel(jogador2);

    gc.recuperar(jogador1, jogador2);
}

int Fase2::getPontuacao()
{
    return gc.getPontuacao();
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
    if (fabs(jogador1->getPosicao().y - vector2D<float>(5400.0f, 400.0f).y) < vector2D<float>(100.0f, 100.0f).y&&
        fabs(jogador1->getPosicao().x - vector2D<float>(5400.0f, 400.0f).x) < vector2D<float>(100.0f, 100.0f).x)
        return true;
    else if (jogador2)
        if (fabs(jogador2->getPosicao().y - vector2D<float>(5600.0f, 600.0f).y) < vector2D<float>(100.0f, 100.0f).y&&
            fabs(jogador2->getPosicao().x - vector2D<float>(5600.0f, 600.0f).x) < vector2D<float>(100.0f, 100.0f).x)
            return true;
    return false;
}
