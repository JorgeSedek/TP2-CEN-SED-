#ifndef EDIFICIO_H_INCLUDED
#define EDIFICIO_H_INCLUDED

#include "material.h"

using namespace std;

const int MATERIALES_UTILIZADOS_EDIFICIOS = 3;
const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;

class Edificio {
    private:
    // atributos
    string nombre_edificio;
    Material* vector_materiales_requeridos;
    int edificios_maximos;

    public:
    // metodos

    // Constructor sin parametros
    //pre:
    //post: Construye un objeto del tipo Edificio. 
    Edificio();

    // Constructor sin parametros
    //pre:
    //post: Construye un objeto del tipo Edificio.
    Edificio(string nombre_edificio, Material* vector_materiales_requeridos, int edificios_maximos);

    private:

};

#endif // EDIFICIO_H_INCLUDED