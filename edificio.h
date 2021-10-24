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
    string nombre_edificio;
    Material vector_costo[MATERIALES_UTILIZADOS_EDIFICIOS];
    int limite_construccion;

    public:
    Edificio();
    Edificio(string nombre_edificio, Material piedra, Material madera, Material metal, int edificios_maximos);
    string obtener_nombre();
    string obtener_nombre_material(int posicion);
    int obtener_costo(int posicion);
    int obtener_limite_construccion();
};

#endif // EDIFICIO_H_INCLUDED