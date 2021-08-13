#include "GerenciadorEstado.hpp"

GerenciadorEstado::GerenciadorEstado(Fase1* Fase1,
                                     Fase2* Fase2,
                                     MenuFase* Menu_fase,
                                     MenuPause* Menu_pause,
                                     MenuTransicao* Menu_transicao,
                                     GerenciadorGrafico* GG,
                                     GerenciadorEventos* GE)
                                     
                                     :

                                     fase1(Fase1),
                                     fase2(Fase2),
                                     menu_fase(Menu_fase),
                                     menu_pause(Menu_pause),
                                     menu_transicao(Menu_transicao),
                                     gg(GG),
                                     ge(GE)

{
    /* coloca o menu fase na pilha */
    menu_fase = new MenuFase();
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
    if(p) pilhaEstados.push(p); 
}
void GerenciadorEstado::popEstado()
{
    delete pilhaEstados.top();
    pilhaEstados.pop();
}
void GerenciadorEstado::esvaziarPilha()
{
    /*  while(pilhaEstados.size() != 0) 
    {
        popEstado();
    } */
}

int GerenciadorEstado::processarCodigo(int codigoRetorno)
{
    switch (codigoRetorno)
    {
    
    /* caso 1 , caso 2 , caso 3 ------------> fases retornam */
    case 1:

        cout<<"pausar"<<endl;
        menu_pause = new MenuPause();
        pushEstado( menu_pause );
        break;

    case 2:

        cout<<"game over"<<endl;
        //pilhaEstados.pop();
        popEstado();
        menu_fase = new MenuFase();
        pushEstado( menu_fase );
        break;

    case 3:
        cout<<"fase concluída"<<endl;
        //pilhaEstados.pop();
        popEstado();
        menu_transicao = new MenuTransicao();
        pushEstado( menu_transicao );
        break;

    /* caso 4 e caso 5 ---------> menu_pause */
    case 4:
        /* menu pause , ou continua o jogo ou volta para o menu_fase */
        cout<<"continuar"<<endl;
        //pilhaEstados.pop();
        popEstado();
        break;
    
    case 5:
        cout<<"indo para menu fase"<<endl;
        //pilhaEstados.pop();
        //pilhaEstados.pop();
        popEstado();
        popEstado();
        menu_fase = new MenuFase();
        pushEstado( menu_fase );
        break;
    
    
    /* caso 6 e caso 7 ----------> menu_fase retorna  */

    case 6:
        cout<<"indo fase 1"<<endl;
        //pilhaEstados.pop();
        popEstado();
        fase1 = new Fase1(gg , ge);
        pushEstado( fase1 );
        break;
    
    case 7:
        cout<<"indo fase 2"<<endl;
        //pilhaEstados.pop();
        popEstado();
        fase2 = new Fase2(gg , ge);
        pushEstado( fase2 );
        break;

    
    /* caso 8 e caso 9 ------------> menu_transicao retorna */
    case 8:
        cout<<"transitando fase 2"<<endl;
        //pilhaEstados.pop();
        popEstado();
        fase2 = new Fase2(gg , ge);
        pushEstado( fase2 );
        break;
    
    case 9:
        cout<<"voltando para menu fase"<<endl;
        //pilhaEstados.pop();
        popEstado();
        menu_fase = new MenuFase();
        pushEstado( menu_fase );
        break;

    default:
        break;
    }
}

/* void GerenciadorEstado::inicializar()
{
    pilhaEstados.push( //menu_fase);
} */
