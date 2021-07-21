#ifndef _LISTAPERSONAGENS_HPP_
#define _LISTAPERSONAGENS_HPP_
#include "Personagem.hpp"

/* Apenas falando para esse classe que RenderWindow existe, ela de fato não abrira esse atributo */
namespace sf{
    class RenderWindow;
}

class ListaPersonagens
{
private:
    class ElementoLista
    {
    private:
        Personagem* info;
        ElementoLista* prev;
        ElementoLista* prox;
    public:
        ElementoLista(Personagem* info = nullptr , ElementoLista* prev = nullptr , ElementoLista* prox = nullptr);
        ~ElementoLista();

        ElementoLista* get_prev();
        void set_prev(ElementoLista* p);

        ElementoLista* get_prox();
        void set_prox(ElementoLista* p);

        Personagem* get_info();
        void set_info(Personagem* p);

    };

    ElementoLista* inicio;
    ElementoLista* fim; 
    ElementoLista* atual;  

public:
    ListaPersonagens();
    ~ListaPersonagens();

    void inserir(Personagem* info);
    void esvaziar();
    Personagem* voltarInicio();
    Personagem* irProximo();

    void atualizaPersonagens(float t);
    void desenharPersonagens(sf::RenderWindow* janela);
    void destruirPersonagens();
};

#endif