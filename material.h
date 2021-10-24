#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "system_clear.h"
#include "colores.h"
#include <string>

using namespace std;

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