#ifndef _LISTADESENHAVEIS_HPP_
#define _LISTADESENHAVEIS_HPP_
#include "Desenhavel.hpp"
#include "lista.hpp"



class ListaDesenhaveis
{
protected:
    lista<Desenhavel*> lista_desenhavel;
   
public:
    ListaDesenhaveis();
    ~ListaDesenhaveis();

    void inserir(Desenhavel* info);
    void inicializarDesenhavel(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    void atualizaDesenhavel(float t);
    void desenharDesenhavel(GerenciadorGrafico &gg);
    void destruirDesenhavel();
    void removerDesenhavel(Desenhavel* p);
    void removerDestruir(Desenhavel* p);
};

#endif