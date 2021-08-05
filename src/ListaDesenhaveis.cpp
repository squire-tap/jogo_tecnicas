#include "ListaDesenhaveis.hpp"

ListaDesenhaveis::ListaDesenhaveis()
{

}

ListaDesenhaveis::~ListaDesenhaveis()
{
    destruirDesenhavel();
}

void ListaDesenhaveis::inserir(Desenhavel *info)
{
    lista_desenhavel.inserir(info);
}

void ListaDesenhaveis::inicializarDesenhavel(GerenciadorGrafico &gg , GerenciadorEventos &ge)
{
    Desenhavel *p = lista_desenhavel.voltarInicio();
    
    /* Percorre toda a lista de personagens , e chama a funcao atualiza para cada personagem */
    while (p)
    {
        p->inicializar(gg , ge);
        /* Atribui null para (p) caso o proximo nao exista */
        p = lista_desenhavel.irProximo();
    }
}

void ListaDesenhaveis::atualizaDesenhavel(float t)
{
    Desenhavel *p =  lista_desenhavel.voltarInicio();

    /* Percorre toda a lista de personagens , e chama a funcao atualiza para cada personagem */
    while (p)
    {
        p->atualizar(t);
        /* Atribui null para (p) caso o proximo nao exista */
        p = lista_desenhavel.irProximo();
    }
}
void ListaDesenhaveis::desenharDesenhavel(GerenciadorGrafico &gg)
{
    Desenhavel *p = lista_desenhavel.voltarInicio();

    /* Percorre toda a lista de personagens , e chama a funcao desenhar para cada personagem */
    while (p)
    {
        p->desenhar(gg);
        p = lista_desenhavel.irProximo();
    }
}
void ListaDesenhaveis::destruirDesenhavel()
{
    Desenhavel *p = lista_desenhavel.voltarInicio();

    /* Percorre toda a lista de personagens , e chama a funcao destruir para cada personagem */
    while (p)
    {
        delete p;
        p = lista_desenhavel.irProximo();
    }
    lista_desenhavel.esvaziar();
}

void ListaDesenhaveis::removerDesenhavel(Desenhavel* p)
{
    lista_desenhavel.removerInfo(p);
}

void ListaDesenhaveis::removerDestruir(Desenhavel* p)
{
        lista_desenhavel.removerDestruir(p);
}
