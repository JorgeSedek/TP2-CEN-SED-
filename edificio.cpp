#include "edificio.h"

Edificio::Edificio() {
    this -> nombre_edificio = "";
    vector_costo[PIEDRA] = Material();
    vector_costo[MADERA] = Material();
    vector_costo[METAL] = Material();
    this -> limite_construccion = 0;
}

Edificio::Edificio(string nombre_edificio, Material piedra, Material madera, Material metal, int limite_construccion) {
    this -> nombre_edificio = nombre_edificio;
    vector_costo[PIEDRA] = piedra;
    vector_costo[MADERA] = madera;
    vector_costo[METAL] = metal;
    this -> limite_construccion = limite_construccion;
}

string Edificio::obtener_nombre() {
    return nombre_edificio;
}

string Edificio::obtener_nombre_material(int posicion) {
    return vector_costo[posicion].obtener_nombre();
}

int Edificio::obtener_costo(int posicion) {
    return vector_costo[posicion].obtener_cantidad();
}

int Edificio::obtener_limite_construccion() {
    return limite_construccion;
}