#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "system_clear.h"
#include "colores.h"
#include <string>

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
    Material();
    Material(string nombre_material, int cantidad_material);
    string obtener_nombre();
    int obtener_cantidad();
    void mostrar_material();
    void restar_costo(int costo);
    int llover_material_aleatorio();
    void mostrar_informacion();
    
    private:
    int generar_cantidad_aleatoria(int tipo_material);
    string obtener_tipo_material(int tipo_material);
};

#endif // MATERIAL_H_INCLUDED