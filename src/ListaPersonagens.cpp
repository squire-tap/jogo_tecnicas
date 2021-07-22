#include "ListaPersonagens.hpp"

ListaPersonagens::ElementoLista::ElementoLista(Personagem *Info , ElementoLista *Prev , ElementoLista *Prox ) : 
info(Info), prev(Prev), prox(Prox)
{
}

ListaPersonagens::ElementoLista::~ElementoLista()
{
}

ListaPersonagens::ElementoLista *ListaPersonagens::ElementoLista::get_prev()
{
    return prev;
}

void ListaPersonagens::ElementoLista::set_prev(ElementoLista *p)
{
    prev = p;
}

ListaPersonagens::ElementoLista *ListaPersonagens::ElementoLista::get_prox()
{
    return prox;
}

void ListaPersonagens::ElementoLista::set_prox(ElementoLista *p)
{
    prox = p;
}

Personagem *ListaPersonagens::ElementoLista::get_info()
{
    return info;
}

void ListaPersonagens::ElementoLista::set_info(Personagem *p)
{
    info = p;
}

ListaPersonagens::ListaPersonagens() : inicio{nullptr}, fim{nullptr}, atual{nullptr}
{
}
ListaPersonagens::~ListaPersonagens()
{
    esvaziar();
}

void ListaPersonagens::inserir(Personagem *info)
{

    
    if (info) /* Se info nao for nulo */
    {
        cout << "tem info" << endl;


        ElementoLista *p = new ElementoLista(info);
        p->set_info(info);

        if (!inicio) /* Se inicio for nulo */
        {
            inicio = p; 
        }
        else
        {
            fim->set_prox(p);
            p->set_prev(fim);
        }
        fim = p;
        cout << "Inclui o Personagem!" << endl;
    }
    else
    {
        cout << "Personagem não existe" << endl;
    }
}
void ListaPersonagens::esvaziar()
{
    ElementoLista *paux = new ElementoLista();

    paux = inicio;
    atual = inicio;

    while (atual) /* Enquanto atual for diferente de nulo */
    {
        atual = atual->get_prox();
        delete paux;
        paux = atual;
    }

    inicio = nullptr;
    fim = nullptr;
    atual = nullptr;
}

Personagem *ListaPersonagens::voltarInicio()
{
    if (inicio) /* Se inicio for diferente de nulo */
    {
        /* cout << "Voltei ao inicio da lista de personagens" << endl; */
        atual = inicio;
        return inicio->get_info();
    }
    else
    {
        /* cout << "Nao possui inicio a Lista de Personagens" << endl; */
        return nullptr;
    };
}
Personagem *ListaPersonagens::irProximo()
{
    /* Se o proximo de atual nao for nulo */
    if (atual->get_prox())
    {
        atual = atual->get_prox();
        return atual->get_info();
        /* cout << "Fui para o proximo personagem!" << endl; */
    }
    else
    {
        return nullptr;
        /* cout << "Nao fui para o proximo personagem!" << endl; */
    }
}

void ListaPersonagens::atualizaPersonagens(float t)
{
    Personagem *p = NULL;
    p = voltarInicio();

    /* Percorre toda a lista de personagens , e chama a funcao atualiza para cada personagem */
    while (p)
    {
        p->atualizar(t);
        /* Atribui null para (p) caso o proximo nao exista */
        p = irProximo();
    }
}
void ListaPersonagens::desenharPersonagens(sf::RenderWindow *janela)
{
    Personagem *p = NULL;
    /* Recebe o primeiro elemento da lista */
    p = voltarInicio();

    /* Percorre toda a lista de personagens , e chama a funcao desenhar para cada personagem */
    while (p)
    {
        p->desenhar(janela);
        p = irProximo();
    }
}
void ListaPersonagens::destruirPersonagens()
{
    Personagem *p = NULL;
    p = voltarInicio();

    /* Percorre toda a lista de personagens , e chama a funcao destruir para cada personagem */
    while (p)
    {
        delete p;
        p = irProximo();
    }
}
