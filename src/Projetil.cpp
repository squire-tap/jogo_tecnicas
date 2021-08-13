#include "Projetil.hpp"
                                                          //Velocidade iniciada            //Dimensao iniciada
Projetil::Projetil(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim , const string caminhoText , int id ): Colidivel(pos , vel , dim , caminhoText , id)
{
    
}

Projetil::~Projetil()
{
    
}