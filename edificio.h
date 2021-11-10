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

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un Edificio "vacío" con todos sus atributos nulos.
    Edificio();

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Edificio según los valores ingresados.
    Edificio(string nombre_edificio, Material piedra, Material madera, Material metal, int edificios_maximos);
    
    //pre: -
    //post: Devuelve el nombre del Edificio.
    string obtener_nombre();

    //pre: -
    //post: Devuelve el nombre del Material en la posición ingresada respecto del 'vector_costo'.
    string obtener_nombre_material(int posicion);

    //pre: -
    //post: Devuelve el costo del Material en la posición ingresada respecto del 'vector_costo'.
    int obtener_costo(int posicion);

    //pre: -
    //post: Devuelve el límite de construcción del Edificio.
    int obtener_limite_construccion();

    //pre: -
    //post: Devuelve el Material que produce el Edificio.
    Material obtener_materiales_producidos();
    
    //pre: -
    //post: Imprime en pantalla información del Edificio.
    void mostrar_informacion();

    private:
    //pre: -
    //post: Asigna un Material a 'materiales_producidos' según el nombre del Edificio.
    void asignar_materiales_producidos(string nombre_edificio);
};

#endif // EDIFICIO_H_INCLUDED