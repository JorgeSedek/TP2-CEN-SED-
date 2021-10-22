#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include <string>

using namespace std;

class Material {

    private:
    // atributos
    string nombre_material;
    int cantidad_material;

    public:
    // metodos
    
    // Constructor sin parametros
    Material();

    //Constructor con parametros
    //pre:
    //post: Construye un objeto del tipo Material.
    Material(string nombre_material, int cantidad_material);

    string obtener_nombre();
    int obtener_cantidad();
    void mostrar_material();

};

#endif // MATERIAL_H_INCLUDED