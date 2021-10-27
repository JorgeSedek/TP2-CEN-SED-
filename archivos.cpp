#include <iostream>
#include <fstream>
#include "archivos.h"

using namespace std;

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

bool cargar_ubicaciones(Ubicacion* &vector_ubicaciones, int &edificios_construidos) {
    
    ifstream archivo(PATH_UBICACIONES);
    string nombre_edificio;
    string fila;
    string columna;

    if (!archivo.is_open()) {
        cout << endl;
        cout << "ERROR: No se encuentra el archivo de ubicaciones." << endl;
        return 0;
    }
    else {

        while (archivo >> nombre_edificio) {
            archivo >> fila;
            archivo >> columna;

            Ubicacion ubicacion(nombre_edificio, fila, columna);

            agregar_ubicacion(vector_ubicaciones, ubicacion, edificios_construidos);
        }
    };
    archivo.close();
    return 1;

}

void agregar_ubicacion(Ubicacion* &vector_ubicaciones, Ubicacion ubicacion, int &edificios_construidos) {

    Ubicacion* nuevo_vector_ubicaciones = new Ubicacion [edificios_construidos + 1];

    for (int i = 0; i < edificios_construidos; i++) {
        nuevo_vector_ubicaciones[i] = vector_ubicaciones[i];
    }

    nuevo_vector_ubicaciones[edificios_construidos] = ubicacion;

    if (edificios_construidos != 0) {
        delete[] vector_ubicaciones;
    }

    vector_ubicaciones = nuevo_vector_ubicaciones;
    edificios_construidos++;
}

bool cargar_mapa(Mapa &mapa) {

    ifstream archivo(PATH_MAPA);
    int filas;
    int columnas;
    string tipo_casillero;

    if (!archivo.is_open()) {
        cout << endl;
        cout << "ERROR: No se encuentra el archivo de mapa." << endl;
        return 0;
    }
    else {

        archivo >> filas;
        archivo >> columnas;

        Mapa nuevo_mapa(filas, columnas);
        
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                
                archivo >> tipo_casillero;
                Casillero* casillero = crear_casillero(i, j, tipo_casillero);
                nuevo_mapa.cargar_casillero(i, j, casillero);
            }
        }

        mapa = nuevo_mapa;
    };
    archivo.close();
    return 1;
}