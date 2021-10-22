#include <iostream>
#include "ciudad.h"

Ciudad::Ciudad() {
    this -> vector_edificios = nullptr;
    this -> cantidad_edificios = 0;
}

Edificio* Ciudad::obtener_vector_edificios() {
    return vector_edificios;
}

int Ciudad::obtener_cantidad_edificios() {
    return cantidad_edificios;
}

bool Ciudad::cargar_edificios() {

    ifstream archivo(PATH_EDIFICIOS);
    string nombre_edificio;
    int edificios_maximos;

    Material vector_materiales_requeridos[MATERIALES_UTILIZADOS_EDIFICIOS];
    string nombre_material;
    int cantidad_material;

    if (!archivo.is_open()) {
        cout << endl;
        cout << "ERROR: No se encuentra el archivo de edificios." << endl;
        return 0;
    }
    else {
        while (archivo >> nombre_edificio) {
            
            for (int i = 0; i < MATERIALES_UTILIZADOS_EDIFICIOS; i++) {

                archivo >> cantidad_material;
                nombre_material = obtener_nombre_material(i);

                Material material(nombre_material, cantidad_material);

                vector_materiales_requeridos[i] = material;
            }

            archivo >> edificios_maximos;

            Edificio edificio(nombre_edificio, vector_materiales_requeridos, edificios_maximos);

            agregar_edificio(edificio);
        }
    };
    archivo.close();
    return 1;
}

void Ciudad::agregar_edificio(Edificio edificio) {

    int cantidad_edificios = obtener_cantidad_edificios();
    Edificio* vector_edificios = obtener_vector_edificios();

    Edificio* nuevo_vector_edificios = new Edificio [cantidad_edificios + 1];

    for (int i = 0; i < cantidad_edificios; i++) {
        nuevo_vector_edificios[i] = vector_edificios[i];
    }

    nuevo_vector_edificios[cantidad_edificios] = edificio;

    if (cantidad_edificios != 0) {
        delete[] vector_edificios;
    }

    vector_edificios = nuevo_vector_edificios;
    cantidad_edificios++;
}