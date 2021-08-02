#ifndef _LISTA_HPP_
#define _LISTA_HPP_
#include "stdafx.hpp"


template<class TL>
class lista
{
private:

    template<class TE>
    class ElementoLista
    {
    private:
        TE info;
        ElementoLista* prev;
        ElementoLista* prox;
    public:
        ElementoLista(TE info = nullptr , ElementoLista* prev = nullptr , ElementoLista* prox = nullptr);
        ~ElementoLista();

        ElementoLista* get_prev();
        void set_prev(ElementoLista* p);

        ElementoLista* get_prox();
        void set_prox(ElementoLista* p);

        TE get_info();
        void set_info(TE p);

    };

    ElementoLista<TL>* inicio;
    ElementoLista<TL>* fim; 
    ElementoLista<TL>* atual;  

public:
    lista();
    ~lista();

    void inserir(TL info);
    void esvaziar();

    TL voltarInicio();
    TL irProximo();

};

template<class TL>
template<class TE>
lista<TL>::ElementoLista<TE>::ElementoLista(TE Info, ElementoLista<TE> *Prev, ElementoLista<TE> *Prox) : info(Info), prev(Prev), prox(Prox)
{
}

template<class TL>
template<class TE>
lista<TL>::ElementoLista<TE>::~ElementoLista()
{
}

template<class TL>
template<class TE>
lista<TL>::ElementoLista<TE> *lista<TL>::ElementoLista<TE>::get_prev()
{
    return prev;
}

template<class TL>
template<class TE>
void lista<TL>::ElementoLista<TE>::set_prev(ElementoLista<TE> *p)
{
    prev = p;
}

template<class TL>
template<class TE>
lista<TL>::ElementoLista<TE> *lista<TL>::ElementoLista<TE>::get_prox()
{
    return prox;
}

template<class TL>
template<class TE>
void lista<TL>::ElementoLista<TE>::set_prox(ElementoLista<TE> *p)
{
    prox = p;
}

template<class TL>
template<class TE>
TE lista<TL>::ElementoLista<TE>::get_info()
{
    return info;
}

template<class TL>
template<class TE>
void lista<TL>::ElementoLista<TE>::set_info(TE p)
{
    info = p;
}

template<class TL>
lista<TL>::lista() : inicio{nullptr}, fim{nullptr}, atual{nullptr}
{

}

template<class TL>
lista<TL>::~lista()
{
    esvaziar();
}

template<class TL>
void lista<TL>::inserir(TL info)
{

    if (info) /* Se info nao for nulo */
    {

        ElementoLista<TL> *p = new ElementoLista<TL>(info);
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

    }
}

template<class TL>
void lista<TL>::esvaziar()
{
    ElementoLista<TL> *paux = new ElementoLista<TL>();

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

template<class TL>
TL lista<TL>::voltarInicio()
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

template<class TL>
TL lista<TL>::irProximo()
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

#endif