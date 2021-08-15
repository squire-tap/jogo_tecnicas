#include "Fase1.hpp"

Fase1::Fase1(GerenciadorGrafico* GG , GerenciadorEventos* GE):
relogio(),
gg(GG),
ge(GE),
IDjanelaFechada{ ge->adicionarOuvinteOutro([this](const sf::Event& e) { janelaFechada(e); })}, 
IDmenuPausa{ ge->adicionarOuvinteTeclado([this](const sf::Event& e) { menuPausa(e); })},
terminar{ false }, 
pausado{ false },
pf(vector2D<float>(1920.0f, 1080.0f) , "assets/PlanoFundo.png")
{
        /* Criando os primeiros personagem */

        gc.setListaDesenhaveis(&listaAmigos);
        jogador2 = NULL;
        
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
        Fase1Builder* FB1 = NULL;
        
        DadosFase* mp = NULL;
        FB1 = new Fase1Builder();

        DM = new DiretorMapa(FB1);
        mp = DM->criarMapa(jogador1, jogador2);
        mp->registrarEntidades(&gc, &listaAmigos);

        /* Atribui as condi��es iniciais para as entidades , tanto na parte gr�fica como nos eventos */
        listaAmigos.inicializarDesenhavel(gg, ge);

        ge->setJanela(gg->getJanela());
}

Fase1::~Fase1()
{
    listaAmigos.destruirDesenhavel();
    ge->removerOuvintes();
    gc.removerTodos();
}

int Fase1::executar()
{
    /* Enquanto terminar for false */
    ge->tratarEventos();
    jogador1->setVelocidade(vector2D<float>(0.0f, 0.0f));
    if(jogador2)
        jogador2->setVelocidade(vector2D<float>(0.0f, 0.0f));
    pausado = false;
    while (!terminar)
    {
        
        
        if (jogador1->getDerrotado())
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

        sf::Time t = relogio.restart();

        //pausado = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P);

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

void Fase1::janelaFechada(const sf::Event& e)
{
    if (e.type == sf::Event::Closed)
        terminar = true;
}

void Fase1::menuPausa(const sf::Event& e)
{
    if (e.key.code == sf::Keyboard::Key::P)
    {
        pausado = true;
        int i = pausado;
    }
}

bool Fase1::termino()
{
    if (fabs(jogador1->getPosicao().y - vector2D<float>(5600.0f, 600.0f).y) < vector2D<float>(100.0f, 100.0f).y&&
        fabs(jogador1->getPosicao().x - vector2D<float>(5600.0f, 600.0f).x) < vector2D<float>(100.0f, 100.0f).x)
        return true;
    else if (jogador2)
        if (fabs(jogador2->getPosicao().y - vector2D<float>(5600.0f, 600.0f).y) < vector2D<float>(100.0f, 100.0f).y&&
            fabs(jogador2->getPosicao().x - vector2D<float>(5600.0f, 600.0f).x) < vector2D<float>(100.0f, 100.0f).x)
            return true;
    else
        return false;
}
