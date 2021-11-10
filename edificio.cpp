#include <iostream>
#include "edificio.h"

Edificio::Edificio() {
    this -> nombre_edificio = "";
    vector_costo[PIEDRA] = Material();
    vector_costo[MADERA] = Material();
    vector_costo[METAL] = Material();
    this -> limite_construccion = 0;
    this -> materiales_producidos = Material();
}

Edificio::Edificio(string nombre_edificio, Material piedra, Material madera, Material metal, int limite_construccion) {
    this -> nombre_edificio = nombre_edificio;
    vector_costo[PIEDRA] = piedra;
    vector_costo[MADERA] = madera;
    vector_costo[METAL] = metal;
    this -> limite_construccion = limite_construccion;
    asignar_materiales_producidos(nombre_edificio);
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

Material Edificio::obtener_materiales_producidos() {
    return materiales_producidos;
}

void Edificio::mostrar_informacion() {
	cout << SUCESS_COLOR << "-Soy un/a " << obtener_nombre() << " y me encuentro en el casillero consultado." << END_COLOR << endl;
}

void Edificio::asignar_materiales_producidos(string nombre_edificio) {

    materiales_producidos = Material();

    if (nombre_edificio == M) {
        materiales_producidos = Material(S, PRODUCCION_MINA);
    }

    if (nombre_edificio == A) {
        materiales_producidos = Material(W, PRODUCCION_ASERRADERO);
    }

    if (nombre_edificio == F) {
        materiales_producidos = Material(I, PRODUCCION_FABRICA);
    }
}