#include <iostream>
#include "archivos.h"
#include "menu.h"

int main() {

    int tipos_de_materiales = 0;
    Material* vector_materiales = nullptr;
    
    int cantidad_edificios = 0;
    Edificio* vector_edificios = nullptr;
    
    int opcion_elegida;

    if (!cargar_materiales(vector_materiales, tipos_de_materiales)) return 0;
    if (!cargar_edificios(vector_edificios, cantidad_edificios)) return 0;

    mostrar_materiales_disponibles(vector_materiales, tipos_de_materiales);

    return 0;
}