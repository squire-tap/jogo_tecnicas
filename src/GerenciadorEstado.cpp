#include "GerenciadorEstado.hpp"

GerenciadorEstado::GerenciadorEstado( GerenciadorGrafico *GG, GerenciadorEventos *GE) :
gg(GG), ge(GE)

{
    /* coloca o menu fase na pilha */
    menu_fase = new MenuFase(gg);
    pushEstado(menu_fase);
}

GerenciadorEstado::~GerenciadorEstado()
{
    //esvaziarPilha();
}
bool GerenciadorEstado::executar()
{
    /* Estado* estado = pilhaEstados.top();
    int codigoRetorno = estado->executar(); 
    bool terminar = processarCodigo(codigoRetorno); 
    return terminar; */

    return processarCodigo((pilhaEstados.top())->executar());
}
void GerenciadorEstado::pushEstado(Estado *p)
{
    if (p)
        pilhaEstados.push(p);
}
void GerenciadorEstado::popEstado()
{
    delete pilhaEstados.top();
    pilhaEstados.pop();
}
void GerenciadorEstado::esvaziarPilha()
{
    while(pilhaEstados.size() != 0) 
    {
        popEstado();
    } 
}

bool GerenciadorEstado::processarCodigo(int codigoRetorno)
{
    switch (codigoRetorno)
    {

    /* caso 1 , caso 2 , caso 3 ------------> fases retornam */
    case 1:

        cout << "pausar" << endl;
        menu_pause = new MenuPause(gg);
        pushEstado(menu_pause);
        break;

    case 2:

        cout << "game over" << endl;
        popEstado();
        menu_fase = new MenuFase(gg);
        pushEstado(menu_fase);
        break;

    case 3:
        cout << "fase 1 concluída" << endl;
        popEstado();
        fase2 = new Fase2(gg , ge , 0);
        pushEstado(fase2);
        break;

    /* caso 4 , caso 5  ---------> menu_pause */
    case 4:
        /* menu pause , ou continua o jogo ou volta para o menu_fase */
        cout << "continuar" << endl;
        popEstado();
        break;

    case 5:
        cout << "indo para menu fase" << endl;
        
        popEstado();
        popEstado();
        menu_fase = new MenuFase(gg);
        pushEstado(menu_fase);
        break;

 
    /* caso 6 , caso 7 , caso 11 e caso 13 ----------> menu_fase retorna  */
    case 6:
        cout << "indo fase 1" << endl;
        popEstado();
        fase1 = new Fase1(gg, ge , 0);
        pushEstado(fase1);
        break;

    case 7:
        cout << "indo fase 2" << endl;
        popEstado();
        fase2 = new Fase2(gg, ge , 0);
        pushEstado(fase2);
        break;
    
    /* Terminar */
    case 11:
        cout << "indo para o leaderboard" << endl;
        popEstado();
        /* leaderboard = new MenuLeader(); */
        /* pushEstado(leaderboard); */
        break;
    
    case 13:
        cout << "indo para Carregar fase" << endl;
        popEstado();
        menu_carregar = new MenuCarregar(gg);
        pushEstado(menu_carregar);
        break;
    
    
    
    /* case 8 e 12 menu carregar retorna */
    case 8:
        cout << "recuperando fase 1" << endl;
        popEstado();
        fase1 = new Fase1(gg ,ge , 1);
        pushEstado(fase1);
        break;
    
    case 12:
        cout << "recuperando fase 2" << endl;
        popEstado();
        fase2 = new Fase2(gg , ge , 1);
        pushEstado(fase2);

    /* Terminou a fase 2 e vai para o menu */
    case 9:
        cout << "voltando para menu fase" << endl;
        popEstado();
        menu_fase = new MenuFase(gg);
        pushEstado(menu_fase);
        break;
    
    case 10:
        cout << "saindo do jogo" << endl;
        return true;
    

    default:
        cout<<"estado indefinido" << codigoRetorno << endl;
        exit (1);
        break;
    }
    return false;
}

/* void GerenciadorEstado::inicializar()
{
    pilhaEstados.push( //menu_fase);
} */
