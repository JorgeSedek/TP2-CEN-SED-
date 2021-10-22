#include <iostream>
#include "menu.h"

void mostrar_materiales_disponibles(Material* vector_materiales, int tipos_de_materiales) {

    cout << "Se encuentran los siguientes materiales disponibles: " << endl;
    cout << endl;

    for (int i = 0; i != tipos_de_materiales; i++) {
        vector_materiales[i].mostrar_material();
    }
    cout << endl;
}

