#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include <string>
#include "system_clear.h"
#include "colores.h"

using namespace std;

const string S = "piedra";
const string W = "madera";
const string I = "metal";
const string VACIO = "";

const int PRODUCCION_MINA = 15;
const int PRODUCCION_ASERRADERO = 25;
const int PRODUCCION_FABRICA = 40;

const int SIN_MATERIAL = 0;
const int MATERIAL_CONTENIDO_POR_CASILLERO = 1;

const int PIEDRA = 0;
const int MADERA = 1;
const int METAL = 2;

const int CANT_MATERIALES = 3;
const int CANT_MAX_PIEDRA = 2;
const int CANT_MAX_MADERA = 2;
const int CANT_MAX_METAL = 3;
const int CANT_MIN_PIEDRA = 1;
const int CANT_MIN_MADERA = 0;
const int CANT_MIN_METAL = 2;

class Material {

    private:
    
    string nombre_material;
    int cantidad_material;

    public:

    // Constructor sin parámetros.
    //pre: -
    //post: Instancia un Material "vacío" con todos sus atributos nulos.
    Material();

    // Constructor con parámetros.
    //pre: -
    //post: Instancia un Material según los valores ingresados.
    Material(string nombre_material, int cantidad_material);
    
    //pre: -
    //post: Devuelve el nombre del Material.
    string obtener_nombre();

    //pre: -
    //post: Devuelve la cantidad del Material.
    int obtener_cantidad();

    //pre: -
    //post: Imprime en pantalla los atributos del Material.
    void mostrar_material();

    //pre: El costo debe ser mayor ó igual a cero.
    //post: Suma el 'costo' a la 'cantidad_material'.
    void sumar_costo(int costo);

    //pre: El costo debe ser mayor ó igual a cero.
    //post: Resta el 'costo' a la 'cantidad_material'.
    void restar_costo(int costo);

    //pre: El Material debe ser una instancia "vacía", con sus atributos nulos.
    //post: Genera una unidad de un material de forma aleatoria entre los posibles materiales que pueden llover.
    //      Devuelve un número asociado al material llovido.
    int llover_material_aleatorio();

    //pre: -
    //post: Imprime en pantalla información del Material.
    void mostrar_informacion();
    
    private:

    //pre: -
    //post: Devuelve el nombre de un material según el número ingresado asociado.
    string obtener_tipo_material(int tipo_material);
};

#endif // MATERIAL_H_INCLUDED