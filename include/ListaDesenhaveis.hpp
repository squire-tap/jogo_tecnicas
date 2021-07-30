#ifndef _LISTADESENHAVEIS_HPP_
#define _LISTADESENHAVEIS_HPP_
#include "Desenhavel.hpp"



class ListaDesenhaveis
{
private:
    lista<Desenhavel*> lista_desenhavel;
   
public:
    ListaDesenhaveis();
    ~ListaDesenhaveis();

    void inserir(Desenhavel* info);
    void inicializarDesenhavel(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    void atualizaDesenhavel(float t);
    void desenharDesenhavel(GerenciadorGrafico &gg);
    void destruirDesenhavel();
};

#endif