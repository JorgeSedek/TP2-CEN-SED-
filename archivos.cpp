#include <iostream>
#include <fstream>
#include "archivos.h"

using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_MATERIALES = "materiales.txt";

bool cargar_materiales(Material* &vector_materiales, int &tipos_de_materiales) {

    ifstream archivo(PATH_MATERIALES);
    string nombre_material;
    int cantidad_material;

    if (!archivo.is_open()) {
        cout << endl;
        cout << "ERROR: No se encuentra el archivo de materiales." << endl;
        return 0;
    }
    else {

        while (archivo >> nombre_material) {
            archivo >> cantidad_material;

            Material material(nombre_material, cantidad_material);

            agregar_material(vector_materiales, material, tipos_de_materiales);

        }
    };
    archivo.close();
    return 1;
}

void agregar_material(Material* &vector_materiales, Material material, int &tipos_de_materiales) {

    Material* nuevo_vector_materiales = new Material [tipos_de_materiales + 1];

    for (int i = 0; i < tipos_de_materiales; i++) {
        nuevo_vector_materiales[i] = vector_materiales[i];
    }

    nuevo_vector_materiales[tipos_de_materiales] = material;

    if (tipos_de_materiales != 0) {
        delete[] vector_materiales;
    }

    vector_materiales = nuevo_vector_materiales;
    tipos_de_materiales++;
}

bool cargar_edificios(Edificio* &vector_edificios, int &cantidad_edificios) {

    ifstream archivo(PATH_EDIFICIOS);
    string nombre_edificio;
    int limite_construccion;

    string nombre_material;
    int cantidad_material;

    if (!archivo.is_open()) {
        cout << endl;
        cout << "ERROR: No se encuentra el archivo de edificios." << endl;
        return 0;
    }
    else {
        while (archivo >> nombre_edificio) {
            
            archivo >> cantidad_material;
            nombre_material = obtener_nombre_material(PIEDRA);
            Material piedra(nombre_material, cantidad_material);

            archivo >> cantidad_material;
            nombre_material = obtener_nombre_material(MADERA);
            Material madera(nombre_material, cantidad_material);

            archivo >> cantidad_material;
            nombre_material = obtener_nombre_material(METAL);
            Material metal(nombre_material, cantidad_material);
        
            archivo >> limite_construccion;

            Edificio edificio(nombre_edificio, piedra, madera, metal, limite_construccion);

            agregar_edificio(vector_edificios, edificio, cantidad_edificios);
        }
    };
    archivo.close();
    return 1;
}

void agregar_edificio(Edificio* &vector_edificios, Edificio edificio, int &cantidad_edificios) {

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