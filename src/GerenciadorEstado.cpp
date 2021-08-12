#include "GerenciadorEstado.hpp"

GerenciadorEstado::GerenciadorEstado(Estado* menu_f)
{
    /* coloca o menu fase na pilha */
    pushEstado(menu_f);
}

GerenciadorEstado::~GerenciadorEstado()
{
    esvaziarPilha();
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
     while(pilhaEstados.size() != 0) 
    {
        popEstado();
    }
}

int GerenciadorEstado::processarCodigo(int codigoRetorno)
{
    switch (codigoRetorno)
    {
    
    /* caso 1 , caso 2 , caso 3 ------------> fases retornam */
    case 1:
        cout<<"pausar"<<endl;
        pushEstado(/* menu_pause */);
        break;

    case 2:
        cout<<"game over"<<endl;
        popEstado();
        pushEstado(/* menu_fase */);
    
    case 3:
        cout<<"fase concluída"<<endl;
        popEstado();
        pushEstado(/* menu_transição */);

    /* caso 4 , caso 5 , caso 6 ------------> menus retornam */


    /* caso 4 e caso 5 ---------> menu_pause */
    case 4:
        /* menu pause , ou continua o jogo ou volta para o menu_fase */
        cout<<"continuar"<<endl;
        popEstado();
    
    case 5:
        cout<<"indo para menu fase"<<endl;
        popEstado();
        popEstado();
        pushEstado(/* menu_fase */);
    
    
    /* caso 6 e caso 7 ----------> menu_fase retorna  */

    case 6:
        cout<<"indo fase 1"<<endl;
        popEstado();
        pushEstado(/* fase1 */);
    
    case 7:
        cout<<"indo fase 2"<<endl;
        popEstado();
        pushEstado(/* fase2 */);

    
    /* caso 8 e caso 9 ------------> menu_transicao retorna */
    case 8:
        cout<<"transitando fase 2"<<endl;
        popEstado();
        pushEstado(/* fase2 */);
    
    case 9:
        cout<<"voltando para menu fase"<<endl;
        popEstado();
        pushEstado(/* menu_fase */)

    default:
        break;
    }
}

/* void GerenciadorEstado::inicializar()
{
    pilhaEstados.push( //menu_fase);
} */
