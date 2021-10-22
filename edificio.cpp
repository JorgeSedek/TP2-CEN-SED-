#include "edificio.h"

Edificio::Edificio() {
    this -> nombre_edificio = "";
    this -> vector_materiales_requeridos = nullptr;
    this -> edificios_maximos = 0;
}

Edificio::Edificio(string nombre_edificio, Material* vector_materiales_requeridos, int edificios_maximos) {
    this -> nombre_edificio = nombre_edificio;
    this -> vector_materiales_requeridos = vector_materiales_requeridos;
    this -> edificios_maximos = edificios_maximos;
}