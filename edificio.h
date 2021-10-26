#ifndef EDIFICIO_H_INCLUDED
#define EDIFICIO_H_INCLUDED

#include "material.h"

using namespace std;

const int MATERIALES_UTILIZADOS_EDIFICIOS = 3;
const int NO_HAY_CONSTRUIDO = 0;
const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;
const string MINA = "mina";
const string ASERRADERO = "aserradero";
const string FABRICA = "fabrica";

class Edificio {
    private:
    string nombre_edificio;
    Material vector_costo[MATERIALES_UTILIZADOS_EDIFICIOS];
    int limite_construccion;
    Material materiales_producidos;

    public:
    Edificio();
    Edificio(string nombre_edificio, Material piedra, Material madera, Material metal, int edificios_maximos);
    string obtener_nombre();
    string obtener_nombre_material(int posicion);
    int obtener_costo(int posicion);
    int obtener_limite_construccion();
    void asignar_materiales_producidos(string nombre_edificio);
    Material obtener_materiales_producidos();
};

#endif // EDIFICIO_H_INCLUDED