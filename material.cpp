#include <iostream>
#include "material.h"

Material::Material() {
    this -> nombre_material = "";
    this -> cantidad_material = 0;
}

Material::Material(string nombre_material, int cantidad_material) {
    this -> nombre_material = nombre_material;
    this -> cantidad_material = cantidad_material;
}

string Material::obtener_nombre() {
    return nombre_material;
}

int Material::obtener_cantidad() {
    return cantidad_material;
}

void Material::mostrar_material() {
    cout << '-' << obtener_cantidad() << " unidades de " << obtener_nombre() << '.' << endl;
}