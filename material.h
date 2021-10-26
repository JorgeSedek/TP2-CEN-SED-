#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "system_clear.h"
#include "colores.h"
#include <string>

using namespace std;

const string S = "piedra";
const string W = "madera";
const string I = "metal";
const int PRODUCCION_MINA = 15;
const int PRODUCCION_ASERRADERO = 25;
const int PRODUCCION_FABRICA = 40;
const int SIN_MATERIAL = 0;

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
};

#endif // MATERIAL_H_INCLUDED