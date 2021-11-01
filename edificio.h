#ifndef EDIFICIO_H_INCLUDED
#define EDIFICIO_H_INCLUDED

#include "material.h"

using namespace std;

const int MATERIALES_UTILIZADOS_EDIFICIOS = 3;
const int NO_HAY_CONSTRUIDO = 0;

const string M = "mina";
const string A = "aserradero";
const string F = "fabrica";
const string E = "escuela";
const string O = "obelisco";
const string P = "planta electrica";

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
    void mostrar_informacion();
};

#endif // EDIFICIO_H_INCLUDED