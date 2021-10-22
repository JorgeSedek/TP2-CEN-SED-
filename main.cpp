#include <iostream>
#include "archivos.h"
#include "menu.h"
#include "ciudad.h"

int main() {

    int tipos_de_materiales = 0;
    Material* vector_materiales = nullptr;
    
    Ciudad ciudad();
    
    int opcion_elegida;

    if (!cargar_materiales(vector_materiales, tipos_de_materiales)) return 0;
    if (!cargar_edificios(ciudad)) return 0;

    mostrar_materiales_disponibles(vector_materiales, tipos_de_materiales);

    return 0;
}